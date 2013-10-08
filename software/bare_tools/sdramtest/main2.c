#define EDB9315A    1
#define EP93XX_PLATFORM_TYPE  EDB9315A  
#define PHYSICAL_EQUAL_VIRTUAL
#include <hwdefs.h>

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdarg.h>

#define LOOP    100000

#define ULONG  unsigned int
#define USHORT unsigned short
#define DWORD  unsigned int

#ifdef __GNUC__
#define TCODE
#define __arm
#else
/* for IAR C */
#define TCODE  __thumb
#pragma pack(1)
#endif

__arm static void set_clock();

TCODE static int strlen(const char* p)
{
    int len = 0;
    while (*p++ != 0)
	len++;
    return len;
}

//Embedded putchar
TCODE static void uputchar(int ch) 
{
    if (ch == '\n') {
        uputchar('\r');
    }
    //Send 'CODE RECIEVED'
    *UART1_DR = ch;
    while (!(*UART1_FR & FR_TXFE));
}


TCODE static void uprintf(char* buffer)
{
  /*
    uputchar('.');
    char buffer[100];
    va_list arg;
    va_start(arg, fmt);
    //vsnprintf(buffer, 511, fmt, arg);
    vsnprintf(buffer, 99, fmt, arg);
    va_end(arg);
  */
    int i;
    int len = strlen(buffer);
    for (i = 0; i < len; i++) {
      uputchar( *(((char*)buffer) + i));
    }
}

TCODE static void updigit(int val)
{
  if (val > 9)
    uputchar('A' + val - 10);
  else
    uputchar('0' + val);
}

TCODE static void upbyte(int val)
{
    updigit((val >> 4) & 0xF);
    updigit(val & 0xF);
}

TCODE static void upval(int val)
{
    upbyte(val >> 24);
    upbyte(val >> 16);
    upbyte(val >> 8);
    upbyte(val);
}

#define SDRAM_WIDTH_32

#define REG_SDRAM_DEVCFG SDRAM_DEVCFG_CS0
#define SDPHYSICAL_ADDR_SDRAM_MAIN  (volatile ULONG *)(PHYSICAL_ADDR_SDRAM_MAIN)

TCODE static void do_check(int i)
{
      *(SDPHYSICAL_ADDR_SDRAM_MAIN + 0x00004000 / 4) = i;
      int j = *(SDPHYSICAL_ADDR_SDRAM_MAIN + 0x00004000 / 4) ;
      
      if (i != j) {
        uprintf("W:");
        upval(i);
        uprintf(" R:");
        upval(j);
        uprintf("\n");
      }
}

//#define SDRAM_DSIZE     0x0020000
#define SDRAM_DSIZE      ((64 * 1024 * 1024) / 4)
      

TCODE static void wait_200us()
{
    volatile unsigned d;
    for (d = 0; d < 700; d++);
}

TCODE static void wait_22us()
{
    volatile unsigned d;
    for (d = 0; d < 80; d++);
}


