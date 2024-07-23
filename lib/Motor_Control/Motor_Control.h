

#ifndef Main_Motor_h
#define Main_Motor_h

#define STEERING_MOTOR_IN1 2 // 왼쪽 조향
#define STEERING_MOTOR_IN2 3 // 오른쪽 조향

#define MAIN_MOTOR_r_IN1 6
#define MAIN_MOTOR_r_IN2 7

#define MAIN_MOTOR_l_IN1 8
#define MAIN_MOTOR_l_IN2 9

#define ENCODER A5

#include <PID_v1.h>

class MainMotor{
public:
    int speed;
    MainMotor();
    void motor_forward(int speed);
    void motor_backward(int speed);
    void motor_hold(void);
};

class SteeringMotor{
public:
    double kp = 8, ki = 0, kd = 0.1;
    double input, output, setpoint;
    int cur_angle = 0;
    int target_angle = 0;
    PID* motor_pid;

    SteeringMotor();
    void read_angle(void);
    void wheel_steering(void); 
};
#endif