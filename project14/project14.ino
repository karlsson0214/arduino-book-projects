// programidé
// avläs potentiometerns värde och skicka seriellt till datorn

void setup() {
  // ange att Arduinon och datorn ska utbyta data med hastigheten 
  // 9600 bitar per sekund. En bit är en etta eller nolla.
  Serial.begin(9600);
}

void loop() {
  // analogRead ger värden i intervallet 0 - 1023
  // write kan bara ta värden i intervallet 0 - 255
  // därför delar vi med 4
  // 2^8 = 256
  // 8 bitar skickas vid ett anrop av funktionen write
  Serial.write(analogRead(A0)/4);
  /* 
  // kod för felsökning
  for (int i = 0; i < 256; i = i + 8)
  {
    Serial.write(i);
    delay(300);
  }
  */

  // pausa körningen i 1 millisekund
  // för att ADC Analog till Digital omvandlaren (eng. Converter)
  // ska hinna med
  delay(100);
}
