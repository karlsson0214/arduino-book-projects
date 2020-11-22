const int optoPin = 2;

void setup()
{
  pinMode(optoPin, OUTPUT);
}

void loop()
{
  // kod för figur på hemsida
  digitalWrite(optoPin, HIGH);
  delay(500); 
  digitalWrite(optoPin, LOW);
  delay(500); 
}
