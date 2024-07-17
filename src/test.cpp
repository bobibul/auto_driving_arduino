// #include <Arduino.h>
// #include "Motor_Control.h"

// #define STEERING_MOTOR_IN1 2
// #define STEERING_MOTOR_IN2 3

// #define MAIN_MOTOR_1_IN1 6
// #define MAIN_MOTOR_1_IN2 7

// #define MAIN_MOTOR_2_IN1 8
// #define MAIN_MOTOR_2_IN2 9

// #define ENCODER A5

// void setup() 
// {
//     Serial.begin(9600);
//     pinMode(STEERING_MOTOR_IN1, OUTPUT); 
//     pinMode(STEERING_MOTOR_IN2, OUTPUT);
//     pinMode(MAIN_MOTOR_1_IN1, OUTPUT);
//     pinMode(MAIN_MOTOR_1_IN2, OUTPUT);
//     pinMode(MAIN_MOTOR_2_IN1, OUTPUT);
//     pinMode(MAIN_MOTOR_2_IN2, OUTPUT);
//     pinMode(ENCODER, INPUT);
  
  

// }
// void loop() {
//     int value; // 왼쪽 -> 오른쪽 값 증가, 중간 약 120으로
//     value = analogRead(ENCODER) / 4;
//     Serial.println(value);



//     analogWrite(STEERING_MOTOR_IN1, 200);
//     analogWrite(STEERING_MOTOR_IN2, LOW);
//     delay(1000);
//     analogWrite(STEERING_MOTOR_IN1, LOW);
//     analogWrite(STEERING_MOTOR_IN2, 200);
//     delay(1000);

//     앞으로감
//     analogWrite(MAIN_MOTOR_1_IN1, 50);
//     analogWrite(MAIN_MOTOR_1_IN2, LOW);
//     analogWrite(MAIN_MOTOR_2_IN1, 50);
//     analogWrite(MAIN_MOTOR_2_IN2, LOW);
//     delay(1000);


// }
