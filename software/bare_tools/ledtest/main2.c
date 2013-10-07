#define EDB9315A    1
#define EP93XX_PLATFORM_TYPE  EDB9315A
#define PHYSICAL_EQUAL_VIRTUAL
#include <hwdefs.h>

#define LOOP    14745600

#define ULONG unsigned int

static void delay()
{
    volatile int i;
    for (i  = 0; i < LOOP/128; i++);
}

int main2()
{
    *UART1_DR = '>';
    while (!(*UART1_FR & FR_TXFE));

    // Setting GrLED and RdLED
    *GPIO_PEDDR |= 0x2;

    for (;;) {
        *GPIO_PEDR |= GPIOE_GLED;
	delay();
	*GPIO_PEDR &= ~GPIOE_GLED;
	delay();
        *GPIO_PEDR |= GPIOE_RLED;
	delay();
        *GPIO_PEDR &= ~GPIOE_RLED;
	delay();
    }

    return 0;
}
