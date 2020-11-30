// hämta bibliotek för seriekommunikation
import processing.serial.*;
// variabel för att hantera (representera) serieporten
Serial myPort;

// variabel för bild
PImage logo;
// hämta bibliotek för seriekommunikation
import processing.serial.*;
// variabel för att hantera (representera) serieporten
Serial myPort;

// variabel för bild
PImage logo;

// bakgrundsfärg i bilden
int bgcolor;

// funktionen körs en gång vid uppstart
void setup()
{
  // HSB står för 
  // Hue (färg) ändras med potentiometern
  // Saturation 
  // Brightnesss 
  // mer info:
  // https://learnui.design/blog/the-hsb-color-system-practicioners-primer.html
  colorMode(HSB, 255); // värden i intervallet 0 - 255
  
  // läs in angiven bild
  logo = loadImage("https://www.arduino.cc/logo.png");
  
  // bestäm fönstrets storlek
  // sätt till samma storlek som bilden
  // size(logo.width, logo.height);
  // raden ovan godkänns inte av kompilatorn
  // har läst bildstorleken i annat program
  size(170, 116);
  
  // utrskrift till Console
  println("Available serial ports:");
  println(Serial.list());
  
  // skapa ett objekt som representerar serieporten
  myPort = new Serial(this, Serial.list()[0], 9600);  
}

// funktionen körs om och om igen
void draw()
{
  if (myPort.available() > 0)
  {
    // läser värdet som skickats från Arduinon    
    bgcolor = myPort.read();
    println(bgcolor);
  }

  // sätt bakgrundsfärgen på bilden
  background(bgcolor, 255, 255);
  // rita bilden med över vänsterhörn på koordinaten (0, 0)
  // (0, 0) ligger i övre vänstra hörnet
  // OBS y är positiv nedåt
  image(logo, 0, 0);  
}

