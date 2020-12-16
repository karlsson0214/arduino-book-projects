// koden i funktionen setup körs en gång
void setup() {
  // möjliggör överföring till dator från Arduino
  // överföringshastiheten är 9600 bitar,ettor eller nollor, per sekund
  Serial.begin(9600);

  // variabel för att spara ett heltal
  int slumptal;
  // slumpa tal och spara i variabeln
  // möjliga tal 1, 2, 3, 4, 5, 6, (men inte 7)
  slumptal = random(1, 7); 
  // skriv ut texten: tärningen visar :
  Serial.print("tärningen visar: ");
  // skriv ut talet på datorn i seriell monitor
  Serial.print(slumptal);
  // ny rad på utskrift
  Serial.println();
}

// används ej i detta exempel, men måste vara med
void loop() {
  // placera kod här som ska göras flera gånger
}
