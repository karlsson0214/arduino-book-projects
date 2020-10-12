
// vektor (eng. array) med 4 platser
// fyra variabler i en
int notes [4];

// koden i setup körs en gång vid start av programmet
void setup() {
  // frekvenser i herts (Hz), antal svängningar per sekund
  notes[0] = 262;  // C
  notes[1] = 294; // D
  notes[2] = 330; // E
  notes[3] = 349; // F
  Serial.begin(9600);
}

// koden i loop körs om och om igen
void loop() {
  int keyValue = analogRead(A0);
  Serial.println(keyValue);

  if (keyValue == 1023)
  {
    // spela på digital out 8
    // spela C 262 Hz
    tone(8, notes[0]);
  }
  // OBS, intervallet kan behöva förstoras
  // toleransen på motstånden kan vara för stor
  // 990 <= keyvalue <= 1010
  else if (990 <= keyValue && keyValue <= 1010)
  {
    tone(8, notes[1]); 
  }
  // 505 <= keyvalue <= 515
  else if (505 <= keyValue && keyValue <= 515)
  {
    tone(8, notes[2]); 
  }
  // 5 <= keyvalue <= 15
  else if (5 <= keyValue && keyValue <= 15)
  {
    tone(8, notes[3]); 
  }
  else
  {
    // ingen knapp nedtryckt
    // ska vara tyst
    noTone(8);
  }
}
