// koden i funktionen setup körs en gång
void setup() {
  // möjliggör överföring till dator från Arduino
  // överföringshastiheten är 9600 bitar,ettor eller nollor, per sekund
  Serial.begin(9600);

  randomSeed(analogRead(A0));

  // variabel för att spara ett heltal
  int slumptal;
  
  // slumpa tal och spara i variabeln
  // möjliga tal 0, 1, (men inte 2)  
  slumptal = random(2); 
  
  if (slumptal == 0)
  {
    Serial.println("krona");
  }
  else 
  {
    Serial.println("klave");
  }
}

// används ej i detta exempel, men måste vara med
void loop() {
  // placera kod här som ska göras flera gånger
}
