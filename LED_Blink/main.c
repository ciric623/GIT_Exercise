#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
void ledBlink(int16_t high_time, int16_t low_time) {
    PORTB |= 1 << 5; // LED ON
    _delay_ms(high_time); // Pauza high_time ms
    PORTB &= ~(1 << 5); // LED OFF
    _delay_ms(low_time); // Pauza low_time ms
}

void ledInit() {
    DDRB |= 1 << 5; // PB5 je izlaz
}

int16_t main () {
    int16_t high_time = 300; // Promenjena vrednost high_time na 300
    int16_t low_time = 700; // Promenjena vrednost low_time na 700
    
    ledInit(); // Poziv funkcije ledInit() za inicijalizaciju LED diode
    
    while (1) {
        ledBlink(high_time, low_time); // Poziv funkcije ledBlink() za blinkanje LED diode
    }
    
    return 0;
}
