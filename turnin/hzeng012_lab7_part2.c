 /* Author: Hulbert Zeng
 * Partner(s) Name (if applicable):  
 * Lab Section: 021
 * Assignment: Lab #7  Exercise #2
 * Exercise Description: [optional - include for your own benefit]
 *
 * I acknowledge all content contained herein, excluding template or example
 * code, is my own original work.
 *
 *  Demo Link: https://youtu.be/Joxf-nc8mOI
 */ 
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init() {
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}
/* One of my 10 LED lights is broken thus why I am only using 9 bits instead of 10.*/
int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    DDRD = 0xFF; PORTD = 0x00;
    ADC_init();
    /* Insert your solution below */
    while (1) {
        unsigned short x = ADC;
        unsigned char lower_bits = (char)x;
        unsigned char upper_bits = (char)(x >> 8);
        PORTC = lower_bits;
        PORTD = upper_bits;
    }
    return 1;
}
