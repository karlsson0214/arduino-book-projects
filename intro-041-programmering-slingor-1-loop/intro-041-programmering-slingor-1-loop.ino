// global variabel 
// finns i setup och loop
int i = 1;

void setup() {
  Serial.begin(9600);
}

// skriv ut 1, 2, 3
// funktionen loop anropas om och om igen av Arduinon
void loop() {
  if (i < 4)
  {
    Serial.println(i);
    i = i + 1;
  }
}
