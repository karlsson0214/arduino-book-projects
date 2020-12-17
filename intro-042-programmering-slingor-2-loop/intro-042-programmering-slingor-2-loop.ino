// global variabel 
// finns i setup och loop
int i = 3;

void setup() {
  Serial.begin(9600);
}

// skriv ut 3, 5, 7
// funktionen loop anropas om och om igen av Arduinon
void loop() {
  if (i < 8)
  {
    Serial.println(i);
    // öka med två
    i = i + 2;
  }
}
