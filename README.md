# Car Reversing Sensor with LCD Display

This project is a car reversing sensor system that uses an HC-SR04 ultrasonic distance sensor to measure the distance to an obstacle and display it on a 16x2 LCD screen. If the distance to the obstacle is less than a predefined threshold, an LED is turned on to alert the driver.

## Features

- Measures distance using HC-SR04 ultrasonic sensor
- Displays the measured distance on a 16x2 LCD screen
- Alerts the driver with an LED when the distance is below a threshold
- Modular code design for easy maintenance and extension

## Hardware Requirements

- ATmega328P microcontroller
- HC-SR04 ultrasonic distance sensor
- 16x2 LCD screen
- LED
- Resistors, wires, and a breadboard

## Software Requirements

- AVR-GCC compiler
- AVRDUDE for programming the microcontroller
- Make (optional) for building the project

## Circuit Diagram

![Circuit Diagram](path_to_your_circuit_diagram_image)

## Installation

1. Clone the repository:

    ```sh
    git clone https://github.com/yourusername/car-reversing-sensor.git
    cd car-reversing-sensor
    ```

2. Connect the hardware according to the circuit diagram.

3. Build the project:

    ```sh
    make all
    ```

4. Flash the firmware to the microcontroller:

    ```sh
    make flash
    ```

## Usage

The system will start measuring the distance as soon as it is powered on. The distance to the nearest obstacle will be displayed on the LCD screen. If the distance is less than the threshold (0.5 meters), the LED will turn on to alert the driver.

## Code Structure

- `main.c`: Contains the main loop and integration of sensor and display functionalities.
- `distance_sensor.h` and `distance_sensor.c`: Contains functions related to the HC-SR04 sensor.
- `lcd_display.h` and `lcd_display.c`: Contains functions related to the 16x2 LCD display.

## Functions Overview

### Distance Sensor Functions

- `void DistanceSensor_init()`: Initializes the distance sensor.
- `double DistanceSensor_measureDistance()`: Measures the distance and returns it as a double.

### LCD Display Functions

- `void LcdDisplay_init()`: Initializes the LCD display.
- `void LcdDisplay_display(const char* str)`: Displays a string on the LCD.
