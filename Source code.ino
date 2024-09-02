#include <Servo.h>

#include <LiquidCrystal.h>

#include <DHT.h>
//#include <DHT_U.h>



#define DHTPIN 2
#define DHTTYPE DHT11

Servo myservo;

LiquidCrystal lcd ={13,12,11,10,9,8};

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
myservo.attach(3);
lcd.begin(20,4);

lcd.print(" TEMP:              ");
lcd.setCursor(0,1);
lcd.print(" HUMD:              ");
lcd.setCursor(0,2);
lcd.print(" LDR1:              ");
lcd.setCursor(0,3);
lcd.print(" LDR2:              ");

}

void loop() {
  // put your main code here, to run repeatedly:
int LDR1 = analogRead(A1);
int LDR2 = analogRead(A2);
int MOIST = analogRead(A2);


lcd.setCursor(7,2);
lcd.print(LDR1);

lcd.setCursor(7,3);
lcd.print(LDR2);

lcd.setCursor(7,0);
lcd.print(dht.readTemperature());

lcd.setCursor(7,1);
lcd.print(MOIST);

myservo.write(180);
delay(500);

myservo.write(0);
delay(500);

}
