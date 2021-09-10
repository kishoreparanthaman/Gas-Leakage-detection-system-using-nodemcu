
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial
char auth [] = "authentication code"; 
 


char ssid [] = "__wifi_name__"; 
char pass [] = "__wifi_password__"; 
 
int Buzzer= D0;
int mq2 = A0;
int data = 0; 

void setup() 
{
  Serial.begin(9600); 
  pinMode(Buzzer, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}
 
void loop() 
{
  Blynk.run();
  getSendData();
}
 
void getSendData()
{
  data = analogRead(mq2);
  Serial.print(data);           // this is to check the data in the serial monitor of the arduino ide
  Serial.print("\n");
  Blynk.virtualWrite(V1, data);
 
  if (data > 750 )
  {
    Blynk.notify("Gas leakage Detected!"); 
    Blynk.email("Gas Alert ","Gas leakage detected");
    digitalWrite(Buzzer, HIGH);
    delay(1000);
    digitalWrite(Buzzer,LOW);
    delay(1000);
    digitalWrite(Buzzer, HIGH);
    delay(1000);
    digitalWrite(Buzzer,LOW);
    delay(1000);
  }
}
