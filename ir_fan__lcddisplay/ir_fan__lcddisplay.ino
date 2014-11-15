

// set pin numbers:
const int ledPin =  6;      // the number of the LED pin
const int lR = 3, lG = 5, lB = 6;
int cR = 0,cG = 0,cB = 0;

long commandOnOff = 16753245;
long commandR = 16724175;
long commandG = 16718055;
long commandB = 16743045;

long commandPlus = 16748655;
long commandMinus = 16754775;

int currentPosition;
// variables will change:

#include <Wire.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#define Addr 0x1E   
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); 

int RECV_PIN = 9;
IRrecv irrecv(RECV_PIN);
decode_results results;

boolean isOn = false;

void ClearDisplay()
{
  lcd.setCursor(0, 0);
  lcd.print("                       ");
  lcd.setCursor(0, 1);
  lcd.print("                       ");
}




void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:     
  // initialize the pushbutton pin as an input:
  lcd.begin(16, 2);    
  pinMode(lR,OUTPUT);
  pinMode(lG,OUTPUT);
  pinMode(lB,OUTPUT);
  
  irrecv.enableIRIn(); // Start the receiver

}

int counter = 0;




long getPressed()
{
   if (irrecv.decode(&results))
    {
      
      long value = results.value; 
           Serial.println(results.value);
     irrecv.resume(); // Receive the next value
     return value;
      
      }
      
      return 0;
}

void setMixColor(int r,int g, int b)
{
    analogWrite(lR,r);
    analogWrite(lG,g);
    analogWrite(lB,b);
    
}

void loop(){
 
  long pressed = getPressed();
  
  if(pressed == commandOnOff)
  {
    if(isOn == true)
    {
      Serial.println("OFF");
      isOn = false;
    }else
    {
      Serial.println("ON");
       isOn = true; 
    }
    
  }
    if(pressed == commandR)
  {
    currentPosition = 1;
    
  }
  
      if(pressed == commandG)
  {
    currentPosition = 2;
    
  }
  
      if(pressed == commandB)
  {
    currentPosition = 3;
    
  }
  
  if(pressed == commandPlus)
  {
    Serial.println("Position:");
    Serial.print(currentPosition);
    
    if (currentPosition == 1)
    {
      Serial.println("RED:");
    Serial.print(cR);
      cR = cR = + 10;
      if(cR > 255)
      {
         cR = 255; 
      }
    }
    if (currentPosition == 2)
    {
      Serial.println("GELB:");
    Serial.print(cG);
      cG = cG = + 10;
      if(cG > 255)
      {
         cG = 255; 
      }
    }
        if (currentPosition == 3)
    {
      Serial.println("GRUEN:");
    Serial.print(cB);
      cB = cB = + 10;
      if(cB > 255)
      {
         cB = 255; 
      }
    }
    
  }
  
  if(pressed == commandMinus)
  {
    if (currentPosition == 1)
    {
      cR = cR = - 1;
      if(cR < 0)
      {
         cR = 0; 
      }
    }
        if (currentPosition == 1)
    {
      cG = cG = - 1;
      if(cG < 0)
      {
         cG = 0; 
      }
    }
        if (currentPosition == 1)
    {
      cB = cB = - 1;
      if(cB < 0)
      {
         cB = 0; 
      }
    }
  }
  
  if(isOn == true)
  {
    
      setMixColor(cR,cG,cB);
  }
  

  
}







  



