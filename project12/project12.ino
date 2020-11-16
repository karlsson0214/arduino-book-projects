#include <Servo.h>
Servo myServo;

// anslut komponenter till
const int piezo = A0;
const int switchPin = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;

// styrkan för den svagaste godkända knackningen
const int quietKnock = 10;
// styrkan för den starkaste godkända knackningen
const int loudKnock = 100;

// avläst styrka på knackning
int knockValue;
// uppe: 0 (LOW), nere: 1 (HIGH)
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
  // upplåst kassaskåp vid start
  digitalWrite(greenLed, HIGH);
  myServo.write(0);
  Serial.println("The box is unlocked!");
}

void loop() {
  // upplåst
  if (locked == false)
  {
    switchValue = digitalRead(switchPin);
    // knapp nere medför lås kassaskåpet
    if (switchValue == HIGH)
    {
      locked = true;
      numberOfKnocks = 0;
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      // lås kassaskåpet med hjäl av motorn
      myServo.write(90);
      Serial.println("The box is locked");
      delay(1000);
    }
  }
  // låst
  else 
  {
    knockValue = analogRead(piezo);
    // Färre än 3 knackningar? Och ny knackning.
    if (numberOfKnocks < 3 && knockValue > 0)
    {
      // godkänd knackning?
      if (checkForKnock(knockValue) == true)
      {
        // kom ihåg knackningen
        // totala antalet knackningar
        numberOfKnocks = numberOfKnocks + 1;
      }
      Serial.print(3 - numberOfKnocks);
      Serial.println(" more knocks to go");
    }
    // Minst 3 godkända knackningar?
    if (numberOfKnocks >= 3)
    {
      locked = false;
      // lås upp med hjälp av motorn
      myServo.write(0);
      delay(20);
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      Serial.println("The box is unlocked!");
    }
  }
}
/*
 * Hjälpfunktion
 * Skicka med knackningens styrka.
 * Returnerar true om knackningen är lagom stark, annars false.
 */
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
