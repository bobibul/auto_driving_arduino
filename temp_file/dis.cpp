#include <Arduino.h>
#include "Motor_Control.h"
#include "Parking.h"


MainMotor main_motor;
SteeringMotor steering_motor;
Ultrasonic ultrasonic_right(32, 33);

String inputString = "";
String prev;

uint8_t currentSensor = 0;  
long pingTimer = 0;
float dist_r;
int count;




void setup() 
{
    Serial.begin(115200); 
    
}

void loop() {
    if(millis() - pingTimer > 200){
        float dis = ultrasonic_right.ultrasonic_distance();
        if(dis != 0){
            Serial.println(dis);
        }
        pingTimer = millis();
    }
    
}
