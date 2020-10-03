// konstanter som inte kan ändra värde
// digital output pin nummer som LED kopplas till
const int greenLEDPin = 9;
const int redLEDPin = 11;
const int blueLEDPin = 10;

// analog input pin som fotoresistorerna kopplas till
const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

// variabler för färgvärden till LED
// 0 inget ljus, 255 fullt ljus
int redLEDValue = 0; 
int greenLEDValue = 0;
int blueLEDValue = 0;

// variabler för avlästa värden från de tre 
// fotoresistorerna
int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

// koden körs en gång vid uppstart
void setup() {
  Serial.begin(9600);

  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}

// koden i loop upprepas om och om igen
void loop() {
  // avläs värden på pinnarna som kopplts till fotoresistorer
  // analoga värden omvandlas till digitala: 0 - 1023
  redSensorValue = analogRead(redSensorPin);
  // vänta så att analog- till digital-omvandlaren (ADC)
  // blir klar med beräkningen
  delay(5); 
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);

  // skicka värden för utskrift på datorns skärm
  Serial.print("Raw sensor values \t Red: ");
  Serial.print(redSensorValue);
  Serial.print("\t Green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t Blue: ");
  Serial.print(blueSensorValue);

  // beräkna värden till LED
  // 0 - 1023 mappas till intervallet 0 - 255
  redLEDValue = redSensorValue / 4;
  greenLEDValue = greenSensorValue / 4; 
  blueLEDValue = blueSensorValue / 4;

  // skicka beräknade värden för utskrift på datorns skärm
  Serial.print("Mapped sensor values \t Red: ");
  Serial.print(redLEDValue);
  Serial.print("\t Green: ");
  Serial.print(greenLEDValue);
  Serial.print("\t Blue: ");
  Serial.print(blueLEDValue);

  // skicka beräknade värden till LED
  analogWrite(redLEDPin, redLEDValue);
  analogWrite(greenLEDPin, greenLEDValue);
  analogWrite(blueLEDPin, blueLEDValue);
}
