//Prototype sketch of the smart switch
#include <Servo.h>

void flick(bool lstatus = LOW); //receives a light status and flick the light
const uint8_t sensor = A5; //sensor connected to pin A5

Servo sswitch; //object for the smart switch servo
const uint8_t servo_pin = 3; //digital pin 2 on arduino nano for servo

void setup() {
  // put your setup code here, to run once:
  sswitch.attach(servo_pin);
  Serial.begin(9600);
}

float dB = 0;

void loop() {
  // put your main code here, to run repeatedly:
 dB = analogRead(sensor);
  delay(500);
  Serial.println(dB, DEC);
  //flick();
}


void flick(bool lstatus) {
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
