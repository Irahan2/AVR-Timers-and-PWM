# AVR Timers and PWM

This repository demonstrates the use of AVR Timers and Pulse Width Modulation (PWM) techniques to perform various tasks using an AVR microcontroller. Each task is implemented in a separate C file, and all programs are designed to run on an AVR platform with the Arduino Leonardo as the target board.

### 1. Timer-Based LED Blinking
**File:** `Timer_Blinking.c`

- **Description:**
  - Utilizes Timer1 in CTC (Clear Timer on Compare Match) mode to toggle an LED connected to pin PC7 at a specified frequency.
  - The LED blinks at 2 Hz.

- **Key Features:**
  - Timer1 is configured with a 1024 prescaler.
  - Interrupt Service Routine (ISR) toggles the LED state upon reaching the compare match value.

### 2. Watchdog Timer Reset
**File:** `Watchdog_Reset.c`

- **Description:**
  - Configures the Watchdog Timer (WDT) to reset the microcontroller every 2 seconds if the WDT is not refreshed.
  - An LED connected to PC7 is turned on for 1 second after each reset.

- **Key Features:**
  - WDT is configured with a 2-second timeout.
  - Demonstrates the use of WDT initialization and handling.

### 3. Constant Duty Cycle PWM
**File:** `PWM_Constant.c`

- **Description:**
  - Generates a PWM signal with a fixed frequency of 50 Hz and a duty cycle of 50%.
  - The PWM signal controls the brightness of an LED connected to pin PB5.

- **Key Features:**
  - Timer1 is configured in Fast PWM mode with a prescaler of 8.
  - Frequency and duty cycle are determined by `ICR1` and `OCR1A` respectively.

### 4. PWM-Based Brightening/Dimming Effect
**File:** `PWM_Dimming.c`

- **Description:**
  - Gradually increases and decreases the brightness of an LED by varying the PWM duty cycle between 0% and 100%.

- **Key Features:**
  - Smooth dimming effect achieved using incremental duty cycle changes.
  - Adjusts `OCR1A` in a loop with delays for smooth transitions.

## Repository Structure
```
.
├── GccApplication1
│   ├── Debug
│   ├── PWM_Constant.c
│   ├── PWM_Dimming.c
│   ├── Timer_Blinking.c
│   ├── Watchdog_Reset.c
│   ├── GccApplication1.cproj
│   └── GccApplication1.componentinfo.xml
├── README.md
```

## How to Use

1. Clone the repository:
   ```bash
   git clone https://github.com/YourUsername/AVR-Timers-and-PWM.git
   ```

2. Open the project in **Microchip Studio** or any compatible IDE.

3. Navigate to the desired task file (e.g., `Timer_Blinking.c`) and build the project.

4. Upload the compiled binary to your AVR board using a suitable programmer.

## Prerequisites

- **Hardware:**
  - Arduino Leonardo or any compatible AVR microcontroller.
  - External components such as LEDs and resistors as required.

- **Software:**
  - Microchip Studio or equivalent AVR development tools.
  - AVR toolchain for compilation.

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.

---

Feel free to explore and modify the code to suit your applications. Contributions and suggestions are always welcome!
