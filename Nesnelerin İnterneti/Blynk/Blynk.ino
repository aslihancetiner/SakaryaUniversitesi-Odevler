#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial    
#include <BlynkSimpleEsp8266.h>
char auth[] = "a1V26DUbyJJLb7xtC4LFJztY_jODitdW";

char ssid[] = "iPhone";
char pass[] = "123456789";

#define ledPin D7 
#define pirPin D1 
int pirValue; 
void setup()
{
  Serial.begin(115200);
  delay(10);
  Blynk.begin(auth, ssid, pass);
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  digitalWrite(ledPin, LOW);
}
void loop()
{
  getPirValue();
  Blynk.run();
  
}

void getPirValue(void)
{
  pirValue = digitalRead(pirPin);
  if (pirValue) 
  { 
    Serial.println("==> Sensörünüzde Hareket Algıland!");
    Blynk.notify("==> Sensörünüzde Hareket Algıland!");  
  }
  digitalWrite(ledPin, pirValue);














































    
  delay(10000);
}
