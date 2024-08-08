#include <Arduino.h>
#include "Motor_Control.h"
#include "Parking.h"

MainMotor main_motor;
SteeringMotor steering_motor;
Ultrasonic ultrasonic_right(32, 33);

String inputString = "";
String prev;

bool stringcomplete = false;
bool stringstart = false;
bool firstobs = false;
bool firstline = true;
bool isRedlight = false;
int angle = 0;
long startTime = -10000;
char mission_num = '0';

void setup() 
{
    Serial.begin(115200); // 시리얼 모니터 연결
    while(true){
        while(Serial.available()){
            mission_num = (char)Serial.read();
        }
        if(mission_num != '0'){
            break;
        }
    }
    if(mission_num == 's'){
        main_motor.motor_forward(50);
    }
    else if(mission_num == 'p'){
        while(true){
            while(Serial.available()){
                mission_num = (char)Serial.read();
            }
            if(mission_num == '1' || mission_num == '2' || mission_num == '3' || mission_num == '4'){
                break;
            }
        }
        main_motor.motor_forward(80);
        while(1){
            if(Serial.available()){
                break;
            }
            // steering_motor.setpoint = 0;
            // steering_motor.read_angle();
            // steering_motor.wheel_steering();
            
        }
        parking(mission_num, main_motor, steering_motor);
    }
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
                isRedlight = true;
                break;

            case 'g' : // 초록불 출발
                if(isRedlight){
                    main_motor.motor_forward(80);
                }
                break;

            case 'x' : // 첫번째 장애물
                startTime = millis();
                main_motor.motor_forward(30);
                angle = 25;
                firstobs = true;
                firstline = false;
                break;
            
            case 'y' : // 첫번째 장애물 지속
                angle = 25;
                break;
            
            case 'z' : // 두번째 장애물
                startTime = millis();
                main_motor.motor_forward(30);
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
        if(millis() - startTime >= 5000){
            angle = inputString.toInt();
        }
        else if(millis() - startTime >= 3500){
            if(firstobs){
                angle = -15;
            }
            else{
                angle = 15;
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