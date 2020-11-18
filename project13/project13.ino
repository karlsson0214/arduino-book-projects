#include <CapacitiveSensor.h>
// mer information: https://www.arduino.cc/reference/en/libraries/capacitivesensor/
// skapa en representation av en kapacitiv sensor som kopplas till pin 4 och 2
CapacitiveSensor capSensor = CapacitiveSensor(4, 2);
// tröskelvärde för att lysdiod ska tändas
// välj så att det är större än värden då sensorn inte vidrörs
// välj så att det är mindre an värden så sensor vidrörs
int threshold = 1000;
const int ledPin = 12;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  // Avläs sensorn 30 gånger och separa ett medelvärde.
  long sensorValue = capSensor.capacitiveSensor(30);
  Serial.println(sensorValue);

  if (sensorValue > threshold)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
  delay(10);
}
