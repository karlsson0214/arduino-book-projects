

void setup() {
  Serial.begin(9600);

  int x; 
  x = 10;
  int y = 20;
  int sum = x + y;
  Serial.print("x: ");
  Serial.println(x); // utskrift: 10
  Serial.print("y: ");
  Serial.println(y); // 20
  Serial.print("summa: ");
  Serial.println(sum); // 30 
  x = 2 * x;
  Serial.print("x: ");
  Serial.println(x); // 20
  x = 10 * y;
  Serial.print("x: ");
  Serial.println(x); // 200
  y = 50;
  Serial.print("y: ");
  Serial.println(y); // 50
  Serial.print("x: ");
  Serial.println(x); // 200

  Serial.println("Arduino Uno");
  String text = "Arduino Uno";
  Serial.println(text); // utskrift: Arduino Uno
}

void loop() {

}
