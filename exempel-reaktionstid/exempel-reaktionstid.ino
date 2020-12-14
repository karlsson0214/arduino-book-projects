const int START = 0;
const int WAIT = 1;

long startTime = 0;
int state = 0;

void setup()
{
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop()
{

  if (state == START)
  {
    digitalWrite(2, HIGH);
    int delayTime = random(3000, 6000);
    Serial.println("random wait");
    delay(delayTime);
    digitalWrite(2, LOW);
    Serial.println("press now");
    startTime = millis();
    state = WAIT;
  }
  else if (state == WAIT)
  {
    // pressed
    if (digitalRead(4) == HIGH)
    {
      long endTime = millis();
      long time = endTime - startTime;
      Serial.print("Your time: ");
      Serial.print(time);
      Serial.println(" ms");
      Serial.println("blink");
      // blink
      for (int i = 0; i < 5; i = i + 1)
      {
        delay(300);
        digitalWrite(2, HIGH);
        delay(300);
        digitalWrite(2,LOW);
      }
      state = START;
    }
  }
  
}
