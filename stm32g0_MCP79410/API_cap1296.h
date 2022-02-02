/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************

File    : API_cap1296.h
Autor : strefapic.blogspot.com
MCU: STM32G071KBT6

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stm32g071xx.h>
#include "cap1296.h"
#include "system_manager.h"

#ifndef API_CAP1296_H
#define API_CAP1296_H

//wskaznik do funkcji drivera I2C CAP1296
typedef void (*write_t)(uint8_t registerAdress, uint8_t data);
typedef uint8_t (*read_t)(uint8_t registerAdress);

typedef struct 
{
    read_t read ;
    write_t write;
        
} i2c_driver_interface_t;

i2c_driver_interface_t i2c_driver_interface_Init(void);


#endif /*API_CAP1296_H*/

