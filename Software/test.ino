//Prototype sketch of the smart switch
//Arduino Examples/Sweep
#include <Servo.h>

void light(bool lstatus = LOW); //receives a light status and flick the light


Servo sswitch; //object for the smart switch servo
uint8_t servo_pin = 12; //digital pin 2 on arduino nano for servo

void setup() {
  // put your setup code here, to run once:
  sswitch.attach(servo_pin);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  light();
}


void light(bool lstatus) {
  uint8_t pos = 0;
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    sswitch.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    sswitch.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
