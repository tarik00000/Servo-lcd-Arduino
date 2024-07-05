#include <LiquidCrystal_I2C.h> // Library for LCD
#include <Servo.h> // Servo Control using the Arduino Servo Library

int btnL = 9; // btn for left side 
int ledL = 8; // led for left side(blue led)
int btnR = 10; // btn for right side
int ledR = 11; //led for right side(red led)
int val; // valute for servo  
Servo s1; // the name of servo
LiquidCrystal_I2C lcd(0x27,16,2); // I2C address 0x27, 16 column and 2 rows

void setup() { 
  s1.attach (3); // pin for servo
  pinMode(ledL, OUTPUT); // blue led (left) set to output
  pinMode(btnL, INPUT); // left btn set to input
  pinMode(ledR, OUTPUT); // red led (right) set to output
  pinMode(btnR, INPUT);  // right btn set to input
  lcd.init(); // initialize the lcd 
  lcd.backlight(); // turn on backlight.
}

void loop() {
             delay(100); // delay 100s
            if (digitalRead(btnR) == 1){ // if the right button is pressed
            digitalWrite(ledR, 1); // turn on the red led 
            digitalWrite(ledL, 0); // turn off the blue led
            s1.write(1); // servo will go to 1
            lcd.clear(); // clear the lcd
            lcd.setCursor(3,0); // set cursor where text will be shown
            lcd.print("SERVO RIGHT"); // text that will be shown if the right button is pressed
            delay(100); // delay 100s
          } // the end of if command
          else if(digitalRead(btnL) == 1){ //if left button is pressed
            digitalWrite(ledL, 1); //turn on the blue led
            digitalWrite(ledR, 0); // turn off the red led
            s1.write(180); // servo will go to 180
            lcd.clear(); // clear the lcd
            lcd.setCursor(3,0); // set cursor where text will be shown
            lcd.print("SERVO LEFT"); // text that will be shown if the left button is pressed
  } // the end of if command
      else { // if noting is pressed 
            digitalWrite(ledL, 0); // turn off the blue led
            digitalWrite(ledR, 0); // turn off the red led
            s1.write(95); // servo will go to 95
            lcd.clear(); // clear the lcd
            lcd.setCursor(3,0); // set cursor where text will be shown
            lcd.print("SERVO OFF"); // text that will be shown if nothing is pressed
            lcd.setCursor(2,1); // set cursor where text will be shown
            lcd.print("MADE BY TaPo"); // text that will be shown if nothing is pressed

          } // the end of else command
           } // THE END - Made by TaPo