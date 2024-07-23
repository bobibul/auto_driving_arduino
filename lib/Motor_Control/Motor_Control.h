

#ifndef Main_Motor_h
#define Main_Motor_h

#define STEERING_MOTOR_IN1 2 // 왼쪽 조향
#define STEERING_MOTOR_IN2 3 // 오른쪽 조향

#define MAIN_MOTOR_r_IN1 6
#define MAIN_MOTOR_r_IN2 7

#define MAIN_MOTOR_l_IN1 8
#define MAIN_MOTOR_l_IN2 9


#define ENCODER A5

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
    int input, output, setpoint;

    SteeringMotor();
    void read_angle(void);
    void wheel_steering(void); 
};

class Ultrasonic{
public:
    int trig, echo;
    long distance, duration;

    Ultrasonic(int trig, int echo);
    float ultrasonic_distance(void);
};

#endif