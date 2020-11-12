const int ledPin = 3;
const int potentiometerPin = A0;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  int potentiometerValue; // 0 - 1023
  potentiometerValue = analogRead(potentiometerPin);
  int ledBrightness; //0 - 255
  // värden i intervallet 0 - 1023 
  //omvandlas till värden i intervallet 0 - 255
  ledBrightness = potentiometerValue / 4;
  analogWrite(ledPin, ledBrightness);

  // skriv till datorn för felsökning
  Serial.print("Led brightness (0-255): ");
  Serial.println(ledBrightness);
  
  delay(200);
}
