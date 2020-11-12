// konstanter för att ange pin för inkoppling
/////////////////////////
// för styrning av H-brygga - L293D
// https://sv.wikipedia.org/wiki/H-brygga
// https://www.engineersgarage.com/stm32/l293d-pin-description-and-working/
// http://www.robotplatform.com/howto/L293/motor_driver_1.html
/////////////////////////////
// för styrnina av motor framåt och bakåt
const int controlPinToIC7 = 2;
const int controlPinToIC2 = 3;
// för styrning av motor av och på
const int enablePin = 9;

// nedre strömbrytaren i figuren
const int directionSwitchPin = 4;
// övre strömbrytaren i figuren
const int onOffSwithStateSwitchPin = 5;
// vridpotentiometern kopplas till denna analog in
const int potPin = A0;

// variabler för läsning och styrning
///////////////////////
// strömbrytare nere (1) och uppe (0)
int onOffSwitchState = 0;
// strömbrytaren nere (1) framåt och uppe (0) bakåt
int directionSwitchState = 0;
// för att minnas den övre strömbrytarens läge i föregående varv i loopen
int previousOnOffSwitchState = 0;
// för att minnas den nedre strömbrytarens läge i föregående varv i loopen
int previousDirectionSwitchState = 0;
// om motorn är av (0) eller på (1). Styrs av övre strömbrytaren.
int motorEnabled = 0;
// motorns börvärde - önskad hastighet: 0 - 255
int motorSpeed = 0;
// motorns rotationsrikting (1) moturs och (0) medurs
// styrs av nedre knappen
int motorDirection = 1;

// koden i funktionen setup körs en gång vid uppstart
void setup() {
  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffSwithStateSwitchPin, INPUT);
  pinMode(controlPinToIC7, OUTPUT);
  pinMode(controlPinToIC2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);
}

// koden i funktionen loop körs om och om igen
void loop() {
  onOffSwitchState = digitalRead(onOffSwithStateSwitchPin);
  delay(1);
  directionSwitchState = digitalRead(directionSwitchPin);
  motorSpeed = analogRead(potPin) / 4; // map [0 - 1023] to [0 - 255]
  
  // om övre tryckknappen bytt läge till nedtryckt
  if (onOffSwitchState != previousOnOffSwitchState 
      && onOffSwitchState == HIGH)
  {
    // byt värde från 0 till 1 eller tvärt om
    motorEnabled = !motorEnabled;
  }
  
  // om nedre tryckknappen bytt läge till nedtryckt
  if (directionSwitchState != previousDirectionSwitchState
      && directionSwitchState == HIGH)
  {
    // byt värde från 0 till 1 eller tvärt om
    motorDirection = !motorDirection;
  }
  
  if (motorDirection == 1)
  {
    // motor roterar moturs
    digitalWrite(controlPinToIC7, HIGH);
    digitalWrite(controlPinToIC2, LOW);
  }
  else
  {
    // motor roterar medurs
    digitalWrite(controlPinToIC7, LOW);
    digitalWrite(controlPinToIC2, HIGH);
  }
  if (motorEnabled == 1)
  {
    // motor på
    analogWrite(enablePin, motorSpeed);
  }
  else
  {
    // motor av
    analogWrite(enablePin, 0);
  }
  // minns till nästa varv i loopen
  previousDirectionSwitchState = directionSwitchState;
  previousOnOffSwitchState = onOffSwitchState;
}