TCODE static void do_work()
{
    volatile unsigned d;
    unsigned i;
    unsigned j, p;
    /*uprintf("DRAM TEST\n");*/

    uputchar('A');
    /*for (;;) {
      upval(1589+5465);
      uprintf("Hello, world!\n");
    }*/
    
    *CSC_CLKSET1 = 0;
   
    // Initialize the SDRAM Configuration
#ifdef SDRAM_WIDTH_32       
/*    *REG_SDRAM_DEVCFG  = DEVCFG_BANKCOUNT |  DEVCFG_SROMLL |  
          DEVCFG_CASLAT_3 | DEVCFG_RASTOCAS_3 ;
    */
      *REG_SDRAM_DEVCFG  = DEVCFG_BANKCOUNT |  DEVCFG_SROMLL |  
          DEVCFG_CASLAT_2 | DEVCFG_RASTOCAS_2 ;
#else    
    *REG_SDRAM_DEVCFG  = DEVCFG_BANKCOUNT | DEVCFG_SROMLL |  
          DEVCFG_CASLAT_3 | DEVCFG_RASTOCAS_3 | DEVCFG_EXTBUSWIDTH;
#endif      
    
    // Wait 200 us
    //for (d = 0; d < 700; d++);
    wait_200us();
  
    //Set the Initialize and MRS bits (issue continuous NOP commands (INIT & MRS set))
    *SDRAM_GLOBALCFG = GLOBALCFG_INIT | GLOBALCFG_MRS | GLOBALCFG_CKE;
    // Wait 200 us
    //for (d = 0; d < 700; d++);
    wait_200us();

    //Clear the MRS bit to issue a precharge all.
    *SDRAM_GLOBALCFG = GLOBALCFG_INIT | GLOBALCFG_CKE;
    // Wait 200 us
    //for (d = 0; d < 700; d++);
    wait_200us();
    
#ifdef SDRAM_WIDTH_32    
    *(SDPHYSICAL_ADDR_SDRAM_MAIN + 0x00000000 / 4) = 0xFFFFFFFF;
    *(SDPHYSICAL_ADDR_SDRAM_MAIN + 0x00400000 / 4) = 0xFFFFFFFF;
    *(SDPHYSICAL_ADDR_SDRAM_MAIN + 0x00800000 / 4) = 0xFFFFFFFF;    
    *(SDPHYSICAL_ADDR_SDRAM_MAIN + 0x00C00000 / 4) = 0xFFFFFFFF;
#else
    *(SDPHYSICAL_ADDR_SDRAM_MAIN + 0x00000000 / 4) = 0xFF;
    *(SDPHYSICAL_ADDR_SDRAM_MAIN + 0x00200000 / 4) = 0xFF;
    *(SDPHYSICAL_ADDR_SDRAM_MAIN + 0x00400000 / 4) = 0xFF;    
    *(SDPHYSICAL_ADDR_SDRAM_MAIN + 0x00600000 / 4) = 0xFF;
#endif    
    
    // Temporarily set the refresh timer to 0x10.  Make it really low so that
    // auto refresh cycles are generated. is refreshed.

    *SDRAM_REFRESH = 0x10;
    //for (d = 0; d < 80; d++);
    wait_22us();
    
    *SDRAM_REFRESH = 0x204;
    //for (d = 0; d < 80; d++);    
    wait_22us();

    //Select mode register update mode
    *SDRAM_GLOBALCFG = GLOBALCFG_MRS | GLOBALCFG_CKE;
#ifdef SDRAM_WIDTH_32      
    d = *(SDPHYSICAL_ADDR_SDRAM_MAIN + 0x00008800 / 4);
    d = *(SDPHYSICAL_ADDR_SDRAM_MAIN + 0x00408800 / 4);
    d = *(SDPHYSICAL_ADDR_SDRAM_MAIN + 0x00808800 / 4);
    d = *(SDPHYSICAL_ADDR_SDRAM_MAIN + 0x00C08800 / 4);     
/*   i = *(SDPHYSICAL_ADDR_SDRAM_MAIN + 0x0000C800 / 4);
    i = *(SDPHYSICAL_ADDR_SDRAM_MAIN + 0x0040C800 / 4);
    i = *(SDPHYSICAL_ADDR_SDRAM_MAIN + 0x0080C800 / 4);
    i = *(SDPHYSICAL_ADDR_SDRAM_MAIN + 0x00C0C800 / 4); 
*/
#else
    d = *(SDPHYSICAL_ADDR_SDRAM_MAIN + 0x00006600 / 4);
    d = *(SDPHYSICAL_ADDR_SDRAM_MAIN + 0x00206600 / 4);
    d = *(SDPHYSICAL_ADDR_SDRAM_MAIN + 0x00406600 / 4);
    d = *(SDPHYSICAL_ADDR_SDRAM_MAIN + 0x00606600 / 4); 
#endif 
    
    // Select mode register update mode
    *SDRAM_GLOBALCFG = GLOBALCFG_CKE;
    // Wait 200 us
    //for (d = 0; d < 700; d++);
    wait_200us();
    
    d = *(SDPHYSICAL_ADDR_SDRAM_MAIN + 0x00004000 / 4);
    
    /*
    for (i = 0; ;i++) {
        *(SDPHYSICAL_ADDR_SDRAM_MAIN + 0x00004000 / 4) = 0xFFFFFFFF;
        *(SDPHYSICAL_ADDR_SDRAM_MAIN + 0x00004000 / 4) = 0x00000000;        
    }
    */
    
    set_clock();
    //for (i = 0; i < 700; i++);
    wait_200us();
    
    
    for (i = 0 ; ; i++) {
      do_check(0xFFFFFFFF);
      do_check(0x00000000);
      do_check(0x12345678);
      do_check(0x55aa55aa);
      do_check(0x88888888);
      do_check(0xf0f0f0f0);
      do_check(0x0f0f0f0f);
      do_check(0x00ff00ff);
      do_check(0xff00ff00);
      do_check(0xffff0000);
      do_check(0x0000ffff);

      for (j = 0xf; j != 0xf0000000; j<<=1) {      
        do_check(j);
        do_check(~j);
      }
    
      for (j = 0x1; j != 0x80000000; j<<=1) {      
        do_check(j);
        do_check(~j);
      }
            
      for (j = 0x3; j != 0xC0000000; j<<=1) {      
        do_check(j);
        do_check(~j);
      }    
      
      uputchar('.');


      //Adress test 
      for (j = 0; j < SDRAM_DSIZE; j++) {
        *(SDPHYSICAL_ADDR_SDRAM_MAIN + j) = 0x00000000;        
      }
      for (j = 0; j < SDRAM_DSIZE; j++) {
        int l =  *(SDPHYSICAL_ADDR_SDRAM_MAIN + j);      
        int k =  0x00000000;
          if (l != k) {
            uprintf("A:");
            upval(j);            
            uprintf(" W:");
            upval(k);
            uprintf(" R:");
            upval(l);      
            uprintf("\n");        
          }
      }
      
      uputchar(';');

      
      //Adress test 
      for (j = 0; j < SDRAM_DSIZE; j++) {
        *(SDPHYSICAL_ADDR_SDRAM_MAIN + j) = 0xFFFFFFFF ^ j ^ ( (j <<15 )+ (j <<10 ) + (j <<2 ) + j);        
      }
      for (j = 0; j < SDRAM_DSIZE; j++) {
        int l =  *(SDPHYSICAL_ADDR_SDRAM_MAIN + j);      
        int k =  ( 0xFFFFFFFF ^ j ^ ((j <<15 ) + (j <<10 ) + (j <<2 ) + j));
          if (l != k) {
            uprintf("A:");
            upval(j);            
            uprintf(" W:");
            upval(k);
            uprintf(" R:");
            upval(l);      
            uprintf("\n");        
          }
      }

      uputchar(':');
      
    
    
    //Offset Test
#define START_OFFSET    0    
#define END_OFFSET      ((32 * 1024 * 1024 ) / 4)
#define SIZE            1024*1024
    

      //Adress test 
      for (j = START_OFFSET; j < START_OFFSET + SIZE; j++) {
        *(SDPHYSICAL_ADDR_SDRAM_MAIN + j) = 0;
      }
      for (j = END_OFFSET; j < END_OFFSET + SIZE; j++) {    
        *(SDPHYSICAL_ADDR_SDRAM_MAIN + j) = 0xFFFFFFFF ^ j ^ ( (j <<15 )+ (j <<10 ) + (j <<2 ) + j);        
      }    
    
      for (j = START_OFFSET; j < START_OFFSET + SIZE; j++) {
        int l =  *(SDPHYSICAL_ADDR_SDRAM_MAIN + j);      
        int k =  0;
          if (l != k) {
            uprintf("A:");
            upval(j);            
            uprintf(" W:");
            upval(k);
            uprintf(" R:");
            upval(l);      
            uprintf("\n");        
          }
      }      
    
       uputchar('-');
      
      
      //Address Walker
      for (p = 0; p < 24/*26*/; p++) {
        unsigned int uad = 1 << p;
        *(SDPHYSICAL_ADDR_SDRAM_MAIN) = 0;
        *(SDPHYSICAL_ADDR_SDRAM_MAIN + uad) = 0xFFFFFFFF;
        int oo = *(SDPHYSICAL_ADDR_SDRAM_MAIN);
        
        *(SDPHYSICAL_ADDR_SDRAM_MAIN) = 0xFFFFFFFF;        
        *(SDPHYSICAL_ADDR_SDRAM_MAIN + uad) = 0;     
        unsigned op = *(SDPHYSICAL_ADDR_SDRAM_MAIN);
        
        if ((oo != 0) || (op != 0xFFFFFFFF)) {
            uprintf("DA:");
            upval(p + 2);
            uprintf(" A:");
            upval(uad);            
            uprintf(" 0:");
            upval(oo);
            uprintf(" 1:");
            upval(op);      
            uprintf("\n");        
        }        
        
      }
        
      
       uputchar('+');
      
      
    }
    
}

