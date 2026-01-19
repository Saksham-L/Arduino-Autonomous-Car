# Arduino-Autonomous-Car
A fully autonomous car that can navigate itself through any maze.

# Autonomous Maze-Solving Robot

An Arduino-based autonomous robot designed to navigate and solve a maze without any human intervention. The robot uses distance sensing, motor control, and simple decision logic to detect walls and make navigation choices in real time.

## Overview
This project was developed as part of a Computer Science & Programming course. The goal was to design and build a fully autonomous robot capable of solving a maze using only Arduino-compatible components. The robot starts and stops using physical buttons, provides visual feedback through an RGB LED, and avoids obstacles using a distance sensor.

## Features
- Fully autonomous maze navigation
- Real-time obstacle detection using a distance sensor
- Start/stop control via physical buttons
- Visual feedback using RGB LED indicators
- Motor driver–controlled differential drive system

## Hardware Components
- Arduino RedBoard Qwiic
- Distance sensor (Trig/Echo)
- Motor driver
- 2 DC motors
- RGB LED (with 330Ω resistors)
- Start (green) and stop (red) buttons
- Jumper wires
- 4× AA batteries

## Pin Configuration (Key Connections)
**Distance Sensor**
- VCC → A14  
- Trig → A15  
- Echo → A16  
- GND → A17  

**RGB LED**
- Blue → A18  
- GND → A19  
- Green → A20  
- Red → A21  

**Buttons**
- Green (Start) Button → D25  
- Red (Stop) Button → D22  

**Motors**
- Right Motor → A4 (Red), A5 (Black)
- Left Motor → A6 (Black), A7 (Red)

## How the Robot Works
1. When the green button is pressed, the robot begins moving forward.
2. The distance sensor continuously checks for obstacles.
3. If an obstacle is detected within 3 inches:
   - The LED turns red
   - The robot turns right
   - If another obstacle is detected, it turns again
4. If no obstacle is detected:
   - The LED turns green
   - The robot continues moving forward
5. Pressing the red button stops the robot immediately.

## Maze-Solving Algorithm (Simplified)
```text
If start button pressed:
    If obstacle detected:
        Turn right
        If obstacle still detected:
            Turn right again
    Else:
        Move forward
Else:
    Stop motors
