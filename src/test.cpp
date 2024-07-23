#include <Arduino.h>
#include "Motor_Control.h"

#define STEERING_MOTOR_IN1 2
#define STEERING_MOTOR_IN2 3

#define MAIN_MOTOR_1_IN1 6
#define MAIN_MOTOR_1_IN2 7

#define MAIN_MOTOR_2_IN1 8
#define MAIN_MOTOR_2_IN2 9

#define ENCODER A5

void setup() 
{
    Serial.begin(9600);
    SteeringMotor steeringmotor;
    MainMotor mainmotor;
    mainmotor.motor_forward(30);

    while(1){
        if(Serial.available()){
            steeringmotor.target_angle = Serial.parseInt();
        }

        else{
            // do nothing
        }
        steeringmotor.read_angle();
        steeringmotor.wheel_steering();
        Serial.print("cur_angle : ");
        Serial.print(steeringmotor.cur_angle);
        Serial.print("  target_angle : ");
        Serial.print(steeringmotor.target_angle);
        Serial.print("  output : ");
        Serial.println(steeringmotor.output);
    }

  
  

}
void loop() {

    // int value; // 왼쪽 -> 오른쪽 값 증가, 중간 약 120으로
    // value = analogRead(ENCODER) / 4;
    // Serial.println(value);
    // delay(200);

    // analogWrite(STEERING_MOTOR_IN1, 200);steeringmotor
    // analogWrite(STEERING_MOTOR_IN2, LOW);
    // delay(1000);    
    // analogWrite(STEERING_MOTOR_IN1, LOW);
    // analogWrite(STEERING_MOTOR_IN2, 200);
    // delay(1000);

    // analogWrite(MAIN_MOTOR_1_IN1, 50);
    // analogWrite(MAIN_MOTOR_1_IN2, LOW);
    // analogWrite(MAIN_MOTOR_2_IN1, 50);
    // analogWrite(MAIN_MOTOR_2_IN2, LOW);
    // delay(1000);


}
