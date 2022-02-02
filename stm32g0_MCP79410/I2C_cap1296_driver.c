/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************

File    : I2C_cap1296_driver.c
Autor : strefapic.blogspot.com
MCU: STM32G071KBT6

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stm32g071xx.h>
#include "I2C_cap1296_driver.h"
#include "cap1296.h"
#include "mcp79410.h"





uint8_t I2C2_ReadRegister_CAP1296(uint8_t registerAdress){

uint8_t data ;
uint8_t slaveAdress = CAP1296_ADDR;
while(I2C2->ISR & I2C_ISR_BUSY); //wait for I2C not busy

I2C2->CR2 &= ~I2C_CR2_NBYTES ; //clear NBYTES
I2C2->CR2 |= 1 << I2C_CR2_NBYTES_Pos; //set NBYTES = 1

I2C2->CR2 &= ~I2C_CR2_AUTOEND; //set AUTOEND = 0

I2C2->CR2 &= ~I2C_CR2_SADD; //clear SADD
I2C2->CR2 |= ((uint32_t)(slaveAdress) << I2C_CR2_SADD_Pos); //set SADD = slaveAdress
I2C2->CR2 &= ~I2C_CR2_RD_WRN; // Master requests a write transfer RD_WRN = 0

I2C2->CR2 |=I2C_CR2_START ; //set START = 1
while(!(I2C2->ISR & I2C_ISR_TXIS)); //wait for data to be transmitted TXIS = 1
I2C2->TXDR = (uint32_t)registerAdress ; //write to buf TXDR , registerAdress
while(!(I2C2->ISR & I2C_ISR_TC)); //wait for transfer complete TC = 1
/*RESTART*/
I2C2->CR2 |= I2C_CR2_AUTOEND; //set AUTOEND = 1
I2C2->CR2 |= I2C_CR2_RD_WRN; // Master requests a read transfer RD_WRN = 1
I2C2->CR2 |=I2C_CR2_START ; //set START = 1
while(!(I2C2->ISR & I2C_ISR_RXNE)); //wait for data to be received RXNE = 1
data = I2C2->RXDR ; //read receive bufer
while(!(I2C2->ISR & I2C_ISR_STOPF)); //wait for STOP complete STOPF = 1

#ifdef debug 
printf("data %d!\n", data);
#endif

return data ; 

}


void I2C1_WriteRegister_MCP79410(uint8_t registerAdress, uint8_t data){

uint8_t slaveAdress = ADDR_RTCC_WRITE;

while(I2C1->ISR & I2C_ISR_BUSY); //wait for I2C not busy

I2C1->CR2 &= ~I2C_CR2_NBYTES ; //clear NBYTES
I2C1->CR2 |= 2 << I2C_CR2_NBYTES_Pos; //set NBYTES = 2

I2C1->CR2 |= I2C_CR2_AUTOEND; //set AUTOEND = 1

I2C1->CR2 &= ~I2C_CR2_SADD; //clear SADD
I2C1->CR2 |= ((uint32_t)(slaveAdress) << I2C_CR2_SADD_Pos); //set SADD = slaveAdress

I2C1->CR2 &= ~I2C_CR2_RD_WRN; // Master requests a write transfer RD_WRN = 0

I2C1->CR2 |=I2C_CR2_START ; //set START = 1
while(!(I2C1->ISR & I2C_ISR_TXIS)); //wait for data to be transmitted TXIS = 1

I2C1->TXDR = (uint32_t)registerAdress ; //write to buf TXDR , registerAdress
while(!(I2C1->ISR & I2C_ISR_TXIS)); //wait for data to be transmitted TXIS = 1

I2C1->TXDR = (uint32_t)data ; //write to buf TXDR , registerAdress

while(!(I2C1->ISR & I2C_ISR_STOPF)); //wait for STOP complete STOPF = 1


}
