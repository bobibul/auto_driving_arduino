

#ifndef Car_Lib_h
#define Car_Lib_h

#define STEERING_MOTOR_IN1 2
#define STEERING_MOTOR_IN2 3

#define MAIN_MOTOR_1_IN1 6
#define MAIN_MOTOR_1_IN2 7

#define MAIN_MOTOR_2_IN1 8
#define MAIN_MOTOR_2_IN2 9

#define ENCODER = A5

int read_encoder(void);
void setup_motor(void);
void motor_forward(int speed);
void motor_backward(int speed);
void motor_hold(void);
void wheel_steering(void);


#endif