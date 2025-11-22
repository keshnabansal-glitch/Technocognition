#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <MPU6050_tockn.h>
#include <SoftwareSerial.h>

// LCD + MPU
LiquidCrystal_I2C lcd(0x27, 16, 2);
MPU6050 mpu(Wire);

// IR + Buzzer
#define IR_PIN 2
#define BUZZER 8

// Bluetooth pins
SoftwareSerial BT(10, 11);  // TX =10, RX =11

const int DOWNWARD_TILT_THRESHOLD = 60;  // degrees

void setup() {
  Serial.begin(9600);
  BT.begin(9600);  // Bluetooth Baud Rate

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.print("Vertical Angle");
  delay(1500);
  lcd.clear();

  pinMode(IR_PIN, INPUT);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);

  Wire.begin();
  mpu.begin();
  mpu.calcGyroOffsets();
}

void loop() {

  mpu.update();

  // --------- Read acceleration ---------
  float ax = mpu.getAccX();
  float ay = mpu.getAccY();
  float az = mpu.getAccZ();

  // --------- Total magnitude ---------
  float total = sqrt(ax*ax + ay*ay + az*az);

  // --------- Vertical angle ---------
  float verticalAngle = acos(az / total) * (180.0 / PI);

  // --------- Eye detection ---------
  bool eyesClosed = (digitalRead(IR_PIN) == LOW);

  // --------- Tilt detection ---------
  bool headDown = (verticalAngle > DOWNWARD_TILT_THRESHOLD);

  lcd.clear();

  if (headDown) {
    lcd.setCursor(0,0);
    lcd.print("SLEEP ALERT!");

    lcd.setCursor(0,1);
    lcd.print("HEAD DOWN!!! ");

    // ----------- BLUETOOTH WARNING ------------
    BT.println("ALERT: HEAD DOWN! DRIVER DROWSY!");
    BT.println("Emergency Attention Needed.");

    // -------- FAST BUZZER ALERT --------
    for (int i = 0; i < 6; i++) {
      digitalWrite(BUZZER, HIGH);
      delay(60);
      digitalWrite(BUZZER, LOW);
      delay(40);
    }

  }
  else {
    lcd.setCursor(0, 0);
    lcd.print("STABLE: Eyes ");

    if (eyesClosed) lcd.print("Closed");
    else lcd.print("Open  ");

    lcd.setCursor(0, 1);
    lcd.print("Angle:");
    lcd.print((int)verticalAngle);
    lcd.print(" deg ");

    digitalWrite(BUZZER, LOW);
  }

  delay(120);
}










