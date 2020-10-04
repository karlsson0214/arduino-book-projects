// inkludera redan färdigskriven kod för att styra servomotorn
#include <Servo.h>

// variabel för att referera till motorn
Servo myServo;
// mittstiftet på vridpotentiometern kopplas till pin nummer
int potentiometerPin = A0;
// avläst värde på potentiometerns mittstift
int potentiometerValue;
// vinkel på motorns axel
int angle;

// koden i setup körs en gång vid programstart
void setup() {
  // koppla servo till angiven digital output pin nummer
  myServo.attach(9);
  Serial.begin(9600);
}

// koden i loop körs om och om igen
void loop() {
  // möjliga värden med analogRead är 0 - 1023
  potentiometerValue = analogRead(potentiometerPin);
  Serial.print("potentiometer value: ");
  Serial.print(potentiometerValue);

  // mappa avläst värde 0 - 1023 
  // till 0 - 179 grader på motoraxeln
  angle = map(potentiometerValue, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle); // println för att avsluta med ny rad

  myServo.write(angle);
  // pausa 
  delay(15);
}
