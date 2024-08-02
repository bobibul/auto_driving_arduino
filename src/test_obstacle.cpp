#include <Arduino.h>
#include <SimpleKalmanFilter.h>
#include "Motor_Control.h"

MainMotor main_motor;
Ultrasonic ultrasonic_front(44, 45);
Ultrasonic ultrasonic_right(32, 33);
SteeringMotor steering_motor;
SimpleKalmanFilter kf(2, 2, 150.0);

String inputString = "";
String prev;

bool stringcomplete = false;
bool stringstart = false;
int angle = 0;
float dis_front = 100;
short count = 0;

long startTime = -10000;

void setup() 
{
    Serial.begin(115200); // 시리얼 모니터 연결
    main_motor.motor_forward(40);
}

void loop() {
    dis_front = kf.updateEstimate(ultrasonic_front.ultrasonic_distance());
    ultrasonic_right.ultrasonic_distance();

    count++;
    if(count >= 3){
        Serial.println(dis_front); 
        count = 0;
    }

 
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
                main_motor.motor_forward(100); 
                break;

            case 'x' :
                startTime = millis();
                //main_motor.motor_forward(40);
                angle = 25;
                break;
            
            case 'y' : 
                angle = 25;
                break;
            
            case 'z' : 
                startTime = millis();
                //main_motor.motor_forward(40);
                angle = -25;
                break;

            default : 
                if(stringcomplete == false){
                    inputString += inchar;
                }
                break;
        }
    }

    if(stringcomplete == true && stringstart == true && millis() - startTime >= 4000){
        angle = inputString.toInt();    
    }
    
    steering_motor.setpoint = angle;
    steering_motor.read_angle();
    steering_motor.wheel_steering();

    inputString = "";
    stringcomplete = false;
    stringstart = false;
}