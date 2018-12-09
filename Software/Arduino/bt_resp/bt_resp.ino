//Designed to run on Arduino Mega 2560
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <Servo.h>

#define TxD 3
#define RxD 2
#define LED_PIN 27
#define HOME_POS 0
#define ON 90
#define OFF 180
#define SERVO 4
#define BAUD 9600
//LCD definitions
#define EN 23
#define RS 25
#define D4 28
#define D5 26
#define D6 24
#define D7 22


SoftwareSerial bluetoothSerial(TxD, RxD); //seetting bluetooth transmission protocol on Serial
Servo flick; //actuator for light
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

char bt_data;
void lcd_print_cmd(String cmd,uint8_t line = 1);

void setup() {
  lcd.begin(16, 2);
  bluetoothSerial.begin(BAUD);
  Serial.begin(BAUD);
  pinMode(LED_PIN, OUTPUT);
  flick.attach(SERVO);
  //flick.write(HOME_POS);
  lcd.setCursor(0, 0);
  lcd.print("Voice Command:");
  }

void loop() {
  if(bluetoothSerial.available()){
    bt_data = bluetoothSerial.read();
    Serial.println(bt_data);
    if(bt_data=='1'){
        lcd_print_cmd("ON");
      digitalWrite(LED_PIN, HIGH); 
      flick.write(ON);         
    }
    if(bt_data=='0'){
        lcd_print_cmd("OFF");
      digitalWrite(LED_PIN, LOW);
      flick.write(OFF);
    }
  }
}


void lcd_print_cmd(String cmd, uint8_t line) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Voice Command:");
    lcd.setCursor(0, line);
    lcd.print(cmd);
}
