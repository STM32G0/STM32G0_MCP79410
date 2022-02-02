/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************

File    :API_cap_1296.c
Autor : strefapic.blogspot.com
MCU: STM32G071KBT6

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stm32g071xx.h>
#include "I2C_cap1296_driver.h"
#include "API_cap1296.h"

/*funkcja inicjalizujaca interfejs*/
i2c_driver_interface_t i2c_driver_interface_Init(void){

i2c_driver_interface_t i2c_driver_interface; //powolanie nowej zmiennej o typie struktury i2c_driver_interface_t
/*przypisanie funkcji do pol struktury*/
i2c_driver_interface.read = I2C2_ReadRegister_CAP1296;
i2c_driver_interface.write = I2C2_WriteRegister_CAP1296;

return i2c_driver_interface;
}