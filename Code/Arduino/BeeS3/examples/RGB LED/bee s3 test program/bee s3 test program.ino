
#include "WiFi.h"
#include <BeeS3.h>

#define WLAN_SSID "Guest"
#define WLAN_PASS "lillypeaches"

BEES3 bees3; 
// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);
  bees3.begin();
  bees3.setPixelBrightness(255 / 2);

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(44, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(38, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(36, OUTPUT);
  pinMode(35, OUTPUT);

    WiFi.begin(WLAN_SSID, WLAN_PASS);
  delay(2000);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    digitalWrite(10,HIGH);
  }
}

// the loop function runs over and over again forever
void loop() {

  bees3.setPixelColor(purple);

  digitalWrite(3, HIGH);   
  delay(100); 
  digitalWrite(3, LOW);    
  delay(100); 

  digitalWrite(4, HIGH);   
  delay(100); 
  digitalWrite(4, LOW);    
  delay(100); 

  digitalWrite(6, HIGH);   
  delay(100); 
  digitalWrite(6, LOW);    
  delay(100); 

  digitalWrite(7, HIGH);   
  delay(100); 
  digitalWrite(7, LOW);    
  delay(100); 

  digitalWrite(8, HIGH);   
  delay(100); 
  digitalWrite(8, LOW);    
  delay(100);   

  digitalWrite(9, HIGH);   
  delay(100); 
  digitalWrite(9, LOW);    
  delay(100); 

  digitalWrite(10, HIGH);   
  delay(100); 
  digitalWrite(10, LOW);    
  delay(100); 

  digitalWrite(44, HIGH);   
  delay(100); 
  digitalWrite(44, LOW);    
  delay(100); 

  digitalWrite(43, HIGH);   
  delay(100); 
  digitalWrite(43, LOW);    
  delay(100); 

   digitalWrite(39, HIGH);   
  delay(100); 
  digitalWrite(39, LOW);    
  delay(100); 

  digitalWrite(38, HIGH);   
  delay(100); 
  digitalWrite(38, LOW);    
  delay(100); 

   digitalWrite(37, HIGH);   
  delay(100); 
  digitalWrite(37, LOW);    
  delay(100);

   digitalWrite(36, HIGH);   
  delay(100); 
  digitalWrite(36, LOW);    
  delay(100); 

  if (WiFi.status() == WL_CONNECTED) {
    digitalWrite(35,HIGH);
    delay(200);
    digitalWrite(35,LOW);
    delay(200);
    digitalWrite(35,HIGH);
    delay(200);
    digitalWrite(35,LOW);
    delay(200);
    digitalWrite(35,HIGH);
    delay(200);
    digitalWrite(35,LOW);
    delay(200);
    digitalWrite(35,HIGH);
    delay(200);
    digitalWrite(35,LOW);
    delay(200);
  }                
}
