// die
// 1
//   0
//     2
const int dotPins [] = {6, 7, 5};

void setup()
{
  pinMode(dotPins[0], OUTPUT);
  pinMode(dotPins[1], OUTPUT);
  pinMode(dotPins[2], OUTPUT);
}

void loop()
{
  if (digitalRead(13) == HIGH)
  {
    animateRoll();
    int numberOfDots = rollDie();
    showDots(numberOfDots);
    delay(3000);  
  }
}
void animateRoll()  
{
  int numberOfPreDisplay = random(7, 12);
  for (int i = 0; i < numberOfPreDisplay; i = i + 1)
  {
    int numberOfDots = rollDie();
    showDots(numberOfDots);
    delay(150);
    hideAllDots();
    delay(150);
  }
}
int rollDie()
{
  return random(1, 4);
}

void showDots(int numberOfDots)
{
  if (numberOfDots == 1)
  {
    digitalWrite(dotPins[0], HIGH);
    digitalWrite(dotPins[1], LOW);
    digitalWrite(dotPins[2], LOW);
  }
  else if (numberOfDots == 2)
  {
    digitalWrite(dotPins[0], LOW);
    digitalWrite(dotPins[1], HIGH);
    digitalWrite(dotPins[2], HIGH);
  }  
  else if (numberOfDots == 3)
  {
    digitalWrite(dotPins[0], HIGH);
    digitalWrite(dotPins[1], HIGH);
    digitalWrite(dotPins[2], HIGH);
  }
}
void hideAllDots()
{
  int index = 0;
  // index: 0, 1, 2
  while (index < 3)
  {
    digitalWrite(dotPins[index], LOW);
    index = index + 1;
  }
                         
}
