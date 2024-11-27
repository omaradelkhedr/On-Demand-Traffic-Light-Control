
# Traffic Light System with On-Demand Crosswalk Button

## Project Overview

This project simulates a traffic light system with an on-demand crosswalk button for pedestrians. The system uses an ATmega32 microcontroller to control traffic lights and pedestrian signals based on button presses and traffic light status. The system operates in two modes: Normal Mode (for vehicles) and Pedestrian Mode (activated by a crosswalk button).

![Photo](https://github.com/user-attachments/assets/ebbb9967-b165-4b91-b045-f404bd8f5fa3)


### Traffic Light Modes:
1. **Normal Mode**:
   - Vehicles' lights cycle through green, yellow, and red.
   - Yellow light blinks for 5 seconds before changing.
2. **Pedestrian Mode**:
   - Activated by the pedestrian crosswalk button.
   - The pedestrian green light turns on when the car's red light is on, allowing pedestrians to cross.
   - If the car's green or yellow light is on, pedestrians must wait until the lights change.

## Features

- **Normal Traffic Light Cycle**:
  - The car's lights (Green, Yellow, Red) change every 5 seconds (Green -> Yellow -> Red -> Yellow -> Green).
  
- **Pedestrian Mode**:
  - Pedestrian crosswalk button triggers the change in light sequence for safe crossing.
  - Pedestrian green light is on for 5 seconds, while car's red light is active.
  - Yellow lights blink for 5 seconds as part of the light transitions.

## Hardware Requirements

- **Microcontroller**: ATmega32
- **Push Button**: Connected to INT0 pin for pedestrian crosswalk.
- **LEDs**:
  - **Vehicle LEDs**: Green, Yellow, and Red connected to Port A (pins 0, 1, and 2).
  - **Pedestrian LEDs**: Green, Yellow, and Red connected to Port B (pins 0, 1, and 2).

## Software Requirements

- **Normal Mode**:
  - The vehicle's LEDs change every 5 seconds (Green -> Yellow -> Red -> Yellow -> Green).
  
- **Pedestrian Mode**:
  - Pedestrian crosswalk button triggers the pedestrian light change based on vehicle light status:
    - When the vehicle’s red light is on, pedestrians get a green signal to cross.
    - When the vehicle’s green or yellow lights are on, pedestrians wait until the lights change.

## System Design

### System Layers:
1. **Application Layer**: Controls the flow and logic of the system.
2. **Hardware Abstraction Layer (HAL)**: Interacts with the hardware (LEDs, button).
3. **Microcontroller Abstraction Layer (MCAL)**: Manages low-level operations like GPIO for input and output.

### Key System Drivers:
- **LED Driver**: Controls the LEDs for vehicles and pedestrians.
- **Button Driver**: Detects button presses and handles debouncing.
- **Traffic Light Driver**: Controls the state transitions between vehicle and pedestrian lights.

### System Flowchart:


![System Flowchart](https://github.com/user-attachments/assets/af30fe25-8a83-41f2-83f6-7399c8351c98)



## Testing

### User Stories:

- **User Story 1**: As a pedestrian, when I make a short press on the crosswalk button while the cars' green light is on and pedestrian red light is off, I will wait for the yellow lights to blink for five seconds, then the cars' red light and pedestrian green light will be on for five seconds, allowing me to cross the street.
  
- **User Story 2**: As a pedestrian, when I make a short press on the crosswalk button while the cars' yellow light is blinking and pedestrian red light is on, I will wait for the yellow lights to blink for five seconds, then the cars' red light and pedestrian green light will be on for five seconds, allowing me to cross the street.

- **User Story 3**: As a pedestrian, when I make a short press on the crosswalk button while the cars' red light is on and pedestrian green light is on, nothing will happen.

- **User Story 4**: As a pedestrian, when I make a long press on the crosswalk button, nothing will happen.

- **User Story 5**: As a pedestrian, when I make a double press on the crosswalk button, the first press will trigger the action, and nothing will happen after the second press.

### Testing Environment:

- The system has been tested using **Proteus** simulation (or hardware if applicable). Each user story was tested to validate the proper transition of traffic light states.

