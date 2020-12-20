  void setup() {
    Serial.begin(9600);
    // anrop av egen funktion
    printHello(); //utskrift: Hej och välkommen!
    printHello(); //utskrift: Hej och välkommen!
    // anrop av egen funktion med parameter
    printHello("Arduino"); //utskrift: Hej Arduino!
  
    Serial.print("3 + 5 = "); //utskrift: 3 + 5 =
    // anrop av funktionen add med parametrarna 3 och 5
    Serial.println(add(3, 5)); //utskrift: 8
  }
  
  void loop() {
  
  }
  
  // definition av funktion
  void printHello()
  {
    Serial.println("Hej och välkommen!");
  }
  
  // definition av funktion som tar parameter name
  void printHello(String name)
  {
    Serial.print("Hej ");
    Serial.print(name);
    Serial.println("!");
  }
  
  // definition av funktion
  // som tar två parametrar x och y
  // och returnerar summan av talen
  int add(int x, int y)
  {
    return x + y;
  }
  
