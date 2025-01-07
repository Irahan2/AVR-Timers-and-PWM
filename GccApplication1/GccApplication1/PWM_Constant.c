#define F_CPU 16000000UL // Define clock speed (16 MHz for Arduino Leonardo)
#include <avr/io.h>

#define PWM_FREQUENCY 50 // PWM frequency (50 Hz)
#define DUTY_CYCLE 50    // Duty cycle (50% brightness)

void PWM_Init(void) {
	// I Set PB5 (Digital Pin 9) as output
	DDRB |= (1 << PB5);

	
	TCCR1A |= (1 << COM1A1) | (1 << WGM11);
	TCCR1B |= (1 << WGM12) | (1 << WGM13);

	// Set the frequency (ICR1 controls the TOP value for Fast PWM)
	ICR1 = (F_CPU / (8 * PWM_FREQUENCY)) - 1; // Prescaler = 8

	// Set the duty cycle (OCR1A controls the duty cycle)
	OCR1A = (ICR1 * DUTY_CYCLE) / 100;

	// Set the clock prescaler to 8
	TCCR1B |= (1 << CS11);
}

int main(void) {
	
	PWM_Init();

	
	while (1) {
		
	}

	return 0;
}