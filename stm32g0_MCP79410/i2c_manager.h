/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************

File    : i2c_manager.h
Autor : strefapic.blogspot.com
MCU: STM32G071KBT6

*/
#include "mcp79410_interface.h"

#ifndef I2C_MANAGER_H
#define  I2C_MANAGER_H


void I2C1_MANAGER_Initialize(void);
void I2C1_Write(uint8_t slaveAdress, uint8_t registerAdress, uint8_t data);
uint8_t I2C1_Read(uint8_t slaveAdress, uint8_t registerAdress);

typedef enum {
I2C_STATE_IDLE,
I2C_STATE_TRANSFER,
I2C_STATE_RECEIVED,
I2C_STATE_STOP,
} I2C_STATE;




#endif /*I2C_MANAGER_H*/