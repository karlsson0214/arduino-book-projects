// för att spara om knappen är intryckt eller inte
// 0 - uppe
// 1 - nere
int switchState = 0;

// kod som körs en gång vid start
void setup()
{
    // digitalt stift 3 är output för grön LED
    pinMode(3, OUTPUT); 
    // digitalt stift 4 är output för röd LED
    pinMode(4, OUTPUT); 
    // digitalt stift 5 är output för röd LED
    pinMode(5, OUTPUT); 
    pinMode(1, INPUT);
}

// kod som körs om och om igen
void loop()
{
    switchState = digitalRead(2);

    // LOW har värdet 0
    // HIGH har värdet 1
    if (switchState == LOW)
    {
        // knapp uppe
        digitalWrite(3, HIGH); // grön LED lyser
        digitalWrite(4, LOW); // röd LED släckt
        digitalWrite(5, LOW); // röd LED släckt
    }
    else
    {
        // knapp nere
        digitalWrite(3, LOW); // grön LED släckt
        digitalWrite(4, LOW); // röd LED släckt
        digitalWrite(5, HIGH); // röd LED tänd

        // pausa programkörningen här i 250 ms 
        delay(250);  

        digitalWrite(3, LOW); // grön LED släckt
        digitalWrite(4, HIGH); // röd LED tänd
        digitalWrite(5, LOW); // röd LED släckt

        // pausa programkörningen här i 250 ms 
        delay(250);          
    }
}
