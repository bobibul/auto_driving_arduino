#include <Arduino.h>
#include "Mission.h"
#include "Motor_Control.h"

void mission1(MainMotor main_motor, SteeringMotor steering_motor){
    while(true){
        main_motor.motor_forward(100);
        steering_motor.wheel_steering();
    } 
    return;
};

void mission2(MainMotor main_motor, SteeringMotor steering_motor){
    return;
};

void mission3(MainMotor main_motor, SteeringMotor steering_motor){
    return;
};

