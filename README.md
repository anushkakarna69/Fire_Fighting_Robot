# 🔥 Fire-Fighting Robot | Auto Fire Chaser and Extinguisher

An autonomous robot capable of detecting and extinguishing small-scale fires using infrared sensors and a water-pumping system. Built using Arduino Uno, this robot is a step towards safer and smarter firefighting technologies, minimizing human risk in hazardous environments.

---

## 📌 Project Overview

This project aims to develop a fire-fighting robot that can autonomously detect fire and respond with extinguishing actions. Using IR flame sensors and an Arduino-controlled system, the robot navigates toward the fire source and activates a water pump to put out the flame.

---

## 🧠 Key Features

- 🔍 **Autonomous Fire Detection** using IR flame sensors
- 🚗 **Direction-Based Navigation** toward the flame source
- 💧 **Automatic Water Dispensing** system via relay and water pump
- 🔄 **Servo-Controlled Spraying** for targeted extinguishing
- 🔋 Battery-powered, fully mobile robotic platform

---

## ⚙️ Hardware Components

| Component                | Description                                |
|--------------------------|--------------------------------------------|
| IR Flame Sensors (x3)    | Detects fire using infrared radiation      |
| Arduino Uno              | Central microcontroller                    |
| BO Motors + Wheels       | Enables robot mobility                     |
| L298 Motor Driver        | Controls motor direction and speed         |
| Water Pump + Relay       | Dispenses water upon fire detection        |
| Mini Servo               | Adjusts nozzle for water spray             |
| Water Tank/Bottle        | Holds water for extinguishing              |
| Breadboard + Wires       | For circuit prototyping                    |
| 18650 Batteries (x3)     | Power supply                               |

---

## 🛠️ Methodology

### 1. **Hardware Setup**
- IR sensors mounted at different angles for multi-directional detection.
- BO motors connected via motor driver for smooth movement.
- Relay-controlled water pump mounted on chassis with a mini water tank.

### 2. **Programming (Arduino)**
- IR sensor values processed for directional decisions.
- Robot navigates toward the detected flame source.
- Relay triggers water pump while servo motor oscillates nozzle direction.

### 3. **Testing Procedure**
- Simulated fire source (e.g., candle) used.
- Robot observed for fire detection, directional movement, and water activation.
- Performance evaluated on response time and extinguishing success.

---

## 📊 Results Summary

| Parameter               | Observation                        |
|--------------------------|------------------------------------|
| Fire Detection Time     | ~2–3 seconds                       |
| Navigation Accuracy     | ~90% accurate directional movement |
| Pump Activation         | Successful in all test cases       |
| Extinguishing Time      | ~5 seconds                         |

---

## ⚠️ Limitations

- 🔆 **False Detections** from strong ambient light
- 🔋 **Battery Drain** impacts prolonged operations
- 🚿 **Low Pressure** water spray requires close distance to fire

---

## 🚀 Future Improvements

- Integration of **thermal cameras** for precision fire detection
- AI-based **fire pattern recognition**
- **Remote control and monitoring** via wireless communication
- Improved **spraying mechanism** for extended range

---

## 👥 Team Members – Group 5

- Ayush Raj – 23051337  
- Kalyan Dutta – 23051596  
- Soumyaja Dey – 23051710  
- Yuvraj Aarsh – 23052450  
- Soumen Mallick – 23052436  
- Sinjini Das – 23052432  
- Snehal Srut Pradhan – 23052599  
- Kshitij Joshi – 23052500  
- Anushka Karna – 23053646  
- Bhumi Shah – 23053631  

---

## 🏫 Institution

**School of Computer Engineering**  
**Kalinga Institute of Industrial Technology (KIIT DU)**  
VT Lab – Cyber Physics and Industrial IoT

---

## 📚 References

- [Arduino Documentation](https://www.arduino.cc)
- [Espressif Technical Reference](https://www.espressif.com)
- [IEEE Robotics Society – Fire-Fighting Robots](https://www.ieee-ras.org)

---

> This project demonstrates a practical and scalable approach to robotic firefighting, offering future possibilities in industrial and domestic safety automation.
