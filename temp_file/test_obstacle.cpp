#include <Arduino.h>
#include "Motor_Control.h"



SteeringMotor steeringmotor;
MainMotor mainmotor;
Ultrasonic ultrasonic_front(44, 45);
Ultrasonic ultrasonic_left(40, 42);
Ultrasonic ultrasonic_right(42, 43);

String inputString = "";
String prev;

int flag = 1;
bool stringcomplete = false;
float dis_front, dis_right, dis_left;

void setup() 
{
    Serial.begin(9600);
    mainmotor.motor_forward(30);
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
    dis_front = ultrasonic_front.ultrasonic_distance();
    dis_right = ultrasonic_right.ultrasonic_distance();
    dis_left = ultrasonic_left.ultrasonic_distance();

    if((dis_right < 50 && dis_right != 0) || (dis_left < 50 && dis_left != 0) || (dis_front < 50 && dis_front != 0)){
        if(flag == 1){
            steeringmotor.parking_wheel_steering(-30);
            flag = 2;
        }

        else if(flag == 2){
            steeringmotor.parking_wheel_steering(30);

            flag = 0;
        }
    }
    


}
