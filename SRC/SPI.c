#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI.h"

#define SPI_PORT    PORTB
#define SPI_DDR     DDRB
#define SS_PIN      PB4
#define MOSI_PIN    PB5
#define MISO_PIN    PB6
#define SCK_PIN     PB7

void SPI_voidInitMaster(void) {
  
    set_bit(SPI_DDR, MOSI_PIN);
    set_bit(SPI_DDR, SCK_PIN);
    set_bit(SPI_DDR, SS_PIN);
    clr_bit(SPI_DDR, MISO_PIN);


    set_bit(SPI_PORT, SS_PIN);

    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

void SPI_voidInitSlave(void) {
   
    set_bit(SPI_DDR, MISO_PIN);
    clr_bit(SPI_DDR, MOSI_PIN);
    clr_bit(SPI_DDR, SCK_PIN);
    clr_bit(SPI_DDR, SS_PIN);

    SPCR = (1 << SPE);
}

u8 SPI_u8Tranceive(u8 Copy_u8Data) {
   SPDR = Copy_u8Data;
  while (GET_BIT(SPSR, SPIF) == 0);

    return SPDR;
}