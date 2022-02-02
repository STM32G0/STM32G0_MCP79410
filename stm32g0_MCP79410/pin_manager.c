/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************

File    : pin_manager.c
Autor : strefapic.blogspot.com
MCU: STM32G071KBT6

*/

#include <stm32g071xx.h>
#include "pin_manager.h"

void PIN_MANAGER_Initialize(void){

/********** PA9 and PB9 set for I2C2*****************/
/*set Alternate fuction mode (0b10)*/
/*for PA9*/
GPIOA->MODER |= GPIO_MODER_MODE9_1 ; 
GPIOA->MODER &= ~(GPIO_MODER_MODE9_0); 
/*for PB9*/
GPIOB->MODER |= GPIO_MODER_MODE9_1 ; 
GPIOB->MODER &= ~(GPIO_MODER_MODE9_0); 
/*set Open Drain*/
GPIOA->OTYPER |= GPIO_OTYPER_OT9 ;
GPIOB->OTYPER |= GPIO_OTYPER_OT9 ;
/*set Pull-Up (0b01)*/
/*for PA9*/
GPIOA->PUPDR |= GPIO_PUPDR_PUPD9_0 ;
GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD9_1);
/*for PB9*/
GPIOB->PUPDR |= GPIO_PUPDR_PUPD9_0 ;
GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPD9_1);
/*set low speed (0b01)*/
/*for PA9*/
GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED9_0 ;
GPIOA->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED9_1);
/*for PB9*/
GPIOB->OSPEEDR |= GPIO_OSPEEDR_OSPEED9_0 ;
GPIOB->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED9_1);
/*set for I2C (0b0110)*/
/*for PA9*/
GPIOA->AFR[1] &= ~(GPIO_AFRH_AFSEL9) ; // clear
/*for PB9*/
GPIOB->AFR[1] &= ~(GPIO_AFRH_AFSEL9) ; // clear
/*for PA9*/
GPIOA->AFR[1] |= (GPIO_AFRH_AFSEL9_1 | GPIO_AFRH_AFSEL9_2) ; //set
/*for PB9*/
GPIOB->AFR[1] |= (GPIO_AFRH_AFSEL9_1 | GPIO_AFRH_AFSEL9_2) ; //set

/********** PA8 set Out for LED **********************/
GPIOA->MODER &= ~GPIO_MODER_MODE8_1 ;  //MODE8 -> 0b01  LED

/********** PB1 set for EXTI ************/
/*set Input (0b00)*/
//GPIOB->MODER &= ~(GPIO_MODER_MODE1_0 | GPIO_MODER_MODE1_1); 
/*set low speed (0b01)*/
//GPIOB->OSPEEDR |= GPIO_OSPEEDR_OSPEED1_0 ;
//GPIOB->OSPEEDR &= ~GPIO_OSPEEDR_OSPEED1_1 ;
/*set Pull-Up (0b01)*/
//GPIOB->PUPDR |= GPIO_PUPDR_PUPD1_0 ;
//GPIOB->PUPDR &= ~GPIO_PUPDR_PUPD1_1;
/*set EXTI for PB1*/
//EXTI->EXTICR[0] |= EXTI_EXTICR1_EXTI1_0 ;
/*set EXTI Falling triger for PB1*/
//EXTI->FTSR1 |= EXTI_FTSR1_FT1 ;
/*set EXTI Interrupt no-masked for PB1*/
//EXTI->IMR1 |= EXTI_IMR1_IM1 ;
}