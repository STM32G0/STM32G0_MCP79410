/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************

File    : I2C_cap1296_driver.h
Autor : strefapic.blogspot.com
MCU: STM32G071KBT6

*/


#ifndef I2C_CAP1296_DRIVER_H
#define I2C_CAP1296_DRIVER_H

/*driver*/
uint8_t I2C2_ReadRegister_CAP1296(uint8_t registerAdress); 
void I2C1_WriteRegister_MCP79410(uint8_t registerAdress, uint8_t data);


#endif /*CLOCK_MANAGER_H*/