// #include <Arduino.h>
// #include "Motor_Control.h"

// void setup() 
// {
//     Serial.begin(9600);
//     SteeringMotor steeringmotor;
//     MainMotor mainmotor;
//     Ultrasonic ultrasonic_front(44, 45);
//     Ultrasonic ultrasonic_left(40, 42);
//     Ultrasonic ultrasonic_right(42, 43);
//     mainmotor.motor_forward(30);
//     bool flag = true;
//     steeringmotor.read_angle();
//     steeringmotor.wheel_steering();

//     while(1){
//         // if(Serial.available()){
//         //     steeringmotor.target_angle = Serial.parseInt();
//         // }

//         // else{
//         //     // do nothing
//         // }
//         // steeringmotor.read_angle();
//         // steeringmotor.wheel_steering();
//         float dis = ultrasonic_front.ultrasonic_distance();
//         Serial.println(dis);
//         if(dis < 50 && dis != 0 && flag){
//             steeringmotor.target_angle = 30;
//             mainmotor.motor_forward(30);
//             steeringmotor.read_angle();
//             steeringmotor.wheel_steering();
//             Serial.print("hi");
//             delay(9000);
//             steeringmotor.target_angle = 0;
//             mainmotor.motor_forward(30);
//             steeringmotor.read_angle();
//             steeringmotor.wheel_steering();
//             flag = false;
//         }
        
//         // Serial.print("cur_angle : ");
//         // Serial.print(steeringmotor.cur_angle);
//         // Serial.print("  target_angle : ");
//         // Serial.print(steeringmotor.target_angle);
//         // Serial.print("  output : ");
//         // Serial.println(steeringmotor.output);
//     }

  
  

// }
// void loop() {

//     // int value; // 왼쪽 -> 오른쪽 값 증가, 중간 약 120으로
//     // value = analogRead(ENCODER) / 4;
//     // Serial.println(value);
//     // delay(200);

//     // analogWrite(STEERING_MOTOR_IN1, 200);steeringmotor
//     // analogWrite(STEERING_MOTOR_IN2, LOW);
//     // delay(1000);    
//     // analogWrite(STEERING_MOTOR_IN1, LOW);
//     // analogWrite(STEERING_MOTOR_IN2, 200);
//     // delay(1000);

//     // analogWrite(MAIN_MOTOR_1_IN1, 50);
//     // analogWrite(MAIN_MOTOR_1_IN2, LOW);
//     // analogWrite(MAIN_MOTOR_2_IN1, 50);
//     // analogWrite(MAIN_MOTOR_2_IN2, LOW);
//     // delay(1000);


// }
