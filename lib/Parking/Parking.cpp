#include "Parking.h"
#include "Motor_Control.h"

void parking(char mission_num, MainMotor main_motor, SteeringMotor steering_motor, long stTime){
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
            stTime = millis();
            while(millis() - stTime < 4000){
                steering_motor.setpoint = -25;
                steering_motor.read_angle();
                steering_motor.wheel_steering();
            }
            

            steering_motor.parking_wheel_steering(0);
            stTime = millis();
            while(millis() - stTime < 7000){
                steering_motor.setpoint = 0;
                steering_motor.read_angle();
                steering_motor.wheel_steering();
            }

            main_motor.motor_hold(); // 주차 성공
            delay(3000);

            steering_motor.parking_wheel_steering(-25);
            main_motor.motor_forward(80);
            stTime = millis();
            while(millis() - stTime < 10000){
                steering_motor.setpoint = -25;
                steering_motor.read_angle();
                steering_motor.wheel_steering();
            }
            steering_motor.parking_wheel_steering(0);
            delay(5000);
            main_motor.motor_hold();
            delay(10000);
            break;

        case '2':
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
            stTime = millis();
            while(millis() - stTime < 4000){
                steering_motor.setpoint = -25;
                steering_motor.read_angle();
                steering_motor.wheel_steering();
            }
            

            steering_motor.parking_wheel_steering(0);
            stTime = millis();
            while(millis() - stTime < 7000){
                steering_motor.setpoint = 0;
                steering_motor.read_angle();
                steering_motor.wheel_steering();
            }

            main_motor.motor_hold(); // 주차 성공
            delay(3000);

            steering_motor.parking_wheel_steering(-25);
            main_motor.motor_forward(80);
            stTime = millis();
            while(millis() - stTime < 10000){
                steering_motor.setpoint = -25;
                steering_motor.read_angle();
                steering_motor.wheel_steering();
            }
            steering_motor.parking_wheel_steering(0);
            delay(5000);
            main_motor.motor_hold();
            delay(10000);
            break;
    }
}