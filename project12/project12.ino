#include <Servo.h>
Servo myServo;
const int piezo = A0;
const int switchPin = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;
const int quietKnock = 10;
const int loudKnock = 100;

int knockValue;
int switchValue;
boolean locked = false;
int numberOfKnocks = 0;

void setup() {
  myServo.attach(9);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
  digitalWrite(greenLed, HIGH);
  myServo.write(0);
  Serial.println("The box is unlocked!");
}

void loop() {
  if (locked == false)
  {
    switchValue = digitalRead(switchPin);
    if (switchValue == HIGH)
    {
      locked = true;
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      myServo.write(90);
      Serial.println("The box is locked");
      delay(1000);
    }
  }
  else // locked
  {
    knockValue = analogRead(piezo);
    if (numberOfKnocks < 3 && knockValue > 0)
    {
      if (checkForKnock(knockValue) == true)
      {
        numberOfKnocks = numberOfKnocks + 1;
      }
      Serial.print(3 - numberOfKnocks);
      Serial.println(" more knocks to go");
    }
    if (numberOfKnocks >= 3)
    {
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      Serial.println("The box is unlocked!");
    }
    
  }

}
boolean checkForKnock(int value)
{
  if (quietKnock < value && value < loudKnock)
  {
    digitalWrite(yellowLed, HIGH);
    delay(50);
    digitalWrite(yellowLed, LOW);
    Serial.print("Valid knock value: ");
    Serial.print(value);
    return true;
  }
  else
  {
    Serial.print("Bad knock value: ");
    Serial.println(value);
    return false;

}
}
