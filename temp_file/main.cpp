#include <Arduino.h>
#include "Motor_Control.h"
#include "Mission.h"

MainMotor main_motor;
Ultrasonic ultrasonic_front(44, 45);
Ultrasonic ultrasonic_right(32, 33);
SteeringMotor steering_motor;

String inputString = "";
bool stringcomplete = false;

void setup() 
{
    Serial.begin(115200); // 시리얼 모니터 연결
    //main_motor.motor_forward(30);
}

void loop() {
    steering_motor.read_angle();
    steering_motor.wheel_steering();
    float dis_front;
    dis_front = ultrasonic_front.ultrasonic_distance(); 
    Serial.print("  dis_front : ");
    Serial.print(dis_front);
    dis_front = ultrasonic_right.ultrasonic_distance(); 
    Serial.print("  dis_right : ");
    Serial.print(dis_front);


    Serial.print("    cur_angle: ");
    Serial.print(steering_motor.input);
    Serial.print("  setpoint: ");
    Serial.print(steering_motor.setpoint);
    Serial.print("  output: ");
    Serial.println(steering_motor.output);

    inputString = "";
    stringcomplete = false;
}


void serialEvent(){
    while(Serial.available()){
        char inchar = (char)Serial.read();
        if(inchar == '\n'){
            stringcomplete = true;
        }
        else{
            inputString += inchar;
        }
    }
    steering_motor.setpoint = inputString.toInt();
}