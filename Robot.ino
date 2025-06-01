 #include <Servo.h>

// Define flame sensor pins
#define FLAME_SENSOR_LEFT A0
#define FLAME_SENSOR_CENTER A1
#define FLAME_SENSOR_RIGHT A2

// Define motor driver pins
#define MOTOR_L1 5  // Left Motor Forward
#define MOTOR_L2 6  // Left Motor Backward
#define MOTOR_R1 9  // Right Motor Forward
#define MOTOR_R2 10 // Right Motor Backward

// Define relay for water pump
#define RELAY_PIN 7
#define RELAY_ON LOW  // Adjust based on relay type
#define RELAY_OFF HIGH

// Define servo motor pin
#define SERVO_PIN 3

// Create Servo object
Servo waterServo;

// Flame sensor threshold
#define FIRE_DETECTED_THRESHOLD 800  // Adjust based on sensor readings
#define DEAD_ZONE 50  // Minimum difference before turning

void setup() {
  Serial.begin(9600);
  
  pinMode(MOTOR_L1, OUTPUT);
  pinMode(MOTOR_L2, OUTPUT);
  pinMode(MOTOR_R1, OUTPUT);
  pinMode(MOTOR_R2, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, RELAY_OFF);
  waterServo.attach(SERVO_PIN);
  waterServo.write(90);
  
  pinMode(FLAME_SENSOR_LEFT, INPUT);
  pinMode(FLAME_SENSOR_CENTER, INPUT);
  pinMode(FLAME_SENSOR_RIGHT, INPUT);
  
  Serial.println("🚀 Fire Fighting Robot Initialized...");
}

void loop() {
    int flameLeft = analogRead(FLAME_SENSOR_LEFT);
    int flameCenter = analogRead(FLAME_SENSOR_CENTER);
    int flameRight = analogRead(FLAME_SENSOR_RIGHT);

    Serial.print("Flame Left: "); Serial.print(flameLeft);
    Serial.print(" | Flame Center: "); Serial.print(flameCenter);
    Serial.print(" | Flame Right: "); Serial.println(flameRight);

    if (flameCenter < FIRE_DETECTED_THRESHOLD) {
        Serial.println("🔥 Fire Detected at Center! Moving Forward...");
        moveForward();
        activateWaterPump();
    } else if (flameLeft < FIRE_DETECTED_THRESHOLD && (flameLeft + DEAD_ZONE) < flameRight) {
        Serial.println("🔥 Fire Detected at Left! Turning Left...");
        turnLeft();
        activateWaterPump();
    } else if (flameRight < FIRE_DETECTED_THRESHOLD && (flameRight + DEAD_ZONE) < flameLeft) {
        Serial.println("🔥 Fire Detected at Right! Turning Right...");
        turnRight();
        activateWaterPump();
    } else {
        Serial.println("✅ No Fire Detected. Stopping...");
        stopMotors();
        deactivateWaterPump();
    }

    delay(700); // Slightly increased delay for stability
}

void moveForward() {
    digitalWrite(MOTOR_L1, HIGH);
    digitalWrite(MOTOR_L2, LOW);
    digitalWrite(MOTOR_R1, HIGH);
    digitalWrite(MOTOR_R2, LOW);
    delay(200);
    stopMotors();
}

void turnLeft() {
    digitalWrite(MOTOR_L1, LOW);
    digitalWrite(MOTOR_L2, HIGH);
    digitalWrite(MOTOR_R1, HIGH);
    digitalWrite(MOTOR_R2, LOW);
    delay(250);
    stopMotors();
}

void turnRight() {
    digitalWrite(MOTOR_L1, HIGH);
    digitalWrite(MOTOR_L2, LOW);
    digitalWrite(MOTOR_R1, LOW);
    digitalWrite(MOTOR_R2, HIGH);
    delay(250);
    stopMotors();
}

void stopMotors() {
    digitalWrite(MOTOR_L1, LOW);
    digitalWrite(MOTOR_L2, LOW);
    digitalWrite(MOTOR_R1, LOW);
    digitalWrite(MOTOR_R2, LOW);
}

void activateWaterPump() {
    Serial.println("🚰 Activating Water Pump...");
    digitalWrite(RELAY_PIN, RELAY_ON);

    for (int pos = 60; pos <= 120; pos += 5) {
        waterServo.write(pos);
        delay(100);
    }
    for (int pos = 120; pos >= 60; pos -= 5) {
        waterServo.write(pos);
        delay(100);
    }

    delay(2000);
    deactivateWaterPump();
}

void deactivateWaterPump() {
    Serial.println("✅ Deactivating Water Pump...");
    digitalWrite(RELAY_PIN, RELAY_OFF);
    waterServo.write(90);
}
