#include <LiquidCrystal.h> // hämta fördigskriven kod för LCD
// dokumentation för LiquidCrystal
// https://www.arduino.cc/en/Reference/LiquidCrystal
// lcd är en variabel för att hantera en LiquidCrystal
// Skapar ett objekt som representerar en display.
// Kan sedan "prata" med detta objekt för att styra display:en.
LiquidCrystal lcd = LiquidCrystal(12, 11, 5, 4, 3, 2);

// lutningssensorn (eng. tiltswitch) kopplad till denna pin
const int switchPin = 6;
// om lutningssensorn är på (1) eller av (0)
int switchState = 0;
// för att minnas föregående värde i nästa anrop av loop-funktionen
int previousSwitchState = 0;

// koden i funktionen setup körs en gång vid uppstart
void setup() {
  // antal columner och rader i display:en
  const int numberOfColumns = 16;
  const int numberOfRows = 2;
  // använder punktnotation
  // vem pratar jag med, punkt, vad vill jag att den ska göra
  // syntax: variabel.funktion()
  lcd.begin(numberOfColumns, numberOfRows);
  pinMode(switchPin, INPUT);
  lcd.print("Ask the");
  // byt rad, till rad 1 från rad 0
  lcd.setCursor(0, 1);
  lcd.print("Crystal Ball");
}

// koden i funktionen loop körs om och om igen
void loop() {
  switchState = digitalRead(switchPin);
  if (switchState != previousSwitchState && switchState == LOW)
  {
    // tiltswitch bytt till läge: avbrott
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("The ball says:");
    lcd.setCursor(0, 1);

    // slumpa ett tal 0, 1, 2, ..., eller 7
    int reply = random(8);
    if (reply == 0)
    {
      lcd.print("Yes");
    }
    else if (reply == 1)
    {
      lcd.print("Most likely");
    }
    else if (reply == 2)
    {
      lcd.print("Certainly");
    }
    else if (reply == 3)
    {
      lcd.print("Outlook good");
    }
    else if (reply == 4)
    {
      lcd.print("Unsure");
    }
    else if (reply == 5)
    {
      lcd.print("Ask again");
    }
    else if (reply == 6)
    {
      lcd.print("Doubtful");
    }
    else if (reply == 7)
    {
      lcd.print("No");
    }
  }
  previousSwitchState = switchState;
}
