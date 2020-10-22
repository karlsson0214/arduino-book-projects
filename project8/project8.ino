// lutningsbrytaren på pinne nr
const int switchPin = 8;
// tidpunkten då en diod tändes senast
// eller tiden för omstart om timglaset vänds
unsigned long previousTime = 0;
// nuvarande värde på tilt switch i loopen
// 0 eller 1, 
// av eller på, 
// upp eller upp och ner
int switchState = 0;
// föregående värde på tilt switch i loopen
int previousSwitchState = 0;
// vilken led ska tändas härnäst
int nextLedToLit = 2;
// tid från att en diod tänds tills nästa tänds
long interval = 3000;

void setup() {
  // använd följande pinnar till dioder
  // 2, 3, ... , 7
  int ledPin = 2;
  while( ledPin < 8)
  {
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
    ledPin = ledPin + 1;
  }
  // pinne för att läsa tilt switch
  pinMode(switchPin, INPUT);

}

void loop() {
  unsigned long currentTime = millis();
  // har det gått så lång tid att nästa diod ska tändas
  if (currentTime - previousTime > interval)
  {
    // minns nuvarande tid
    previousTime = currentTime;
    // tänd nästa diod
    digitalWrite(nextLedToLit, HIGH);
    // berätta vilken diod som ska tändas härnäst
    nextLedToLit = nextLedToLit + 1;
    if (nextLedToLit == 7)
    {
      // sista lysdioden tänds
      // låt dioderna blinka på något roligt vis
      // t.ex. de tänds och släcks en efter en några gånger
      
      // skriv koden själv
    }
  }
  // läs läget på tilt switch
  switchState = digitalRead(switchPin);
  // Om tilt switch:ens läge har ändrats,
  // så nollställ
  if (switchState != previousSwitchState)
  {
    int ledPin = 2;
    // släck alla dioder
    while(ledPin < 8)
    {
      digitalWrite(ledPin, LOW);
      ledPin = ledPin + 1;
    }
    // första dioden som ska tändas
    nextLedToLit = 2;
    // minns nuvarande tid
    previousTime = currentTime;
  }
  
}
