// koden i funktionen setup körs en gång
void setup() {
  // möjliggör överföring till dator från Arduino
  // överföringshastiheten är 9600 bitar,ettor eller nollor, per sekund
  Serial.begin(9600);


  Serial.begin(9600);

  Serial.println("skriv ut 1, 2, 3 med flera rader println");
  Serial.println(1);
  Serial.println(2);
  Serial.println(3);

  Serial.println("med while");

  int i = 1;
  while (i < 4)
  {
    Serial.println(i);
    // öka i med ett
    i = i + 1;
  }

  Serial.println("skriv ut: 3, 5, 7");
  // återanvänd i och ge den värdet 3
  i = 3;
  while (i < 8)
  {
    Serial.println(i);
    // öka i med två
    i = i + 2;
  }

  Serial.println("räkna ner 10, 7, 4, 1");
  // startvärde
  i = 10;
  // medan större än noll
  while (i > 0)
  {
    Serial.println(i);
    // minska med 3
    i = i - 3;
  }

  Serial.println("1, 2, 3 med for");
  for (i = 1; i < 4; i = i + 1)
  {
    Serial.println(i);
  }

  Serial.println("3, 5, 7 med for");
  for (i = 3; i < 8; i = i +2)
  {
    Serial.println(i);
  }

  Serial.println("10, 7, 4, 1 med for");
  for (i = 10; i > 0; i = i - 3)
  {
    Serial.println(i);
  }
}

// används ej i detta exempel, men måste vara med
void loop() {
  // placera kod här som ska göras flera gånger
}
