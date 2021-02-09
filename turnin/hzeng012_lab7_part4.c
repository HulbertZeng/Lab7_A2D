 /* Author: Hulbert Zeng
 * Partner(s) Name (if applicable):  
 * Lab Section: 021
 * Assignment: Lab #7  Exercise #4
 * Exercise Description: [optional - include for your own benefit]
 *
 * I acknowledge all content contained herein, excluding template or example
 * code, is my own original work.
 *
 *  Demo Link: https://youtu.be/W0hKzEpbiP4
 */ 
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init() {
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    DDRD = 0xFF; PORTD = 0x00;
    ADC_init();
    unsigned int seq = 511 / 8;
    /* Insert your solution below */
    while (1) {
        unsigned short x = ADC;
        unsigned char result = 0xFF;
        for(unsigned int i = 0; i < 8; ++i) {
            if(x >= ((i + 1) * seq)) {
                result = result - (0x01 << i);
            }
        }
        PORTC = result;
    }
    return 1;
}
