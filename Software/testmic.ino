#include <Servo.h>


// Define hardware connections
#define PIN_GATE_IN 2
#define IRQ_GATE_IN 0

#define PIN_LED_OUT 13
#define PIN_ANALOG_IN A0
int pin_analog_in = A0;

// soundISR()
// This function is installed as an interrupt service routine for the pin
// change interrupt. When digital input 2 changes state, this routine
// is called.
// It queries the state of that pin, and sets the onboard LED to reflect that
// pin's state.

void soundISR() {
  int pin_val;
  //pin_val = digitalRead(PIN_GATE_IN);
  //digitalWrite(PIN_LED_OUT, pin_val);
}

Servo sswitch; //object for the smart switch servo
const uint8_t servo_pin = 3; //digital pin 2 on arduino nano for servo

void setup() {
Serial.begin(9600);
// Configure LED pin as output
pinMode(PIN_LED_OUT, OUTPUT);
// configure input to interrupt
pinMode(PIN_GATE_IN, INPUT);
attachInterrupt(IRQ_GATE_IN, soundISR, CHANGE);
sswitch.attach(servo_pin);
// Display status
//Serial.println("Initialized");
delay(5000);
}

void loop() {
int value;
// Check the envelope input
value = analogRead(pin_analog_in);
// Convert envelope value into a message
fix_axis();
Serial.println(value);
//Serial.print("Status: ");
  
  if(value > 550) {
    pin_analog_in = A1;
    //Serial.println("Quiet.");
    flick(true);
    delay(5000);
    pin_analog_in = A0;
  }

  value = 0;
// pause for 1 second
//delay(1000);
}

void flick(bool lstatus) {
  uint8_t pos = 0;
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    sswitch.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(5000);
}

void fix_axis() {
  Serial.print(0);
  Serial.print(" ");
  Serial.print(1023);
  Serial.print(" ");
}