////////////////////////////////////////////////////////////////////////////////
// Flash testing
////////////////////////////////////////////////////////////////////////////////

//
// Definitions for Flash erasing.
//
#define     FLASH_BLOCK_SIZE            0x20000
#define     FLASH_BLOCK_MASK            ~(FLASH_BLOCK_SIZE - 1)
#define     FLASH_BUFFER_SIZE           32

//
//Flash cmd and status
//
#define     FLASH_READ_MODE             0x00FF
#define     FLASH_BLOCK_ERASE           0x0020
#define     FLASH_CLEAR_STATUS          0x0050
#define     FLASH_BLOCK_ERASE_RESUME    0x00d0
#define     FLASH_BLOCK_PROGRAM_RESUME  0x00d0
#define     FLASH_WRITE_TO_BUFFER       0x00E8
#define     FLASH_READ_STATUS           0x0070
#define     FLASH_LOCK_BIT              0x0060
#define     FLASH_LOCK_SET              0x0001
#define     FLASH_LOCK_CLEAR            0x00d0

#define	    FLASH_READ_ID_CODES         0x0090
#define     FLASH_READ_QUERY            0x0098

#define     STATUS_WRITE_READY          0x0080
#define     EXT_STATUS_WBUFFER_READY    0x0080

/*
static DWORD    			gdwStartAddr          = 0;
static DWORD    			gdwLength             = 0;
static volatile USHORT * 	gpusCurAddr    		  = 0;
static BOOL     			gbFlashEraseComplete  = FALSE;
static BOOL     			gbUnlocked            = TRUE;

static DWORD				gdwFlashSize			;

static DWORD                gdwManufactureId		=0;
struct EraseBlockInfo     	sBlockInfo[4];
static DWORD				gdwNumEraseRegion		=0;
static DWORD				gdwCurEraseRegion		=0;
static DWORD				gdwCurEraseBlock		=0;
static DWORD				gdwCurEraseBlockMask	=0;
static DWORD				gdwFlashBufferSize		=64;
*/
TCODE static void TestFlash()
{
        volatile USHORT *gpusCurAddr = 0;  
        DWORD gdwManufactureId = 0;
        DWORD gdwNumEraseRegion = 0;
        DWORD gdwFlashSize;
  
  
	DWORD iIdx = 0;
	DWORD dwToalSize=0;
	int i;
	
	gpusCurAddr = (unsigned short*)PHYSICAL_ADDR_FLASH;
	// Query 16 bitwidth id.
	*gpusCurAddr 		= FLASH_READ_ID_CODES;
	gdwManufactureId 	= *gpusCurAddr;

        uprintf("FM:");
        upval(gdwManufactureId);  
        uprintf("\n");
        
	// Query 16 bitwidth flash.
	*gpusCurAddr = FLASH_READ_QUERY;

	gdwFlashSize = 1 << (*(gpusCurAddr + 0x27) & 0xFF);

        uprintf("FS:");
        upval(gdwFlashSize);  
        uprintf("\n");        

	//gdwNumEraseRegion = *(gpusCurAddr + 0x2c) & 0xFFFF;
	gdwNumEraseRegion = *(gpusCurAddr + 0x2c) & 0x00FF; //Set bs to MAX 256

	for(iIdx = 0; iIdx < gdwNumEraseRegion; iIdx++)
	{
		DWORD blocks = (*(gpusCurAddr + 0x2d + (iIdx<<2)) & 0xFFFF) + 1;
                
                DWORD block_size =
			(((*(gpusCurAddr + 0x30 + (iIdx<<2)) & 0xFFFF) << 8) +
			(*(gpusCurAddr + 0x2f + (iIdx<<2)) & 0xFFFF)) << 8;

		dwToalSize += block_size * blocks;

                uprintf("bs ");
                upval(block_size);  
                uprintf(" -- ");
                upval(blocks); 
                uprintf("\n");
	}
        
        uprintf("T ");
        upval(dwToalSize);
        uprintf("\n");
        
        for (i = 0; i < 0x40; i++) {
          DWORD val = *(gpusCurAddr + i);
          uprintf("RID: ");
          upval(i);
          uprintf(" v: ");          
          upval(val);          
          uprintf("\n");
        }
        
}
        




