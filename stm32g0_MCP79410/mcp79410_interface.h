/*
 * mcp79410_interface.h
 * Plik naglówkowy biblioteki
 * Obsluga zegarka Microchip MCP79410
 *
 * - interface do obslugi I2C dla MCP79410
 *  
 *  Pliki	:mcp79410.h, mcp79410.c
 */

#include <stdint.h>
#include "mcp79410.h"


#ifndef MCP79410_INTERFACE_H_
#define MCP79410_INTERFACE_H_


typedef  struct {
/*deklaracja wskaznikow na funkcje*/
void (*WriteRegisterRTCC)(uint8_t registerAdress, uint8_t data) ;
void (*WriteRegisterEEPROM)(uint8_t registerAdress, uint8_t data);
uint8_t (*ReadRegisterRTCC)(uint8_t registerAdress);
void (*InitRTCC)(void);
uint8_t (*getTime_YEAR)(void);
uint8_t (*getTime_MONTH)(void);
uint8_t (*getTime_DAY)(void);
uint8_t (*getTime_HOUR)(void);
uint8_t (*getTime_MIN)(void);
uint8_t (*getTime_SEC)(void);

} mcp79410_interface_t ;

extern const mcp79410_interface_t mcp79410 ;

#endif /*MCP79410_INTERFACE_H*/