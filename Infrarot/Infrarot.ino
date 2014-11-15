

// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  6;      // the number of the LED pin
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
boolean isOn = false;
int dimmFactor = 0;
int currentClicks = 0;
int analogAnzeigePin = 5;
double onePercent = 0.203;
#include <Wire.h>

#define Addr 0x1E   
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); 

int sX,sY,sZ;

boolean safed = false;


void DrawCoords()
{
    int x, y, z;

  // Initiate communications with compass
  Wire.beginTransmission(Addr);
  Wire.write(byte(0x03));       // Send request to X MSB register
  Wire.endTransmission();

  Wire.requestFrom(Addr, 6);    // Request 6 bytes; 2 bytes per axis
  if(Wire.available() <=6) {    // If 6 bytes available
    x = Wire.read() << 8 | Wire.read();
    z = Wire.read() << 8 | Wire.read();
    y = Wire.read() << 8 | Wire.read();
  }
  
  lcd.setCursor(0, 0);
   lcd.print("X");
   lcd.setCursor(1,0);
   lcd.print(x);
   
   lcd.setCursor(0, 1);
   lcd.print("Y");
   lcd.setCursor(1,1);
   lcd.print(y);
   
   lcd.setCursor(5, 1);
   lcd.print("Z");
   lcd.setCursor(6,1);
   lcd.print(z);
   
   if(safed)
   {
      if(sX == x )
      {
        for(int i = 0;i < 50;i = i +1)
        {
          analogWrite(ledPin,255);
           delay(1); 
        }
      }else
      if(sY == y )
      {
        for(int i = 0;i < 100;i = i +1)
        {
          analogWrite(ledPin,255);
           delay(1); 
        }
      }else
      if(sZ == z )
      {
        for(int i = 0;i < 200;i = i +1)
        {
          analogWrite(ledPin,255);
           delay(1); 
        }
      }
           
      else
      {
        analogWrite(ledPin,0);
      }
   }
   
   
}

void ClearDisplay()
{
  lcd.setCursor(0, 0);
  lcd.print("                       ");
  lcd.setCursor(0, 1);
  lcd.print("                       ");
}

 boolean isClicked()
{
  int buttonState = digitalRead(buttonPin);
  if(buttonState == LOW)
  {
    return true;
  }else
  {
    return false;
  }
}

void SafeData()
{
  

  // Initiate communications with compass
  Wire.beginTransmission(Addr);
  Wire.write(byte(0x03));       // Send request to X MSB register
  Wire.endTransmission();

  Wire.requestFrom(Addr, 6);    // Request 6 bytes; 2 bytes per axis
  if(Wire.available() <=6) {    // If 6 bytes available
    sX = Wire.read() << 8 | Wire.read();
    sZ = Wire.read() << 8 | Wire.read();
    sY = Wire.read() << 8 | Wire.read();
  }
  
  safed = true;
  ClearDisplay();
  lcd.setCursor(0, 0);
  lcd.print("Daten gespeichert");
  
}

void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:     
  // initialize the pushbutton pin as an input:
  lcd.begin(16, 2);
  pinMode(buttonPin, INPUT);   
  pinMode(ledPin, OUTPUT);  
  pinMode(analogAnzeigePin,OUTPUT);
  
    

}
void loop(){
 
  
  boolean clicked = isClicked();
  
  if(clicked)
  {
     if(safed == false)
     {
       SafeData();
     }
  }
  
}







  



