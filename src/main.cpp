#include <Arduino.h>
#include "Motor_Control.h"
#include "Mission.h"

MainMotor main_motor;
Ultrasonic ultrasonic_front(44, 45);
Ultrasonic ultrasonic_right(32, 33);
SteeringMotor steering_motor;

String inputString = "";

String prev;
bool stringcomplete = false;
bool stringstart = false;
int angle = 0;

void setup() 
{
    Serial.begin(115200); // 시리얼 모니터 연결
    main_motor.motor_forward(100);
    
}

void loop() {

    while(Serial.available()){
        char inchar = (char)Serial.read();
        Serial.print(inchar);
        if(inchar == 'o'){
            stringstart = true;
        }
        else if(inchar == '\n'){
            stringcomplete = true;
        }

        else if(inchar == 'r'){
            main_motor.motor_hold();
        }

        else if(inchar == 'g'){
            main_motor.motor_forward(100);
        }
        else{
            if(stringcomplete == false){
                inputString += inchar;
            }
        }
    }

    if(stringcomplete == true && stringstart == true){
        angle = inputString.toInt();    
    }
   
    
    steering_motor.setpoint = angle;
    steering_motor.read_angle();
    steering_motor.wheel_steering();
    
    Serial.println(angle);



    // Serial.print("    cur_angle: ");
    // Serial.print(steering_motor.input);
    // Serial.print("  setpoint: ");
    // Serial.print(steering_motor.setpoint);
    // Serial.print("  output: ");
    // Serial.println(steering_motor.output);
    inputString = "";
    stringcomplete = false;
    stringstart = false;
}
