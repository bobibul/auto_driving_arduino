

#ifndef Main_Motor_h
#define Main_Motor_h

#define STEERING_MOTOR_IN1 2
#define STEERING_MOTOR_IN2 3

#define MAIN_MOTOR_1_IN1 6
#define MAIN_MOTOR_1_IN2 7

#define MAIN_MOTOR_2_IN1 8
#define MAIN_MOTOR_2_IN2 9

#define ENCODER A5

#include <PID_v1.h>

class MainMotor{
private:
    int speed;  

public:
    MainMotor();
    void motor_forward(int speed);
    void motor_backward(int speed);
    void motor_hold(void);
};

class SteeringMotor{
private:
    double kp = 1, ki = 0, kd = 0.5;
    double input, output, setpoint;
    PID* motor_pid;

public:
    SteeringMotor();
    void read_encoder(void);
    void wheel_steering(void); 
};
#endif