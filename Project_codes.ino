#include <LiquidCrystal.h>
#include <DHT.h>
#include <Servo.h>

int pos = 0;
#define DHTPIN 3 

#define DHTTYPE DHT11   // DHT 11
Servo myservo;

LiquidCrystal lcd = {13, 12, 11, 10, 9, 8};
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(20,4);

  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);

  digitalWrite(5, HIGH);
  digitalWrite(A0, HIGH);
   myservo.attach(4);

  lcd.clear(); //clear lcd
  lcd.setCursor(0,0); //setcursor position
  lcd.print("===================="); //lcd printing
  lcd.setCursor(0,1);  //setcursor position
  lcd.print(" SOLAR CROP DRYING  "); //lcd printing
  lcd.setCursor(0,2);  //setcursor position
  lcd.print("       SYSTEM      "); //lcd printing
  lcd.setCursor(0,3);  //setcursor position
  lcd.print("===================="); //lcd printing
  delay(1500);
  
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
int ldr=analogRead(A4);
int ldr_=analogRead(A3);
int moist=analogRead(A5);
float h = dht.readHumidity();
float t = dht.readTemperature();

int moist_=map(moist, 0, 1019, 0, 100);
//float f = dht.readTemperature(true);
delay(200);

  

  
  if(moist_<=16 && moist_>=14)
  {
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A1, LOW);

  lcd.clear(); //clear lcd
  lcd.setCursor(0,0); //setcursor position
  lcd.print("===================="); //lcd printing
  lcd.setCursor(0,1);  //setcursor position
  lcd.print("CROPS ALREADY DRIED!"); //lcd printing
  lcd.setCursor(0,2);  //setcursor position
  lcd.print("  REMOVE THE CROPS  "); //lcd printing
  lcd.setCursor(0,3);  //setcursor position
  lcd.print("===================="); //lcd printing
  }

  else
  {
    //lcd.clear(); //clear lcd
  lcd.setCursor(0,0); //setcursor position
  lcd.print("LDR 1:              "); //lcd printing
  lcd.setCursor(0,1);  //setcursor position
  lcd.print("LDR 2:              "); //lcd printing
  lcd.setCursor(0,2);  //setcursor position
  lcd.print("MOIST:              "); //lcd printing
  lcd.setCursor(0,3);  //setcursor position
  lcd.print("TEMP:               "); //lcd printing
  lcd.setCursor(7,0);
  lcd.print(ldr);
  lcd.print("   ");
  lcd.setCursor(7,1);
  lcd.print(ldr_);
  lcd.print("   ");
  lcd.setCursor(7,2);
  lcd.print(moist_);
  lcd.print("%  ");
  lcd.print("   ");
  lcd.setCursor(6,3);
  lcd.print(t);
  lcd.print("C");
  /*
  lcd.setCursor(13,3);
  lcd.print(h);
  lcd.print("%  ");
  */
  
   if(t<35)
{
   digitalWrite(6, HIGH);
   digitalWrite(7, LOW);
   digitalWrite(A2, HIGH);
   digitalWrite(A1, LOW);
}



else
{
   digitalWrite(6, LOW);
   digitalWrite(7, LOW);
   digitalWrite(A2, LOW);
   digitalWrite(A1, LOW);
}


if(ldr>ldr_)
{
  myservo.write(180);
}

if(ldr<=ldr_)
{
  myservo.write(-180);
}
  }



}
