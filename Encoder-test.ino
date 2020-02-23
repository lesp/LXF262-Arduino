#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

 #define A 6
 #define B 7
 #define motor 9
int counter = 0; 
int aState;
int aLastState;


 void setup() { 
   lcd.init();
   pinMode (A,INPUT);
   pinMode (B,INPUT);
   pinMode(motor, OUTPUT);
   digitalWrite(A, HIGH);
   digitalWrite(B, HIGH);
   lcd.backlight();
   lcd.setCursor(1,0);
   lcd.print("Turn dial to ");
   lcd.setCursor(1,1);
   lcd.print("start motor");
   
   Serial.begin (9600);
   aLastState = digitalRead(A);   
 } 
 void loop() { 
   aState = digitalRead(A);
   if (aState != aLastState){     
     if (digitalRead(B) != aState) { 
       counter ++;
       if (counter > 12){
        counter = 0;
       }
       else if (counter < -1){
        counter = 0;
       }
     } else if (counter > -1) {
       counter --;
     }
     Serial.print("Value: ");
     Serial.println(counter);
     if (counter == 2) {
      Serial.println("Motor On");
      Serial.println("20%");
      lcd.setCursor(1,0);
      lcd.print("Motor On");
      lcd.setCursor(1,1);
      lcd.print("20%");
      analogWrite(motor, 51);
     }
     else if (counter == 4) {
      Serial.println("Motor On");
      Serial.println("40%");
      lcd.setCursor(1,0);
      lcd.print("Motor On");
      lcd.setCursor(1,1);
      lcd.print("40%");
      analogWrite(motor, 102);
     }
     else if (counter == 6) {
      Serial.println("Motor On");
      Serial.println("60%");
      lcd.setCursor(1,0);
      lcd.print("Motor On");
      lcd.setCursor(1,1);
      lcd.print("60%");
      analogWrite(motor, 153);
     }
     else if (counter == 8) {
      Serial.println("Motor On");
      Serial.println("80%");
      lcd.setCursor(1,0);
      lcd.print("Motor On");
      lcd.setCursor(1,1);
      lcd.print("80%");
      analogWrite(motor, 204);
     }
     else if (counter == 10) {
      Serial.println("Motor On");
      Serial.println("100%");
      lcd.setCursor(1,0);
      lcd.print("Motor On");
      lcd.setCursor(1,1);
      lcd.print("100%");
      analogWrite(motor, 255);
     }
     else {
      analogWrite(motor, 0);
      lcd.clear();
     }
   } 
   aLastState = aState;
 }
