#include <Arduino.h>
#include "Motor_Control.h"

MainMotor main_motor;
SteeringMotor steering_motor;

String inputString = "";
String prev;

bool stringcomplete = false;
bool stringstart = false;
bool firstobs = false;
bool firstline = true;
int angle = 0;
long startTime = -10000;

void setup() 
{
    Serial.begin(115200); // 시리얼 모니터 연결
    main_motor.motor_forward(100);
}

void loop() { 

    while(Serial.available()){
        char inchar = (char)Serial.read();
        switch(inchar){
            case 'o' : 
                stringstart = true;
                break;

            case '\n': 
                stringcomplete = true;
                break;

            case 'r' : // 빨간불 정지
                main_motor.motor_hold(); 
                break;

            case 'g' : // 초록불 출발
                main_motor.motor_forward(80); 
                break;

            case 'x' : // 첫번째 장애물
                startTime = millis();
                main_motor.motor_forward(80);
                angle = 25;
                firstobs = true;
                firstline = false;
                break;
            
            case 'y' : // 첫번째 장애물 지속
                angle = 25;
                break;
            
            case 'z' : // 두번째 장애물
                startTime = millis();
                main_motor.motor_forward(80);
                angle = -25;
                firstobs = false;
                firstline = true; 
                break;

            default : 
                if(stringcomplete == false){
                    inputString += inchar;
                }
                break;
        }
    }

    if(stringcomplete == true && stringstart == true){
        if(millis() - startTime >= 6500){
            if(firstline){
                angle = inputString.toInt();
            }
            else{
                angle = 0;
            }
        }
        else if(millis() - startTime >= 4000){
            if(firstobs){
                angle = -25;
            }
            else{
                angle = 25;
            }
        }
    }
    
    steering_motor.setpoint = angle;
    steering_motor.read_angle();
    steering_motor.wheel_steering();
    Serial.println(millis() - startTime);

    inputString = "";
    stringcomplete = false;
    stringstart = false;
}