#define FCLOCK 200

#if (FCLOCK == 240)
#define     FDIV                    1
#define     HDIV                    2
#define     PDIV                    1
#define     PRE_CLKSET1_VALUE       0x0080a4b7
#define     PLL1_CLOCK              399974400
#endif // (FCLOCK == 200)


#if (FCLOCK == 220)
#define     FDIV                    1
#define     HDIV                    2
#define     PDIV                    1
#define     PRE_CLKSET1_VALUE       0x0080a437
#define     PLL1_CLOCK              399974400
#endif // (FCLOCK == 200)


#if (FCLOCK == 200)
#define     FDIV                    1
#define     HDIV                    2
#define     PDIV                    1
#define     PRE_CLKSET1_VALUE       0x0080a3d7
#define     PLL1_CLOCK              399974400
#endif // (FCLOCK == 200)



//**********************************************************************
//
// PLL1 Clock =368  Mhz
// FClock    = 184  Mhz
// HCLock    = 73   Mhz
// PClock    = 46   Mhz
//
//
//**********************************************************************
#if (FCLOCK == 184)
#define     FDIV                    1
#define     HDIV                    2
#define     PDIV                    1
#define     PRE_CLKSET1_VALUE       0x0080ab15
#define     PLL1_CLOCK              368640000
#endif // (FCLOCK == 184)              
#if (FCLOCK == 166)
#define     FDIV                    1
#define     HDIV                    4
#define     PDIV                    1
//#define     PRE_CLKSET1_VALUE       0x0080fa5a
//#define     PLL1_CLOCK              332049054
#define     PRE_CLKSET1_VALUE        0x00809907
#define     PLL1_CLOCK              331776000
#endif // (FCLOCK == 166)              



