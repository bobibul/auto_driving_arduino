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
    motor_pid->SetOutputLimits(-30, 30);
}

void SteeringMotor::read_angle(void)
{
    input = analogRead(A5) / 4 - 125;
}

void SteeringMotor::wheel_steering(void)
{
    read_angle();

    if(Serial.available() > 0){
        setpoint = Serial.parseInt();
        motor_pid->Compute();
    }

    else{
        // do nothing
    }


    if(output > 0){
        analogWrite(STEERING_MOTOR_IN1, output * RATIO);
        analogWrite(STEERING_MOTOR_IN2, LOW);
    }

    else{
        analogWrite(STEERING_MOTOR_IN1, LOW);
        analogWrite(STEERING_MOTOR_IN2, -output * RATIO);
    }
}
