

#include<SoftwareSerial.h>
#include<Servo.h>

#define TxD 3
#define RxD 2
#define LED_PIN 7
#define HOME_POS 0
#define ON 90
#define OFF 180

SoftwareSerial bluetoothSerial(TxD, RxD); //seetting bluetooth transmission protocol on Serial
Servo flick; //actuator for light

char c;

void setup() {
  bluetoothSerial.begin(9600);
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  flick.attach(9);
  //flick.write(HOME_POS);
  }

void loop() {
  if(bluetoothSerial.available()){
    c = bluetoothSerial.read();
    Serial.println(c);
    if(c=='1'){
      digitalWrite(LED_PIN, HIGH); 
      flick.write(ON);         
    }
    if(c=='0'){
      digitalWrite(LED_PIN, LOW);
      flick.write(OFF);
    }
  }
}
