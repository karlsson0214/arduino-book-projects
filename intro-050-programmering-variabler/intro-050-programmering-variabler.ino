int global = 200;

void setup() {
  Serial.begin(9600);

  Serial.print("global: ");
  Serial.println(global);

  int lokal = 30;
  Serial.print("lokal: ");
  Serial.println(lokal);

}

void loop() {
  if (global == 200)
  {
    Serial.print("global: ");
    Serial.println(global);
    global = 201;
  }

  // ´lokal´ was not declared in this scope
  //lokal = 80;
 
}
