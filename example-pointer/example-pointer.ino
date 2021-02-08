

void setup() {
  Serial.begin(9600);
  
  int a = 3;
  int b = 5;
  int sum = a + b;
  Serial.print("a: ");
  Serial.println(a);
  Serial.print("b: ");
  Serial.println(b);
  Serial.print("sum: ");
  Serial.println(sum);
  
  a = 12;
  b = 14;
  sum = a + b;
  Serial.print("a: ");
  Serial.println(a);
  Serial.print("b: ");
  Serial.println(b);
  Serial.print("sum: ");
  Serial.println(sum);

  // pekare
  int *p;
  // p innehåller minnesadressen till sum
  p = &sum;
  // *p är värdet på given adress
  Serial.print("(värdet i ovan angivna minnesadesss) *p: ");
  Serial.println(*p);

  sum = 11;
  Serial.print("sum: ");
  Serial.println(sum);
  Serial.print("(värdet i ovan angivna minnesadesss) *p: ");
  Serial.println(*p);
}

void loop() {
  

}
