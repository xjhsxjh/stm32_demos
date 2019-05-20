#include "stm32f10x.h"

/*------------------------------------------------------------
                           Ö÷º¯Êý
------------------------------------------------------------*/

//Quick hack, approximately 1ms delay
void ms_delay(int ms)
{
   while (ms-- > 0) {
      volatile int x=5971;
      while (x-- > 0)
         __asm("nop");
   }
}

int main() {
    int count = 0;
    /* RCC reset & clock control register */
    // 1. afio, alternative function i/o clock enable
    RCC->APB2ENR |= 0x00000001;

    // 2. afio_mapr configure. (io multi-map & debug configure)
    // just enable SWJ (serial wired jtag), which suppport SWD or JTAG.
    // other pins, don't do remap.
    AFIO->MAPR = 0x0 | 0x04000000;


    // 3. ioport B clock enable
    RCC->APB2ENR |= 0x0000000c;

    // 4. init GPIOB related registers
    // configure all mode bit as output mode, max speed 50MHz.
    GPIOB->CRH = 0x33333333;
    GPIOB->CRL = 0x33333333;

    // 5. led blinky
    do {
        ms_delay(500);
        /* GPIOB all output data 0 */
        GPIOB->ODR = 0;

        ms_delay(500);
        /* GPIOB all output data 1 */
        GPIOB->ODR = 0xffffffff;
    } while (count++ < 10);

    GPIOB->ODR = 0xffffffff;

    count = 0;
    while (count++ < 30) {
        ms_delay(500);
    }

    return 0;
}
