#define F_CPU 16000000UL // Define clock speed (16 MHz for Arduino Leonardo)
#include <avr/io.h>
#include <util/delay.h>

#define PWM_FREQUENCY 100   // PWM frequency (100 Hz)
#define MAX_DUTY_CYCLE 100  // Maximum duty cycle (%100)
#define MIN_DUTY_CYCLE 0    // Minimum duty cycle (%0)
#define STEP 1              // Duty cycle increment/decrement step
#define DELAY_MS 10         // Delay between steps (10 ms)

void PWM_Init(void) {
	// Set PB5 (Digital Pin 9) as output
	DDRB |= (1 << PB5);

	
	TCCR1A |= (1 << COM1A1) | (1 << WGM11); // Non-inverting mode, Fast PWM
	TCCR1B |= (1 << WGM12) | (1 << WGM13);  // Fast PWM, ICR1 TOP

	ICR1 = (F_CPU / (8 * PWM_FREQUENCY)) - 1; // Prescaler = 8

	
	OCR1A = (ICR1 * MIN_DUTY_CYCLE) / 100;

	// Set the clock prescaler to 8
	TCCR1B |= (1 << CS11);
}

int main(void) {
	// Initialize PWM
	PWM_Init();

	uint8_t duty_cycle = MIN_DUTY_CYCLE; // Starting duty cycle
	uint8_t direction = 1;              // 1: Increasing, 0: Decreasing

	while (1) {
		// Update the duty cycle
		if (direction) {
			duty_cycle += STEP; // Increase duty cycle
			if (duty_cycle >= MAX_DUTY_CYCLE) {
				duty_cycle = MAX_DUTY_CYCLE;
				direction = 0; // Switch to decreasing
			}
			} else {
			duty_cycle -= STEP; // Decrease duty cycle
			if (duty_cycle <= MIN_DUTY_CYCLE) {
				duty_cycle = MIN_DUTY_CYCLE;
				direction = 1; // Switch to increasing
			}
		}

		// Apply the updated duty cycle to OCR1A
		OCR1A = (ICR1 * duty_cycle) / 100;

		// Delay between steps for smooth effect
		_delay_ms(DELAY_MS);
	}

	return 0;
}