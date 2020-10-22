// strömbrytaren kopplas till denna digital out
const int switchPin = 2;

// MOSFET - transistorn styrs med denna digital out
// transistorn fungerar som en strömbrytare för motorn
const int motorPin = 9;

// strömbrytaren nere (1) eller uppe (0)
int switchState = 0;

// funktionen setup körs en gång vid uppstart 
void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
}

// koden i funktionen loop körs om och om igen
void loop() {
  // avläs strömbrytarens läge upp (0) ner (1)
  switchState = digitalRead(switchPin);

  // om strömbrytaren är nere
  if (switchState == HIGH)
  {
    // kör motor
    digitalWrite(motorPin, HIGH);
  }
  else
  {
    // ingen ström till motorn
    digitalWrite(motorPin, LOW);
  }

}
