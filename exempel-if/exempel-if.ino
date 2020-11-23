const int ledOnePin = 4;
const int ledTwoPin = 3;
const int ledThreePin = 2;
const int potPin = A0;

void setup()
{
  pinMode(ledOnePin, OUTPUT);
  pinMode(ledTwoPin, OUTPUT);
  pinMode(ledThreePin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int potValue = analogRead(potPin);
  Serial.print("potentiometer value: ");
  Serial.println(potValue);
  if (0 <= potValue && potValue < 256)
  {
    digitalWrite(ledOnePin, LOW);
    digitalWrite(ledTwoPin, LOW);
    digitalWrite(ledThreePin, LOW);
  }
  else if (256 < potValue && potValue < 512)
  {
    digitalWrite(ledOnePin, HIGH);
    digitalWrite(ledTwoPin, LOW);
    digitalWrite(ledThreePin, LOW);
  }
  else if (512 < potValue && potValue < 768)
  {
    digitalWrite(ledOnePin, HIGH);
    digitalWrite(ledTwoPin, HIGH);
    digitalWrite(ledThreePin, LOW);
  }
  else 
  {
    digitalWrite(ledOnePin, HIGH);
    digitalWrite(ledTwoPin, HIGH);
    digitalWrite(ledThreePin, HIGH);
  }
  delay(100);
}
