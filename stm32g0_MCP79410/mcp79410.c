 /*
 * mcp79410.c
 *
 * Obsluga zegarka Microchip MCP79410
 *
 * - sterowanie: I2C
 *  
 *  Pliki	:mcp79410.h, mcp79410.c
 */
 #include <stdint.h>
 #include "mcp79410.h"
 #include "i2c_manager.h"

extern uint8_t err_flg  ;   // the error flag will be used in this file 
//..............................................................................
// The below function writes a data byte in the I2C RTCC
//..............................................................................

void i2c_rtcc_wr(uint8_t registerAdress, uint8_t data){ // writes a data byte to the I2C RTCC   
uint8_t slaveAdress = ADDR_RTCC_WRITE;
I2C1_Write(slaveAdress, registerAdress, data);
}
//..............................................................................
// The below function writes a data byte in the I2C RTCC
//..............................................................................

void i2c_eeprom_wr(uint8_t registerAdress, uint8_t data){ // writes a data byte to the I2C EEPROM   
uint8_t slaveAdress = ADDR_EEPROM_WRITE ;
I2C1_Write(slaveAdress, registerAdress, data);
}
//..............................................................................
// The below function reads a data byte from the I2C RTCC
//..............................................................................

uint8_t i2c_rtcc_rd(uint8_t registerAdress){ // read a data byte from the I2C RTCC   
uint8_t slaveAdress = ADDR_RTCC_WRITE;
return I2C1_Read(slaveAdress, registerAdress);
}
//..............................................................................
// The below function initializes the I2C RTCC
//..............................................................................

void i2c_rtcc_ini(void){             // initialization of the I2C RTCC: 
uint8_t day = 0;
i2c_rtcc_wr(ADDR_CTRL,0xC0);         // square wave on MFP, no alarms, MFP = 1Hz
/*enable VBAT*/
day = i2c_rtcc_rd(ADDR_DAY);
i2c_rtcc_wr(ADDR_DAY,day | VBATEN);  // enable the battery back-up
/*Set Time*/
i2c_rtcc_wr(ADDR_YEAR,0x22);         // initialize YEAR  register : (20)22           
i2c_rtcc_wr(ADDR_MNTH,0x01);         // initialize MONTH register : styczeñ  
i2c_rtcc_wr(ADDR_DATE,0x01);         // initialize DATE  register : date = 01  
i2c_rtcc_wr(ADDR_HOUR,0x00);         // initialize HOUR  register : hour = 00  
i2c_rtcc_wr(ADDR_MIN,0x00) ;         // initialize MIN   register : min  = 00  
i2c_rtcc_wr(ADDR_SEC,START_32KHZ);   // init SEC register and start the 32khz oscillator .
}   


/*****************************************************************************
                    Get time MCP79410 and convert BCD to DEC
 *****************************************************************************/
uint8_t get_YEAR(void) {
uint8_t yr = 0;   
yr  = i2c_rtcc_rd(ADDR_YEAR)  ;  /*read YEAR*/        
yr = (((yr >> 4) & 0x0F) * 10) + (yr & 0x0F); /*konwersja liczby BCD na dziesietna*/   
return yr;           
}
    
uint8_t get_MONTH(void) { 
uint8_t mon = 0;  
mon = i2c_rtcc_rd(ADDR_MNTH)  ;  /*read MONTH*/ 
mon = ((((mon&0x1F) >> 4) & 0x0F) * 10) + (mon & 0x0F); /*konwersja liczby BCD na dziesietna + maska dla leap year*/
return mon;
}

uint8_t get_DAY(void) {   
uint8_t day = 0;
day = i2c_rtcc_rd(ADDR_DATE)  ;  /*read DATE*/ 
day = ((((day&0x3F) >> 4) & 0x0F) * 10) + (day & 0x0F); /*konwersja liczby BCD na dziesietna*/
return day;
}

uint8_t get_HOUR(void) {
uint8_t hr = 0;       
hr  = i2c_rtcc_rd(ADDR_HOUR)  ;  /*read HOUR*/
hr = ((((hr&0x3F) >> 4) & 0x0F) * 10) + (hr & 0x0F); /*konwersja liczby BCD na dziesietna + maska dla 12 hours format*/
return  hr ;
}

uint8_t get_MIN(void) {   
uint8_t min = 0;   
min = i2c_rtcc_rd(ADDR_MIN)   ;  /*read MIN*/
min = (((min >> 4) & 0x0F) * 10) + (min & 0x0F); /*konwersja liczby BCD na dziesietna*/
return min;
} 

uint8_t get_SEC(void) { 
uint8_t sec = 0;   
sec = i2c_rtcc_rd(ADDR_SEC)   ;  /*read SEC*/
sec = ((((sec&0x7F) >> 4) & 0x0F) * 10) + (sec & 0x0F); /*konwersja liczby BCD na dziesietna + maska dla Start Oscilator*/
return sec;
}












/*
//..............................................................................
// The below function initializes the time/date variables, only if the oscillator is not yet running
void ini_i2c_time(void){             // initialization of time/date vars on the I2C RTCC
uint8_t day=0;                       // local variable (stores the RTCC DAY register) 
day = i2c_rtcc_rd(ADDR_DAY);         // read day + OSCON bit 
if((day&OSCON)==OSCON) ;             // if oscillator = already running, do nothing. 
else{                                // if oscillator = not running, set time/date(arbitrary)
i2c_rtcc_wr(ADDR_YEAR,0x21);         // initialize YEAR  register : (20)17           
i2c_rtcc_wr(ADDR_MNTH,0x5);          // initialize MONTH register : maj  
i2c_rtcc_wr(ADDR_DATE,0x22);         // initialize DATE  register : date = 28  
i2c_rtcc_wr(ADDR_HOUR,0x00);         // initialize HOUR  register : hour = 00  
i2c_rtcc_wr(ADDR_MIN,0x00) ;         // initialize MIN   register : min  = 00  
i2c_rtcc_wr(ADDR_SEC,START_32KHZ);}  // init SEC register and start the 32khz oscillator .
} 

*/