/*
 * File:   main.c
 * Author: Malone
 *
 * Created on April 10, 2023, 6:01 PM
 */

#include "spi.h"

void PPS_init(void){
    
    /* Unlock PPS */
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x00;
    
    //RA1PPS = 0x20; //ss
    RC5PPS = 0x1F; //SDO
    RC3PPS = 0x1E; //SCK
    //RC2PPS = 0x20; //SS
    //SPI1SDIPPS = 0x14; //SDI
    
    /* Lock PPS */
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x01;
}

void port_init(void){
    
//    TRISA &= ~0x02;
    TRISC &= ~0x2F; //SCK - RC3 | SDI - RC4 | SDO - RC5 | SS - RC2 | RS - RC1 | RST - RC0
//    
//    ANSELA &= ~0x02;
    ANSELC &= ~0x2F; //digital
}

void spi_init(void){
    
    SPI1CON0bits.EN = 0;
    port_init();
    PPS_init();
    
    SPI1CLK |= 0x01; //FOSC
    SPI1BAUD |= 0x40; //BAUD 
    SPI1CON0 |= 0x03; //bit mode 1
    SPI1CON1 |= 0x54; 
    SPI1CON2 |= 0x02;
    SPI1INTE |= 0x00;
    SPI1INTF |= 0x00;
    
    SPI1CON0bits.EN = 1;
    
}

void cs_low(void){
    
    LATC &=~ 0x04;
}

void cs_high(void){
    
    LATC |= 0x04;
}

void dc_low(void){
 
    LATC &=~ 0x02;
}

void dc_high(void){
    
    LATC |= 0x02;
}

void rst_high(void){
    
    LATC |= 0x01;
}

void rst_low(void){
    
    LATC &=~ 0x01;
}

void spi_write(uint8_t data){
    
    SPI1TXB = data;
    while(SPI1STATUS & (1<<5)){
    }
}