#include "stm32f4xx.h"


#define GPIOAEN     (1U<<0)
#define GPIOCEN     (1U<<2)

#define PIN5        (1U<<5)
#define PIN13       (1U<<13)

#define LED_PIN     PIN5
#define BTN_PIN     PIN13


int main(void)
{

   //enable clock access to GPIO A and C
   RCC->AHB1ENR |= GPIOAEN;
   RCC->AHB1ENR |= GPIOCEN;

   //set GPIO A as output pin
   GPIOA->MODER |= (1U<<10);
   GPIOA->MODER &=~ (1U<<11);

   //set GPIO C as input pin
   GPIOC->MODER |= (1U<<26);
   GPIOC->MODER |= (1U<<27);

   while (1)
   {
	   //check if BTN is pressed
       if (GPIOC->IDR & BTN_PIN)
       {

         //turn on LED
	   GPIOA->BSRR = LED_PIN;
	    }
       else {

    	 //turn off LED
       GPIOA->BSRR = (1U<<21) ;
       }
   }


}
