#include <Arduino.h>
#include "Motor_Control.h"
#include "Mission.h"

MainMotor main_motor;
Ultrasonic ultrasonic_right(32, 33);
Ultrasonic ultrasonic_back(34, 35);
SteeringMotor steering_motor;

String inputString = "";
bool stringcomplete = false;

void setup() 
{
    Serial.begin(115200); // 시리얼 모니터 연결
    steering_motor.parking_wheel_steering(0);
    main_motor.motor_forward(80);
    int count = 0;
    while(1){
        float dis = ultrasonic_right.ultrasonic_distance();
        Serial.println(dis);
        if(dis <= 50 && dis != 0){
            count++;
        }
        if(count >= 2){
            break;
        }
    }
    delay(1300);
    main_motor.motor_hold();
    delay(500);

    steering_motor.parking_wheel_steering(30);
    main_motor.motor_forward(80);
    delay(7000);
    main_motor.motor_hold();
    delay(1000);

    steering_motor.parking_wheel_steering(-30);
    main_motor.motor_backward(60);
    delay(5000);
    main_motor.motor_hold();
    steering_motor.parking_wheel_steering(0);
    main_motor.motor_backward(60);
    delay(5000);

    main_motor.motor_hold(); // 주차 성공
    delay(3000);

    steering_motor.parking_wheel_steering(-30);
    main_motor.motor_forward(80);
    delay(10000);
    steering_motor.parking_wheel_steering(0);
    delay(5000);
    main_motor.motor_hold();
    delay(10000);
}


void loop() {
    // do nothing
}

