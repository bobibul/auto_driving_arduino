#include "Motor_Control.h"
#include "Arduino.h"


MainMotor::MainMotor()
{
    pinMode(MAIN_MOTOR_r_IN1, OUTPUT);
    pinMode(MAIN_MOTOR_r_IN2, OUTPUT);
    pinMode(MAIN_MOTOR_l_IN1, OUTPUT);
    pinMode(MAIN_MOTOR_l_IN2, OUTPUT);
}

void MainMotor::motor_forward(int speed)
{
    this->speed = speed;
    analogWrite(MAIN_MOTOR_r_IN1, speed);
    analogWrite(MAIN_MOTOR_r_IN2, LOW);
    analogWrite(MAIN_MOTOR_l_IN1, speed);
    analogWrite(MAIN_MOTOR_l_IN2, LOW);
}

void MainMotor::motor_backward(int speed)
{
    this->speed = speed;
    analogWrite(MAIN_MOTOR_r_IN1, LOW);
    analogWrite(MAIN_MOTOR_r_IN2, speed);
    analogWrite(MAIN_MOTOR_l_IN1, LOW);
    analogWrite(MAIN_MOTOR_l_IN2, speed);
}

void MainMotor::motor_hold(void)
{
    speed = 0;
    analogWrite(MAIN_MOTOR_r_IN1, LOW);
    analogWrite(MAIN_MOTOR_r_IN2, LOW);
    analogWrite(MAIN_MOTOR_l_IN1, LOW);
    analogWrite(MAIN_MOTOR_l_IN2, LOW);
}



SteeringMotor::SteeringMotor() : input(0), output(0), setpoint(0)
{
    pinMode(STEERING_MOTOR_IN1, OUTPUT);
    pinMode(STEERING_MOTOR_IN2, OUTPUT);
}

void SteeringMotor::read_angle(void)
{
    input = (analogRead(A5) - 505) / 4;
}

void SteeringMotor::wheel_steering(void)
{
    output = (setpoint - input);
    
    if(output > 1){
        analogWrite(STEERING_MOTOR_IN1, LOW);
        analogWrite(STEERING_MOTOR_IN2,  80 + output * 3);
    }

    else if(output < -1){
        analogWrite(STEERING_MOTOR_IN1, 80 - output * 3);
        analogWrite(STEERING_MOTOR_IN2, LOW);
    }
    else{
        analogWrite(STEERING_MOTOR_IN1, LOW);
        analogWrite(STEERING_MOTOR_IN2, LOW);
    }
}

void SteeringMotor::parking_wheel_steering(int setpoint)
{
    this->setpoint = setpoint;
    unsigned long startTime = millis();

    while(millis() - startTime < 1500){

        read_angle();
        output = (setpoint - input);

        if(output > 1){
            analogWrite(STEERING_MOTOR_IN1, LOW);
            analogWrite(STEERING_MOTOR_IN2,  80 + output * 3);
        }

        else if(output < -1){
            analogWrite(STEERING_MOTOR_IN1, 80 - output * 3);
            analogWrite(STEERING_MOTOR_IN2, LOW);
        }
        else{
            analogWrite(STEERING_MOTOR_IN1, LOW);
            analogWrite(STEERING_MOTOR_IN2, LOW);
        }
    }

    analogWrite(STEERING_MOTOR_IN1, LOW);
    analogWrite(STEERING_MOTOR_IN2, LOW);
   
}

Ultrasonic::Ultrasonic(int trig, int echo)
{
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    this->trig = trig;
    this->echo = echo;

}

float Ultrasonic::ultrasonic_distance(void)
{
    digitalWrite(trig, LOW);
    digitalWrite(echo, LOW);
    delayMicroseconds(2);

    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH);
    distance = (duration / 2.0) * 0.0344;

    return distance;
}
