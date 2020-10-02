// analogt stift som terminstorn kopplas till
const int sensorPin = A0;

// gränstemperatur i grader celsius då alla dioder är släckta
// denna kan du behöva ändra om det är varmt i rummet
const float baselineTemp = 20.0;

// körs en gång vid uppstart
void setup()
{
    // öppna serieporten
    // 9600 bitar (ettor och nollor) per sekund
    Serial.begin(9600);

    // digitala stiften 2, 3, 4 ska vara output, 0 volt
    int pinNumber = 2;
    while (pinNumber < 5)
    {
        pinMode(pinNumber, OUTPUT);
        digitalWrite(pinNumber, LOW);
        pinNumber = pinNumber + 1;
    }
}

// upprepas om och om igen
void loop()
{
    int temperatureSensorValue = analogRead(sensorPin);

    // skriv ut mätvärde på datorn
    Serial.print("Temperatur sensor value: ");
    Serial.print(temperatureSensorValue);

    // omvandla mätvärde [0 - 1024) till spänning i volt
    float voltage = (temperatureSensorValue / 1024.0) * 5.0;

    Serial.print(", Volts: ");
    Serial.print(voltage);

    // omvandla till temperatur i grader celsius
    float temperature = (voltage - 0.5) * 100;

    Serial.print(", degrees C: ");
    Serial.print(temperature);

    // styr lampor
    if (temperature >= baselineTemp + 6)
    {
        // tänd tre dioder
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
    }
    else if (temperature >= baselineTemp + 4)
    {
        // tänd tre dioder
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
    }
    else if (temperature >= baselineTemp + 2)
    {
        // tänd tre dioder
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    }
    if (temperature < baselineTemp)
    {
        // släck alla dioder
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    }

    // pausa i 1 ms
    delay(1);
}
