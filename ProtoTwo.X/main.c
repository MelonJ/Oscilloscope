/*
 * File:   main.c
 * Author: Malone
 *
 * Easy blink LED with Interrupts
 * Created on April 23, 2023, 5:12 PM
 */


#include "CONFIG.h"
#include "spi.h"
#include "ST7735.h"
//#define _XTAL_FREQ 20000000

void main(void) {
    
//    OSCCON3 = 0x00;
//    OSCFRQ = 0x08;
//    OSCTUNE = 0x00;
//    CLKRCLK = 0x01;
    
    TRISDbits.TRISD0 = 0; //LED as output
    LATDbits.LATD0 = 0; //LED initially off
    spi_init();
    //TFT_RedTab_Initialize();
    //fillScreen(ST7735_CYAN);
    //spi_write(0xAA);
    
    while(1)
    {
        
        spi_write(0x7F);
        __delay_ms(1000);
        LATDbits.LATD0 ^= 1;
        
    }
    
    return;
}