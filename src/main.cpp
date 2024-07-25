#include <Arduino.h>
#include "Motor_Control.h"
#include "Mission.h"

MainMotor main_motor;
SteeringMotor steering_motor;

String inputString = "";
bool stringcomplete = false;

void setup() 
{
    Serial.begin(115200); // 시리얼 모니터 연결
    //main_motor.motor_forward(60);
}

void loop() {
    steering_motor.read_angle();
    steering_motor.wheel_steering();

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