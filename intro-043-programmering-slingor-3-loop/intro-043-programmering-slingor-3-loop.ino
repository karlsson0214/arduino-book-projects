// global variabel 
// finns i setup och loop
int i = 10;

void setup() {
  Serial.begin(9600);
}

// skriv ut 10, 7, 4, 1
// funktionen loop anropas om och om igen av Arduinon
void loop() {
  if (i > 0)
  {
    Serial.println(i);
    // minska med 3
    i = i - 3;
  }
}
