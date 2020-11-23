const int ledPins [] = {4, 3, 2};
const int potPin = A0;

void setup()
{
  int i = 0;
  while (i < 3)
  {
    pinMode(ledPins[i], OUTPUT);
    i = i + 1;
  }
  Serial.begin(9600);
}

void loop()
{
  int potValue = analogRead(potPin);
  Serial.print("potentiometer value: ");
  Serial.println(potValue);
  if (0 <= potValue && potValue < 256)
  {
    for (int i = 0; i < 3; i = i + 1)
    {
      digitalWrite(ledPins[i], LOW);
    }
  }
  else if (256 < potValue && potValue < 512)
  {
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], LOW);
    digitalWrite(ledPins[2], LOW);
  }
  else if (512 < potValue && potValue < 768)
  {
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], HIGH);
    digitalWrite(ledPins[2], LOW);
  }
  else 
  {
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], HIGH);
    digitalWrite(ledPins[2], HIGH);
  }
  delay(100);
}
