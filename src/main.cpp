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

void setup() 
{
    Serial.begin(115200); // 시리얼 모니터 연결
    main_motor.motor_forward(60);
}

void loop() {

    while(Serial.available()){
        char inchar = (char)Serial.read();
        if(inchar == '\n'){
            stringcomplete = true;
        }
        else{
            if(stringcomplete == false){
                inputString += inchar;
            }
        }
    }
    if(inputString == ""){
        inputString = prev;
    }
    int angle = inputString.toInt();
    steering_motor.setpoint = angle;
    Serial.println(angle);

    steering_motor.read_angle();
    steering_motor.wheel_steering();

    // Serial.print("    cur_angle: ");
    // Serial.print(steering_motor.input);
    // Serial.print("  setpoint: ");
    // Serial.print(steering_motor.setpoint);
    // Serial.print("  output: ");
    // Serial.println(steering_motor.output);
    prev = inputString;
    inputString = "";
    stringcomplete = false;
}
