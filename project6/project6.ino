// variabel för att spara fotoresistorns värde
int sensorValue;
// högsta och lägsta avlästa sensorvärde vid kalibrering
// kommer att vara lägsta avlästa värdet vid kalibrering
int sensorLow = 1023; 
// kommer at vara högsta avlästa värdet vid kalibrering
int sensorHigh = 0;

// inbyggd led på Arduinon är kopplad till pin 13
const int ledPin = 13;


// koden i setup körs en gång vid programstart
void setup() 
{
  pinMode(ledPin, OUTPUT);
  // för att indikera att kalibrering pågår
  digitalWrite(ledPin, HIGH);
  // kalibrera instrumentet under 5000 millisekunder
  // handen förs nära fotoresistorn och långt ifrån
  while (millis() < 5000)
  {
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh)
    {
      sensorHigh = sensorValue;
    }
    else if (sensorValue < sensorLow)
    {
      sensorLow = sensorValue;
    }
  }
  // släck led för att visa att kalibreringen är avslutad
  digitalWrite(ledPin, LOW);
}

// koden i loop körs om och om igen
void loop() 
{
  // läs av fotoresistorn
  sensorValue = analogRead(A0);
  // översätt avläst värde till frekvens att spela
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  // spela ton på pinne 8
  // med frekvensen pitch
  // med tonens längd i millisekunder
  tone(8, pitch, 20);

  // paus
  delay(10);
}
