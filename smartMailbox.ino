#include <NewPing.h> //For Ultrasonic sensor HC-SR07
#include <LiquidCrystal.h> //For 16*2 LCD 

int dist;
int count=0; 
int ledPin=7; //Pin for LED
int buzz=4; //Buzzer pin

NewPing sonar(0,13,400); //Pins attached to arduino from sensor (Trigger,Echo,Max_Distance)
LiquidCrystal lcd(12,11,5,4,3,2); //Pins attched to arduino from LCD

void setup() {
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  pinMode(buzz,OUTPUT);
  lcd.begin(16,2);
}

void loop() {
int ind;
lcd.setCursor(0,0);
  dist=sonar.ping_cm(); //Get the distance in cm
  delay(250);
  if(dist<=4) //Checking for obstruction within a range
  {ind=1;
    goto let;}
  else
  {ind=0;}
  let: if(ind==1) //Alert if Letter is detected
  {count++; //Letter Count
  digitalWrite(ledPin,HIGH);
  digitalWrite(buzz,HIGH);
  delay(50);
  digitalWrite(ledPin,LOW);
  digitalWrite(buzz,LOW);
  delay(50);
  lcd.print(millis() / 1000);
  lcd.print("Number of letters: ");
  lcd.println(count);
  }
}
