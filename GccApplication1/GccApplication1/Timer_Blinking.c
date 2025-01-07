#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 16000000UL // Define the microcontroller clock frequency
#define BLINK_FREQ 2     // Define the LED blink frequency (in Hz)

void Timer1_Init(void) {
	
	TCCR1B |= (1 << WGM12); // Set WGM12 bit to enable CTC mode

	
	OCR1A = (F_CPU / (2 * 1024 * BLINK_FREQ)) - 1;

	
	TIMSK1 |= (1 << OCIE1A);

	
	TCCR1B |= (1 << CS12) | (1 << CS10);
}


ISR(TIMER1_COMPA_vect) {
	
	PORTC ^= (1 << PC7);
}

int main(void) {
	// Configure PC7 as an output pin
	DDRC |= (1 << PC7);


	Timer1_Init();


	sei();


	while (1) {
	}

	return 0;
}