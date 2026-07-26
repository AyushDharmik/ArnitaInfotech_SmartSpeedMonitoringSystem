# Smart Speed Monitoring System for Road Safety

**Embedded Systems Internship Project**  
**Arnita Infotech Pvt. Ltd.**

---

# Project Overview

The **Smart Speed Monitoring System** is an embedded system developed using **Arduino Uno** to measure the speed of a vehicle. The system uses two IR sensors (simulated using push buttons in Wokwi) placed at a fixed distance. When a vehicle passes both sensors, the Arduino calculates its speed and displays it on an OLED display.

If the measured speed exceeds the predefined speed limit, the system activates a buzzer to alert the user.

---

# Objectives

- Measure vehicle speed using two sensors.
- Display speed on an OLED display.
- Alert when the vehicle exceeds the speed limit.
- Simulate the complete system using Wokwi.

---

# Features

- Vehicle speed measurement
- OLED display output
- Overspeed detection
- Buzzer alert
- Vehicle counter
- Automatic reset for the next vehicle
- Wokwi simulation

---

# Components Used

| Component | Quantity |
|----------|---------:|
| Arduino Uno | 1 |
| SSD1306 OLED Display (I²C) | 1 |
| Push Buttons (IR Sensor Simulation) | 2 |
| Piezo Buzzer | 1 |
| Jumper Wires | As Required |

---

# Circuit Connections

## OLED Display

| OLED Pin | Arduino Uno |
|----------|-------------|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

## Sensor 1

| Component | Arduino |
|----------|----------|
| Push Button | D2 & GND |

## Sensor 2

| Component | Arduino |
|----------|----------|
| Push Button | D3 & GND |

## Buzzer

| Component | Arduino |
|----------|----------|
| Positive | D8 |
| Negative | GND |

---

# Working Principle

1. The system waits for the first sensor to detect a vehicle.
2. When Sensor 1 is triggered, the timer starts.
3. When Sensor 2 is triggered, the timer stops.
4. Arduino calculates the vehicle speed using the formula:

```
Speed = Distance / Time
Speed (km/h) = (Distance / Time) × 3.6
```

5. The calculated speed is displayed on the OLED display.
6. If the speed exceeds the speed limit, the buzzer sounds three times.
7. The system automatically resets and waits for the next vehicle.

---

# Project Structure

```text
ArnitaInfotech_Embedded_Task
│
├── Task_1
│   ├── Requirement_Analysis.docx
│   └── Requirement_Analysis.pdf
│
├── Task_2
│   ├── System_Specification.docx
│   └── System_Specification.pdf
│
├── Task_3
│   ├── sketch.ino
│   ├── diagram.json
│   ├── libraries.txt
│   ├── README.md
│   ├── Images
│   └── Video
```

---

# Project Screenshots

## Startup Screen

![Startup](Images/startup.png)

## Waiting Screen

![Waiting](Images/waiting.png)

## Vehicle Detection

![Vehicle Detected](Images/vehicle_detected.png)

## Safe Speed

![Safe Speed](Images/safe_speed.png)

## Over Speed Detection

![Over Speed](Images/over_speed.png)

## Circuit Diagram

![Circuit Diagram](Images/circuit.png)

---

# Demonstration Video

The project demonstration video is available in the **Video** folder.

---

# Software Used

- Arduino IDE
- Wokwi Simulator
- GitHub

---

# Future Improvements

- Real IR obstacle sensors
- Camera-based vehicle detection
- GSM module for SMS alerts
- Real-Time Clock (RTC)
- SD card data logging
- Traffic statistics dashboard

---

# Author

**Ayush Kishor Dharmik**

B.Tech Electronics and Telecommunication Engineering

MIT Academy of Engineering (MITAOE), Alandi, Pune

---

# License

This project was developed for educational purposes as part of the **Embedded Systems Internship Program** conducted by **Arnita Infotech Pvt. Ltd.**
