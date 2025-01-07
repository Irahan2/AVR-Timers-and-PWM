#define F_CPU 16000000UL // I Set clock frequency to 16 MHz
#include <avr/io.h>
#include <avr/wdt.h>
#include <util/delay.h>

void WDT_Init(void) {
	
	MCUSR &= ~(1 << WDRF);

	
	WDTCSR |= (1 << WDCE) | (1 << WDE);

	
	WDTCSR = (1 << WDE) | (1 << WDP2) | (1 << WDP1); // 2-second timeout
}

int main(void) {
	// Configure PC7 (D13) as output
	DDRC |= (1 << PC7);

	// Turn on LED after reset
	PORTC |= (1 << PC7);
	_delay_ms(1000); // Keep LED on for 1 second

	// Turn off LED
	PORTC &= ~(1 << PC7);

	// Initialize Watchdog Timer
	WDT_Init();

	while (1) {
		// Main loop does nothing; WDT will reset microcontroller every 2 seconds
	}

	return 0;
}