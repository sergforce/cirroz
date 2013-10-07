#define EDB9315A    1
#define EP93XX_PLATFORM_TYPE  EDB9315A
#define PHYSICAL_EQUAL_VIRTUAL
#include <hwdefs.h>

#define LOOP    100000

#define ULONG unsigned int


int main2()
{
    *UART1_DR = '>';
    while (!(*UART1_FR & FR_TXFE));

    return 0;
}
