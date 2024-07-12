#include "Arduino.h"
#include "Motor_Control.h"





void setup_motor(void)
{
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(MAIN_MOTOR_1_IN1, OUTPUT);
    pinMode(MAIN_MOTOR_1_IN2, OUTPUT);
    pinMode(MAIN_MOTOR_2_IN1, OUTPUT);
    pinMode(MAIN_MOTOR_2_IN2, OUTPUT);
    pinMode(STEERING_MOTOR_IN1, OUTPUT);
    pinMode(STEERING_MOTOR_IN2, OUTPUT);
}


void motor_forward(int speed)
{
    analogWrite(MAIN_MOTOR_1_IN1, speed);
    analogWrite(MAIN_MOTOR_1_IN2, LOW);
    analogWrite(MAIN_MOTOR_2_IN1, LOW);
    analogWrite(MAIN_MOTOR_2_IN2, speed);
}

void motor_backward(int speed)
{
    analogWrite(MAIN_MOTOR_1_IN1, LOW);
    analogWrite(MAIN_MOTOR_1_IN2, speed);
    analogWrite(MAIN_MOTOR_2_IN1, speed);
    analogWrite(MAIN_MOTOR_2_IN2, LOW);
}

void motor_hold(void)
{
    analogWrite(MAIN_MOTOR_1_IN1, LOW);
    analogWrite(MAIN_MOTOR_1_IN2, LOW);
    analogWrite(MAIN_MOTOR_2_IN1, LOW);
    analogWrite(MAIN_MOTOR_2_IN2, LOW);
}


int read_encoder(void)
{
    return analogRead(A5) / 4;
}

void wheel_steering(void)
{
    
}