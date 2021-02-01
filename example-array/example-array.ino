void setup () {
  Serial.begin(9600);
  
  Serial.println("**************");
  Serial.println("favorittal");
  Serial.println("--------------");
  // variabel med plats för 5 heltal
  // en variabel med plats för flera värden kallas vektor (eng. array)
  int favorittal [5]; 
  // har index 0, 1, 2, 3, 4
  // index börjar alltid på 0 i C++
  favorittal[0] = 2;
  favorittal[1] = 3;
  favorittal[2] = 5;
  favorittal[3] = 7;
  favorittal[4] = 11;

  Serial.print("Mina favorittal: ");
  int index = 0;
  while (index < 5)
  {
    Serial.print(favorittal[index]);
    Serial.print(", ");
    index = index + 1;
  }
  Serial.println();

  Serial.println("**************");
  Serial.println("inköpslista");
  Serial.println("--------------");
  String list [] = {"milk", "egg", "flour", "salt"};
  Serial.println("buy: ");
  for (int i = 0; i < 4; i = i + 1)
  {
    Serial.println(list[i]);
  }


  Serial.println("**************");
  Serial.println("rövarspråk");
  Serial.println("--------------");

  //char message [3] = {'h', 'e', 'j'};
  // nedanstående rad ger samma vektor (eng. array) som raden ovan
  char message [3] = "hej";
  // nedanstående rad ger också samma resultat
  //String message = "hej";
  Serial.print(message);
  Serial.println(" på rörvarspråk:");
  // sizeof(message) ger värdet 3
  // men för String blir det 6
  // läs mer om sizeof(): https://www.arduino.cc/reference/en/language/variables/utilities/sizeof/
  Serial.print("ordlängd: ");
  Serial.println(sizeof(message));
  for (int i = 0; i < sizeof(message); i = i + 1)
  {
    Serial.print(message[i]);
    // om konsonant
    // fuskar lite eftersom e är den enda vokalen i hej
    if (message[i] != 'e')
    {
      Serial.print('o');
      Serial.print(message[i]);      
    }
  }
  Serial.println();

  
  Serial.println("**************");
  Serial.println("Yatzy");
  Serial.println("--------------");
  // för att få nya slumptal när programmet körs en gång till
  randomSeed(analogRead(A0));
  
  // vektor (eng. array) med plats för 5 heltal
  int dice[5];
  for (int i = 0; i < 5; i = i + 1)
  {
    // kasta 5 tärningar, en i taget
    // spara resultatet i dice
    dice[i] = random(1, 7);
  }
  Serial.println("Yatzy dice");
  for (int i = 0; i < 5; i = i + 1)
  {
    Serial.print(dice[i]);
    Serial.print(", ");
  }
  Serial.println();
  int sum = 0;
  for (int i = 0; i < 5; i = i + 1)
  {
    sum = sum + dice[i];
  }
  Serial.print("sum: ");
  Serial.println(sum);
  Serial.println("**************");
  Serial.println("--------------");
}

void loop () 
{

}
