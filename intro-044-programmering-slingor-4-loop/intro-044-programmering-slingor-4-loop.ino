// global variabel 
// finns i setup och loop
int i = 1;

void setup() {
  Serial.begin(9600);
}

// funktionen loop anropas om och om igen av Arduinon
void loop() {
  Serial.println(i);
  i = i + 1;
}
