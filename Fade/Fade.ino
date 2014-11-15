/*
 Fade
 
 This example shows how to fade an LED on pin 9
 using the analogWrite() function.
 
 This example code is in the public domain.
 */



int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
  Serial.begin(9600);
  for(int i = 2;i <= 13;i++)
  {
     pinMode(i,OUTPUT); 
  }
  
  for(int i = 0; i <= 7;i++)
  {
    pinMode(i,INPUT);
  }
} 

// the loop routine runs over and over again forever:
void loop()  { 
  // set the brightness of pin 9:
 
    for(int i = 2;i <= 13;i++)
  {
    
    for(int s = 0;s <= 500;s++)
    {
      delay(1);
      Serial.print("PIN:");
      Serial.println(i);
      analogWrite(i, brightness); 
            // change the brightness for next time through the loop:
      brightness = brightness + fadeAmount;
    
      // reverse the direction of the fading at the ends of the fade: 
      if (brightness == 0 || brightness == 255) {
        fadeAmount = -fadeAmount ; 
      }     
      // wait for 30 milliseconds to see the dimming effect    
      delay(30);
    } 
  }
  
   for(int i = 0;i <= 7;i++)
    {
      int analogInput = analogRead(i);
      Serial.print("AnalogPin: ");
      Serial.print(i);
      Serial.print(" Value: ");
      Serial.println(analogInput);
    }    

 
  Serial.println("Piep"); 
}

