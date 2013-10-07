#define EDB9315A    1
#define EP93XX_PLATFORM_TYPE  EDB9315A  
#define PHYSICAL_EQUAL_VIRTUAL
#include "hwdefs.h"

#define LOOP    100000

#define ULONG unsigned int



//#pragma segment="CODE" 
/*
int main3(int param)
{
  int j[20];


  for (int t = 0; t < 20; t++) {
      j[t] = 'A' + t;
  }
  
 
  int i = 0;
  int l = 0;
  
  for (;;) {
    for (i  = 0; i < LOOP; i++);
    *GPIO_PEDR |= GPIOE_GLED;
  
    for (i  = 0; i < LOOP; i++);
    *GPIO_PEDR &= ~GPIOE_GLED;


    for (i  = 0; i < LOOP / 10; i++);
    *GPIO_PEDR |= GPIOE_RLED;
  
    for (i  = 0; i < LOOP / 10; i++);
    *GPIO_PEDR &= ~GPIOE_RLED;
    
    if (l < 20) {
      *UART1_DR = j[l++];
    } else {
      l = 0;
    }

  }
  
  return 0;
}
*/

int main3(int param)
{
    int words; // = 2048 / 4;
    int bytes;
    int b[4];
    volatile ULONG* pMemBegin = (volatile ULONG*)0x80014000;
    
    int flash = 1;
    int i;
    
    (void)param; /* get rid of warning */

    //Flash RED led 
    for (i  = 0; i < LOOP / 10; i++);
    *GPIO_PEDR |= GPIOE_RLED;  
    for (i  = 0; i < LOOP / 10; i++);
    *GPIO_PEDR &= ~GPIOE_RLED;
    
    // Send '<' prompt to load boot code
    *UART1_DR = '<';
    while (!(*UART1_FR & FR_TXFE));
 
    for (words = 0; words < 2048 / 4; words++) {
      for (bytes = 0; bytes < 4; bytes++) {
        while ((*UART1_FR & FR_RXFE));
        b[bytes] = *UART1_DR;
      }

      if (flash) {      
        *GPIO_PEDR |= GPIOE_GLED; flash = 0;
      } else {
        *GPIO_PEDR &= ~GPIOE_GLED; flash = 1;
      }
      
      //ULONG word = (b[0] << 24) | (b[1] << 16) | (b[2] << 8) | b[3];
      ULONG word = (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
      *pMemBegin++ = word;
    }
    
    //Send 'CODE RECIEVED'
    *UART1_DR = '>';
    while (!(*UART1_FR & FR_TXFE));    

    pMemBegin = (volatile ULONG*)0x80014000;
      
    //Check signature
  //  if ((*pMemBegin == 'CRUS') || (*pMemBegin == 'SURC')) {
    if (1) {
      void (*p)() =  (void (*)())0x80014004;
      
      // TurnOff LED
      *GPIO_PEDR &= ~GPIOE_GLED;
      
      for (i  = 0; i < LOOP * 2; i++);
      
      (*p)();
      
      for (;;);
      
    } else {
      // Bad Code!!!
      for (;;) {
        for (i = 0; i < 4; i++) {
          *UART1_DR = *pMemBegin >> (i * 8);
          while (!(*UART1_FR & FR_TXFE));        
        }
      
        for (i  = 0; i < LOOP / 4; i++);
        *GPIO_PEDR |= GPIOE_GLED;
      
        for (i  = 0; i < LOOP / 4; i++);
        *GPIO_PEDR &= ~GPIOE_GLED;

        for (i  = 0; i < LOOP / 4; i++);
        *GPIO_PEDR |= GPIOE_RLED;
      
        for (i  = 0; i < LOOP / 4; i++);
        *GPIO_PEDR &= ~GPIOE_RLED;        
      }
    }
    
  
}

//Embedded aligned memcpy
static void amemcpy(void* dst, void* src, int count) 
{
    int* d = (int*)dst;
    int* s = (int*)src;
    int i;

    for (i = 0; i < (count>>2); i++) {
        *d++ = *s++;
    }
}


#define MCSPEED     14745600
#define UART_SPEED      9600
int main2()
{
    // Setting GrLED and RdLED
    *GPIO_PEDDR |= 0x2;
    // Turn off Green LED
    *GPIO_PEDR &= ~GPIOE_GLED;
  
    *UART1_CR = 0;
    // Set UART1 speed and mode
    short div = (MCSPEED / (32 * UART_SPEED)) - 1;
    *UART1_LCR_L = div & 0xFF;
    *UART1_LCR_M = div >> 8;    
    *UART1_LCR_H = LCR_H_DATABITS_8 | LCR_H_FIFO_ENABLE;
    *UART1_MCR = MCR_DTR | MCR_RTS;
    *UART1_CR = CR_UARTE;   
            
    // Remap UART loader
    amemcpy((char*)main3 + 0x800, (char*)main3, 0x400);


    // Call remaped UART bootloader    
    int (* x)(int) = (int (*)(int) )((char*)main3 + 0x800);
    (*x)(0);

    return 0;
}
