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
    this->speed = -speed;
    analogWrite(MAIN_MOTOR_r_IN1, LOW);
    analogWrite(MAIN_MOTOR_r_IN2, -speed);
    analogWrite(MAIN_MOTOR_l_IN1, LOW);
    analogWrite(MAIN_MOTOR_l_IN2, -speed);
}

void MainMotor::motor_hold(void)
{
    this->speed = 0;
    analogWrite(MAIN_MOTOR_r_IN1, LOW);
    analogWrite(MAIN_MOTOR_r_IN2, LOW);
    analogWrite(MAIN_MOTOR_l_IN1, LOW);
    analogWrite(MAIN_MOTOR_l_IN2, LOW);
}



SteeringMotor::SteeringMotor() : input(0), output(0), setpoint(0)
{
    motor_pid = new PID(&input, &output, &setpoint, kp, ki, kd, DIRECT);
    pinMode(STEERING_MOTOR_IN1, OUTPUT);
    pinMode(STEERING_MOTOR_IN2, OUTPUT);

    motor_pid->SetMode(AUTOMATIC);
    motor_pid->SetOutputLimits(-255, 255);
    
}

void SteeringMotor::read_angle(void)
{
    cur_angle = (analogRead(A5) - 505) / 4;
    input = target_angle - cur_angle;
}

void SteeringMotor::wheel_steering(void)
{
    motor_pid->Compute();
    if(input < 0){
        analogWrite(STEERING_MOTOR_IN1, output);
        analogWrite(STEERING_MOTOR_IN2, LOW);
    }

    else{
        analogWrite(STEERING_MOTOR_IN1, LOW);
        analogWrite(STEERING_MOTOR_IN2, -output);
    }
}
