#include <Arduino.h>
#include "Motor_Control.h"
#include "Parking.h"

MainMotor main_motor;
SteeringMotor steering_motor;
Ultrasonic ultrasonic_right(32, 33);

void setup() {
    Serial.begin(115200); // 시리얼 모니터 연결

}

void loop() {
    steering_motor.read_angle();
    Serial.println(steering_motor.input);
    Serial.println("hi");
}