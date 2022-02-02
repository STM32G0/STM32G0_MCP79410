/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************

File    : main.c
Autor   : strefapic.blogspot.com
MCU     : STM32G071KBT6

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stm32g071xx.h>
#include "system_manager.h"
#include "mcp79410_interface.h"

volatile uint8_t intFlag = 0;

int main(void) {

SystemInit();
SYSTEM_MANAGER_Initialize();

SysTick_Config(16000000 * 0.1); //ok 0.1 s
mcp79410.InitRTCC();
mcp79410.getTime_HOUR();

while(1){

if(intFlag){ //flaga aktywowana w przerwaniu SysTick
     
      intFlag = 0; //zeruj flage 
      //mcp79410.WriteRegisterRTCC(ADDR_CTRL, 0x80);
      mcp79410.ReadRegisterRTCC(ADDR_CTRL);
      GPIOA->ODR ^= GPIO_ODR_OD8 ; //LED - PA8 toggle          
     }
  }
}

/*Interrupt Handler for SysTick*/

void SysTick_Handler(void){
intFlag = 1;
}



/*
void EXTI0_1_IRQHandler(void){
intFlag = 1;
if(EXTI->FPR1 & EXTI_FPR1_FPIF1)
EXTI->FPR1 |= EXTI_FPR1_FPIF1; //clear pending
}
*/