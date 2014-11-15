/*
  Button
 
 Turns on and off a light emitting diode(LED) connected to digital  
 pin 13, when pressing a pushbutton attached to pin 2. 
 
 
 The circuit:
 * LED attached from pin 13 to ground 
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 
 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.
 
 
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to 
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

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); 

void SetSteps()
{
  double value = (float)dimmFactor * onePercent;
    currentClicks = (int)value;
    if(currentClicks > 52)
    {
       currentClicks = 0; 
    }

    
}

void dimm()
{
  isOn = true;
    while(digitalRead(buttonPin) == LOW)
    {
      
      dimmFactor = dimmFactor + 1;
        if(dimmFactor > 255)
        {
          dimmFactor = 0;
          lcd.setCursor(0, 1);
        lcd.print("");
        }
        
        //lcd.print("DimFactor:");
        lcd.setCursor(0, 0);
        lcd.print("Dimmfactor:");
        lcd.setCursor(0, 1);
        lcd.print(dimmFactor);
        int time = 0;
        //Serial.print("light \n");
        //Serial.print(dimmFactor);
        for(int i = 0; i <= 24;i = i +1)
        {
          delay(1);
            analogWrite(ledPin,dimmFactor);
        }
      
    }
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
 
  // read the state of the pushbutton value:
  int buttonState1 = digitalRead(buttonPin);

  delay(200);
  int buttonState2 = digitalRead(buttonPin);

  //Serial.print(buttonState1);
  //Serial.print("//");
  //Serial.print(buttonState2);
  //Serial.print("\n");
  
  if(buttonState1 == LOW && buttonState2 == LOW)
  {
    SetSteps();
    dimm(); 
  }
  if(buttonState1 == LOW && buttonState2 == HIGH)
  {
    SetSteps();
     if(isOn == true)
    {
        //Serial.print(" ON \n");
             
        lcd.setCursor(7, 0);
       isOn = false;
       lcd.print("OFF");
    }else
   {
     
        
     lcd.setCursor(7, 0);
      isOn = true;
      lcd.print("ON");
   } 
    
  }
  if(isOn == true)
  {
    //Serial.print("light \n");
    analogWrite(ledPin,dimmFactor);
  }else
  {
    analogWrite(ledPin,0);
  }
  analogWrite(analogAnzeigePin,currentClicks);
  

        //lcd.setCursor(0, 0);
        //lcd.print("Clicks:");
        //lcd.setCursor(0, 1);
        //lcd.print(currentClicks);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
 // if (buttonState == HIGH) {     
    // turn LED on:    
   // digitalWrite(ledPin, HIGH);  
 // } 
 // else {
    // turn LED off:
  //  digitalWrite(ledPin, LOW); 
 // }
}







  



