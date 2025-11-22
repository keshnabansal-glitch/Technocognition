README.md
🚨 Driver Drowsiness & Head-Tilt Detection System
A safety alert system using MPU6050, IR Eye-Blink Sensor, LCD Display, and a Buzzer to detect driver drowsiness based on eye closure and head downward tilt.

📌 Overview
This project detects signs of drowsiness in a driver by monitoring:


Head tilt angle using an MPU6050 accelerometer/gyroscope


Eye blink (open/closed) using an IR sensor


Real-time display of angle and eye status on a 16×2 I2C LCD


High-tempo buzzer alarm when head drops beyond a set angle


If the driver’s head tilts downward more than 60°, a rapid buzzer alert is triggered to wake them up.

🛠️ Hardware Components


Arduino Uno/Nano


MPU6050 – Accelerometer & Gyroscope


IR Eye Blink Sensor


I2C 16×2 LCD


Buzzer


Jumper wires



🔧 Pin Connections
LCD (I2C)


SDA → A4


SCL → A5


VCC → 5V


GND → GND


IR Sensor


OUT → D2


VCC → 5V


GND → GND


Buzzer




→ D8




– → GND



📐 Working Principle
1️⃣ Head Tilt Detection


The MPU6050 provides X, Y, Z acceleration.


Total acceleration vector is computed.


Vertical angle is calculated using:


verticalAngle = acos(az / total) * (180/PI)



If the angle exceeds 60°, the system assumes the head is falling down → SLEEP ALERT.


2️⃣ Eye Blink Detection


IR sensor detects whether eyes are:


Open → HIGH


Closed → LOW




Status is shown on the LCD.


3️⃣ Buzzer Alert
When head tilt exceeds threshold:


Buzzer emits rapid beeps (6 fast pulses).
This increases alertness and prevents micro-sleep.



📺 LCD Messages
ConditionLCD Line 1LCD Line 2BuzzerNormalSTABLE: Eyes Open/ClosedAngle: XX degOFFDrowsy (Head Down)SLEEP ALERT!HEAD DOWN!!!Rapid Beeps

🧠 Code Explanation
The code performs:


Initialization of LCD, MPU6050, IR sensor, and buzzer


Continuous reading of sensor values


Calculation of head tilt angle


Eye-open/closed detection


Conditional warnings + buzzer alert


Display of real-time data on LCD


The threshold angle can be changed here:
const int DOWNWARD_TILT_THRESHOLD = 60;  // degrees


▶️ How to Use


Upload the code to Arduino.


Power the circuit.


Keep the sensors near your head/eyes.


LCD will show:


Eye status


Head tilt in degrees




If the head drops → Buzzer alert activates!



🧪 Applications


Driver drowsiness detection


Industrial safety monitoring


Student attention monitoring


Wearable head-tracking devices



📄 License
This project is open-source. Modify or use freely for academic or personal purposes.

If you want, I can:
✔ Add images/diagrams
✔ Add a wiring schematic
✔ Convert this README into PDF, DOCX, or formatted GitHub-style
✔ Create a GitHub-ready folder structure
Just tell me!
