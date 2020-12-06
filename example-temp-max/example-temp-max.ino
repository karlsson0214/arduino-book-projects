// programkörningen börjar här
// avläs temperaturgivaren på denna pin
const int tempPin = A0;
// variabel för att spara maximal temperatur
float maxTemp = -273;

// funktionen setup körs en gång
void setup()
{
  // initiera överföring till datorn från Arduinon
  // överföringshastighet 9600 ettor eller nollor per sekund
  Serial.begin(9600);
}

// funktionen loop körs om och om igen
void loop()
{
  // lokal variabel för att spara sensorvärdet
  // kan läsa i intervallet 0 - 1023
  int sensorVal;
  // avläs sensorvärde
  sensorVal = analogRead(tempPin);

  // 125C motsvarar 358
  // -40C motsvarar 174
  // 100C motsvarar 309
  // 309 - 104 = 205 blir 2.05 i formeln nedan
  // 0C motsvarar 104, därför -104 i formeln nedan
  
  // omvandla till grader
  float temp = (sensorVal - 104) / 2.05;
  
  // om ny maximal temperatur, spara den
  if (temp > maxTemp)
  {
    maxTemp = temp;
  }
  
  // Utskrift till datorn
  Serial.print("Sensor value: ");
  Serial.println(sensorVal);
  Serial.print("temperatur: ");
  Serial.print(temp);
  Serial.println("C");
  Serial.print("max: ");
  Serial.print(maxTemp);
  Serial.println("C");
  
  // pausa körningen här i 500 millisekunder
  // Vill inte få så många utskrifter på datorn
  delay(500);
}
