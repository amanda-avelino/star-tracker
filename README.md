# Star Tracker

An automated star-tracking system developed as an academic engineering project, combining astronomy, celestial coordinate systems, electronics, programming, and mechanical components.

## Overview

The Star Tracker project was developed with the objective of creating a system capable of automatically tracking celestial objects based on their position in the sky.

The system uses celestial coordinates, astronomical time calculations, sensors, and stepper motors to determine and perform the movement required to follow a target.

The project was developed at the **Federal University of Lavras (UFLA)** as part of an academic engineering project.

## Objectives

The main objectives of the project were:

- Study celestial coordinate systems and their application to astronomical tracking;
- Understand the relationship between celestial coordinates and the movement of a tracking system;
- Calculate local sidereal time using a real-time clock and the observer's longitude;
- Convert celestial coordinates into information that can be used to control stepper motors;
- Integrate a microcontroller with sensors, motors, and other electronic components;
- Develop a mechanical structure capable of supporting the tracking system;
- Test and evaluate the prototype.

## Theoretical Background

The position of a celestial object can be described using different coordinate systems.

For this project, the **equatorial coordinate system** was used, with:

- **Right Ascension (RA)**
- **Declination (Dec)**

These coordinates describe the position of an object on the celestial sphere.

To relate the position of a celestial object to the observer's local environment, the project calculates the **Local Sidereal Time (LST)** using information from the real-time clock and the observer's longitude.

Right Ascension is then converted from hours to degrees, allowing the celestial coordinates to be related to the required movement of the tracking system.

## System Overview

The general operation of the system can be represented as:

```text
Celestial Object
       ↓
Right Ascension + Declination
       ↓
Local Sidereal Time
       ↓
Coordinate Calculations
       ↓
Motor Position
       ↓
Stepper Motors
       ↓
Mechanical Tracking System
```

The Arduino is responsible for processing the relevant information and controlling the stepper motors according to the calculated positions.

## Hardware

The prototype was built using the following components:

- Arduino Uno
- Stepper motors
- Stepper motor drivers
- MPU-6050 gyroscope
- DS3231 Real-Time Clock (RTC)
- Protoboard
- Electrical wiring
- Power supply
- 3D-printed mechanical components

## Software

The control system was implemented using the Arduino programming environment.

The code uses libraries and routines for:

- Communication with electronic components
- Reading the DS3231 real-time clock
- Reading sensor information
- Stepper motor control
- Astronomical time calculations
- Right Ascension and Declination
- Conversion between astronomical coordinates and motor movement

The main libraries used in the prototype include:

```cpp
#include <Wire.h>
#include <DS3231.h>
#include <Stepper.h>
```

## Development

The development process involved several stages:

### 1. Study of Astronomical Concepts

The project began with the study of celestial coordinate systems, Right Ascension, Declination, and the relationship between celestial coordinates and the observer's position.

### 2. Electronic Assembly

The Arduino, sensors, real-time clock, motor drivers, and stepper motors were assembled and connected to form the control system.

### 3. Software Development

An Arduino program was developed to read the required information, perform the astronomical calculations, and control the motors.

### 4. Mechanical Development

A mechanical structure was developed to support the components and allow movement around the relevant axes.

Some of the structural components were produced using 3D printing.

### 5. Testing and Calibration

The prototype was assembled and subjected to initial tests.

Calibration and integration procedures were performed in an attempt to verify the behavior of the system.

## Results

The project resulted in a prototype integrating:

- Astronomical coordinate calculations
- A real-time clock
- Sensors
- A microcontroller
- Stepper motors
- Motor drivers
- A mechanical structure

The project demonstrated the integration of astronomical concepts with electronic and mechanical systems.

However, the final tracking precision could not be fully verified during the project.

### Demonstration

A short demonstration of the Star Tracker prototype in operation:

[ Watch the Star Tracker in action](https://youtube.com/shorts/J1A2CNMPfsA)

## Challenges and Limitations

Several technical challenges were encountered during development.

These included:

- Problems involving the Arduino communication port
- Difficulties related to power and ground connections on the protoboard
- Problems with some 3D-printed structural supports
- Intermittent stepper motor failures
- Motor vibrations
- Difficulties in performing a complete validation of the tracking precision

These limitations prevented a complete quantitative evaluation of the final tracking accuracy.

## Future Improvements

Based on the challenges encountered during development, possible future improvements include:

- Improving the mechanical structure
- Improving the power distribution system
- Refining motor calibration
- Improving the reliability of the stepper motors
- Developing a more precise positioning method
- Performing systematic measurements of tracking accuracy
- Improving the integration between the electronic and mechanical systems
- Carrying out more extensive experimental validation

## Repository Structure

```text
star-tracker/
│
├── README.md
│
├── src/
│   └── star_tracker.ino
│
├── images/
│   ├── prototype/
│   └── system/
│
└── report/
    └── project_report.pdf
```

##  Documentation

The project was documented in an academic technical report containing the theoretical background, system components, development methodology, code, results, and limitations.

## Authors

**Amanda Cristina Avelino**  
**Whilgnner Whanchellosk Cruz Miranda**
Physics Engineering  
Federal University of Lavras (UFLA)

## Project Context

This project was developed as an academic engineering project with an interdisciplinary approach involving:

- Astronomy
- Physics
- Electronics
- Programming
- Mechanical Engineering
- Instrumentation
