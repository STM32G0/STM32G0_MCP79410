/*
 * mcp79410_interface.c
 * Plik naglówkowy biblioteki
 * Obsluga zegarka Microchip MCP79410
 *
 * - sterowanie: interface do obslugi I2C dla MCP79410
 *  
 *  Pliki	:mcp79410.h, mcp79410.c
 */

#include "mcp79410_interface.h"
#include "i2c_manager.h"
#include "mcp79410.h"

/*do wskaznikow przypisujemy funkcje*/
const mcp79410_interface_t mcp79410 = {
.WriteRegisterRTCC = i2c_rtcc_wr,
.WriteRegisterEEPROM = i2c_eeprom_wr,
.ReadRegisterRTCC = i2c_rtcc_rd,
.InitRTCC = i2c_rtcc_ini,
.getTime_YEAR = get_YEAR,
.getTime_MONTH = get_MONTH,
.getTime_DAY = get_DAY,
.getTime_HOUR = get_HOUR,
.getTime_MIN = get_MIN,
.getTime_SEC = get_SEC,

};