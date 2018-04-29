#include <Wire.h> 
#include "RTClib.h" 

DS1307 RTC; 

void setup () { 
   
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
    
    Serial.begin(9600); 
    Wire.begin(); 
    RTC.begin(); 
 
   
  if (!RTC.isrunning()) {
   
    Serial.println("RTC is NOT running!");// following line sets the RTC to the date & time this sketch was compiled
   RTC.adjust(DateTime(__DATE__, __TIME__));
   }
   
  
 

  //Serial.print("Formato: "); Serial.println(__DATE__); Serial.print(" ");Serial.println(__TIME__);Serial.println();
} 

void loop () { 
    DateTime now = RTC.now(); 


    int decena = now.minute()/10;
    int unidad = now.minute() - (decena*10);


    Serial.println(unidad);
    Serial.println(now.minute());

  switch (unidad){

  case (0):
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    break;
  case (1):
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    break;

  case (2):
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    break;

  case (3):
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    break;
    
  case (4):
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    break;

  case (5):
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    break;
  case (6):
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    break;

  case (7):
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    break;

  case (8):
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    break;
    
  case (9):
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    break;

  }
//    Serial.print(now.year(), DEC); 
//    Serial.print('/'); 
//    Serial.print(now.month(), DEC); 
//    Serial.print('/'); 
//    Serial.print(now.day(), DEC); 
//    Serial.print(' '); 
//    Serial.print(now.hour(), DEC); 
//    Serial.print(':'); 
//    Serial.print(now.minute(), DEC); 
//    Serial.print(':'); 
//    Serial.print(now.second(), DEC); 
//     
//    Serial.println(); 
//    delay(1000); 
}
