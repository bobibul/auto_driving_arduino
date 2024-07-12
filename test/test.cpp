#include <Arduino.h>
#include "Motor_Control.h"

#define STEERING_MOTOR_IN1 2
#define STEERING_MOTOR_IN2 3

#define MAIN_MOTOR_1_IN1 6
#define MAIN_MOTOR_1_IN2 7

#define MAIN_MOTOR_2_IN1 8
#define MAIN_MOTOR_2_IN2 9

int cmd;

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);Serial.println("hi");
  Serial.println("hello");
}

void loop() {

    if(Serial.available()){
        cmd = Serial.read();
        Serial.println(cmd);
    }
  
  
}
