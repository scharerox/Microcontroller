/*
 Fade
 
 This example shows how to fade an LED on pin 9
 using the analogWrite() function.
 setxkbmap -model pc105 -layout de
 This example code is in the public domain.
 */



int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
  Serial.begin(9600);
  pinMode(17,OUTPUT);
  pinMode(18,OUTPUT);
  pinMode(19,OUTPUT);
  
  for(int i = 0; i <= 7;i++)
  {
    pinMode(i,INPUT);
  }
} 

// the loop routine runs over and over again forever:
void loop()  { 
  // set the brightness of pin 9:

    int values[8];
    

   for(int i = 0;i <= 7;i++)
    {
      values[i] = analogRead(i);
      
;
      
      for(int s = 0;s <= 200;s++)
      {
        delay(1);
        digitalWrite(17,HIGH);
        digitalWrite(18,HIGH);
        digitalWrite(19,HIGH); 
      }
      
      
    }    
    
    for(int i = 0;i < 8;i++)
    {
      Serial.print("$AnalogPin: ");
      Serial.print(i);
      Serial.print(values[i]);
    }
    
      Serial.println("");

   
}

