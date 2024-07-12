#include <Arduino.h>
#include "Motor_Control.h"

int cmd;

void setup() {

  setup_motor();

  Serial.begin(9600);
  Serial.println("Arduino Mega connected to Serial monitor!!");

  while(1){
    if(Serial.parseInt() == 1){
      
      motor_forward(100);
      break;
    }

    else{
      // do nothing
    }
  }
  
}

void loop() {

  if(Serial.available()){
        cmd = Serial.parseInt();
        Serial.println(cmd);
    }

}
