#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
void ledInit ()
{
DDRB |= 1 << 5; // PB5 je izlaz
}
void ledBlink ( int16_t high_time , int16_t low_time )
{
PORTB |= 1 << 5; // LED ON
_delay_ms ( high_time ) ; // Pauza 1 s
PORTB &= ~(1 << 5) ; // LED OFF
_delay_ms ( low_time ); // Pauza 1 s
}
int16_t main ()
{
int16_t high_time = 300;
int16_t low_time = 700;
ledInit () ;
while (1)
{
ledBlink ( high_time , low_time );
}
return 0;
}
