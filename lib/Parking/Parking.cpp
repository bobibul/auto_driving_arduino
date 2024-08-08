#include "Parking.h"
#include "Motor_Control.h"

void parking(char mission_num, MainMotor main_motor, SteeringMotor steering_motor){
    switch(mission_num){
        case '1':
            delay(3500);
            main_motor.motor_hold();
            delay(500);

            steering_motor.parking_wheel_steering(30);
            main_motor.motor_forward(80);
            delay(5000);
            main_motor.motor_hold();
            delay(500);

            steering_motor.parking_wheel_steering(-25);
            main_motor.motor_backward(60);
            delay(5000);
            main_motor.motor_hold();
            steering_motor.parking_wheel_steering(0);
            main_motor.motor_backward(60);
            delay(10000);

            main_motor.motor_hold(); // 주차 성공
            delay(3000);

            steering_motor.parking_wheel_steering(-25);
            main_motor.motor_forward(80);
            delay(10000);
            steering_motor.parking_wheel_steering(0);
            delay(5000);
            main_motor.motor_hold();
            delay(10000);
            break;

        case '2':
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
            break;

        case '3':
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
            break;

        case '4':
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
            break;
    }
}