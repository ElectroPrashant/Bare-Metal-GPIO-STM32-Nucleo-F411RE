//where is the led connected
//port: A
//pin: 5

#define PERIPH_BASE          (0x40000000UL)
// 0x4002 0000 + 0x00002 0000   =   0x4002 0000
#define AHB1PERIPH_OFFSET    (0x000020000UL)
#define AHB1PERIPH_BASE     (PERIPH_BASE + AHB1PERIPH_OFFSET)
#define GPIOA_OFFSET         (0x0000UL)

#define GPIOA_BASE           (AHB1PERIPH_BASE + GPIOA_OFFSET)

//RCC= reset clock control
#define RCC_OFFSET           (0X3800UL)
#define RCC_BASE             (AHB1PERIPH_BASE + RCC_OFFSET)

//to use our the registers we have to typecast the address to volatile int pointer and then dereference the pointer

#define AHB1EN_R_OFFSET      (0x30UL)
#define RCC_AHB1EN_R         (*(volatile unsigned int *) (RCC_BASE + AHB1EN_R_OFFSET) )
#define GPIOAEN              (1U<<0)                             // means "shift 1 at position 0" ie. 0b  0000 0000 0000 0000 0000 0000 0000 0001  (32 bits)
                                                                 // ex. 1U<<4 means shift 1 at position 4 ie. 0b  0000 0000 0000 0000 0000 0000 0001 0000
#define MODE_R_OFFSET        (0x00UL)
#define GPIOA_MODE_R         (*(volatile unsigned int *) (GPIOA_BASE + MODE_R_OFFSET) )
#define OD_R_OFFSET          (0x14UL)
#define GPIOA_OD_R           (*(volatile unsigned int *) (GPIOA_BASE + OD_R_OFFSET))

#define PIN5                 (1U<<5)
#define LED_PIN               PIN5

// Pin 5 -> MODDER5[1:0] -> 10,11 Bits
// 01 -> GP OP Mode

/* (1U<<10) // set bit 10 to 1
 * &=~(1U<<11) // set bit 11 to 0
 */

int main (void)
{
	/* 1. Enable clock access to GPIOA */

	RCC_AHB1EN_R |= GPIOAEN ;                           //rcc ahb1en register -> let 0b  0000 0000 0000 0000 1000 1111 0000 0000 -> 0b  0000 0000 0000 0000 1000 1111 0000 0001
	                                                                                                                                //just bit 0 changed to 1
	/* 2. Set PA5 as OP pin
	 */
	GPIOA_MODE_R |= (1U<<10) ; // set bit 10 to 1
	GPIOA_MODE_R &=~(1U<<11); // set bit 11 to 0
    while(1)
    {
      //3. set PA5 high
   // GPIOA_OD_R |= LED_PIN;

    //3.5 Exp2- toggle PA5
    GPIOA_OD_R ^= LED_PIN;   //toggle operator ^
    for(int i=0; i<100000; i++) { }   // delay

    }

}
