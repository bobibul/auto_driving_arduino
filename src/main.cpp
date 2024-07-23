#include <Arduino.h>
#include "Motor_Control.h"
#include "Mission.h"


int inturrupt_setpoint = 0;

void setup() 
{
    MainMotor main_motor;
    SteeringMotor steering_motor;
    Ultrasonic ultrasonic_left(40, 41);
    Ultrasonic ultrasonic_right(42, 43);
    Ultrasonic ultrasonic_front(44, 45);

    Serial.begin(115200); // 시리얼 모니터 연결
    main_motor.motor_forward(50);
    
    while(true){
        
        steering_motor.setpoint = inturrupt_setpoint;
        steering_motor.read_angle();
        steering_motor.wheel_steering();
        // Serial.print("cur_angle: ");
        // Serial.print(steering_motor.input);
        // Serial.print("  setpoint: ");
        // Serial.print(steering_motor.setpoint);
        // Serial.print("  output: ");
        // Serial.println(steering_motor.output);
        
    }
    
}

void loop() {
  // do nothing
}

void serialEvent(){

    inturrupt_setpoint = Serial.parseInt();
    Serial.println("hi");
}