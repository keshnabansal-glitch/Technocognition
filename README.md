# 🚨 Driver Drowsiness & Head-Tilt Detection System

A safety alert system using **MPU6050**, **IR Eye Blink Sensor**, **LCD Display**, and a **Buzzer** to detect driver drowsiness based on **eye closure** and **head downward tilt**.

---

## 📌 Overview
This project monitors the driver’s alertness by detecting:
- **Head tilt angle** using MPU6050  
- **Eye blink status** using an IR sensor  
- **Real-time display** via 16×2 I2C LCD  
- **High-speed buzzer alarm** when drowsiness is detected  

If the driver's head tilts downward beyond **60°**, a rapid buzzer alert is activated.

---

## 🛠️ Hardware Components
- Arduino Uno / Nano  
- MPU6050 Accelerometer + Gyroscope  
- IR Eye Blink Sensor  
- 16×2 LCD (I2C)  
- Buzzer  
- Jumper Wires  

---

## 🔧 Pin Connections

### **LCD (I2C)**
- SDA → A4  
- SCL → A5  
- VCC → 5V  
- GND → GND  

### **IR Sensor**
- OUT → D2  
- VCC → 5V  
- GND → GND  

### **Buzzer**
- + → D8  
- – → GND  

---

## 📐 Working Principle

### **1️⃣ Head Tilt Detection**
- MPU6050 provides X, Y, Z acceleration.  
- Total vector magnitude is computed.  
- Vertical angle is calculated:  
