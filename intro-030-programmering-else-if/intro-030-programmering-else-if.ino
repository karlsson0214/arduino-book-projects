// koden i funktionen setup körs en gång
void setup() {
  // möjliggör överföring till dator från Arduino
  // överföringshastiheten är 9600 bitar,ettor eller nollor, per sekund
  Serial.begin(9600);

  // för att det inte ska bli samma slumptal
  // varje gång som programmet körs
  randomSeed(analogRead(A0));
  
  // variabel för att spara ett heltal
  int slumptal;
  
  // slumpa tal och spara i variabeln
  // möjliga tal 1, 2, 3, (men inte 4)
  slumptal = random(1, 4); 
  
  if (slumptal == 1)
  {
    Serial.println("");
    Serial.println("  * ");
    Serial.println("");
    Serial.println();
  }
  else if (slumptal == 2)
  {
    Serial.println("*");
    Serial.println("");
    Serial.println("    *");
    Serial.println();
  }
  else
  {
    Serial.println("*");
    Serial.println("  * ");
    Serial.println("    *");
    Serial.println();
  }
}

// används ej i detta exempel, men måste vara med
void loop() {
  // placera kod här som ska göras flera gånger
}
