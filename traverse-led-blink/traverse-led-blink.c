// ------------ Preamble ------------
#define F_CPU 16000000UL

#include <avr/io.h>             /*Defines pins, ports, etc*/
#include <util/delay.h>      /* Functions to waste time*/

// --------- Functions --------- //
void POVDisplay(uint8_t oneByte) {
    PORTB = oneByte;
    _delay_ms(20);
}

int main(void) {
    //------------ Inits ------------//
    DDRB = 0xff;          /*
                                    Data Direction Register B:
                                    Writing a one to the bit enables output.
                                */
    // ------------ Event Loop ------------//
    while (1) {
        POVDisplay(0b10000000);
        POVDisplay(0b01000000);
        POVDisplay(0b00100000);
        POVDisplay(0b00010000);
        POVDisplay(0b00001000);
        POVDisplay(0b00000100);
        POVDisplay(0b00000010);
        POVDisplay(0b00000001);

        PORTB = 0;
        _delay_ms(10);
    }
    return(0);
}