#define     REAL_HDIV           ((1  * (HDIV == 0))  + \
                                 (2  * (HDIV == 1))  + \
                                 (4  * (HDIV == 2))  + \
                                 (5  * (HDIV == 3))  + \
                                 (6  * (HDIV == 4))  + \
                                 (8  * (HDIV == 5))  + \
                                 (16 * (HDIV == 6))  + \
                                 (32 * (HDIV == 7)))

#define     REAL_FCLOCK         (PLL1_CLOCK / (1<<FDIV))
#define     REAL_HCLOCK         (PLL1_CLOCK / REAL_HDIV)
#define     REAL_PCLOCK         (REAL_HCLOCK/ (1<<PDIV))
#define     CLKSET1_VALUE       (PRE_CLKSET1_VALUE |                \
                                (PDIV <<CLKSET1_PCLK_DIV_SHIFT)|    \
                                (HDIV <<CLKSET1_HCLK_DIV_SHIFT)|    \
                                (FDIV <<CLKSET1_FCLK_DIV_SHIFT))

#define     CLKSET2_VALUE           0x300dc317
#define     PLL2_CLOCK              192000000


//****************************************************************************
// SDRAM refresh calculation
//****************************************************************************
// This is the time in uS between refreshes.
//
//
//
#define     SDRAM_REFRESH_TIME          32
#define     SDRAM_REFRESH_VALUE         ((REAL_HCLOCK / 1000000) * SDRAM_REFRESH_TIME)
#define     SDRAM_14MHZ_REFRESH_VALUE   ((EX_CLOCK / 1000000) * SDRAM_REFRESH_TIME)

__arm void set_clock()
{

    
    *WATCHDOG_WDCONTROL = WDCONTROL_DISABLE;

    //
    // Program the processor/bus clock rate.
    //
    *CSC_SYSLOCK = 0xAA;
    *CSC_CLKSET1 = CLKSET1_VALUE; 

    //
    // Flush the pipeline.
    //    
asm ("nop\n" 
     "nop\n"
     "nop\n"
     "nop\n"
     "nop\n"
     "nop\n"       
     "nop\n"           
       ); 
    
    //
    // Configure PLL2 in order to generate a solid 48Mhz clock for USB.
    //
    *CSC_SYSLOCK = 0xAA;
    *CSC_CLKSET2 = CLKSET2_VALUE; 

    //
    // Enable all of the UARTS and the math coprocessor.
    //
    *CSC_SYSLOCK =  0xAA;
    
    //
    *SDRAM_REFRESH = SDRAM_REFRESH_VALUE;

    //
    // Program the power control register to use all dma channels.
    //
    //ulPwrcnt = *CSC_PWRCNT;
    *CSC_SYSLOCK = 0xAA;        
}

void main2()
{

    TestFlash();
    do_work();    
//    for (;;);
}
