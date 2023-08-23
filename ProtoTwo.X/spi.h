/* 
 * File:   spi.h
 * Author: Malone
 *
 * Created on April 10, 2023, 11:25 PM
 */

#ifndef SPI_H
#define	SPI_H

#include "CONFIG.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>


#ifdef	__cplusplus
extern "C" {
#endif

    
void spi_init(void);

void PPS_init(void);

void port_init(void);

void spi_write(uint8_t data);

uint8_t spi_read(uint8_t data);

void cs_low(void);

void cs_high(void);

void rst_high(void);

void rst_low(void);

void dc_low(void);

void dc_high(void);


#ifdef	__cplusplus
}
#endif

#endif	/* SPI_H */

