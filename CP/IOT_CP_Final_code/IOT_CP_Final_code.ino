#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include "DHT.h"
#define DHTTYPE DHT11 // type of the temperature sensor
const int DHTPin = 5; //--> The pin used for the DHT11 sensor is Pin D1 = GPIO5
DHT dht(DHTPin, DHTTYPE); //--> Initialize DHT sensor, DHT dht(Pin_used, Type_of_DHT_Sensor);

//#include <SPI.h>
//#include <Wire.h>
#include "MQ135.h"




WiFiClient client;
long myChannelNumber = 1733229;
const char myWriteAPIKey[] = "QJG9K2CJAKXI9JPN";

//const int trigger=D7; 
//const int echo=D6; 
float dist,dist2;
int sensorPin = A0;
//int gasPin = A1;
//int pirpin =A2;
int ir1 = 0;
int ir2 = 0;

void setup()
{
  Serial.begin(9600);
//  pinMode(trigger,OUTPUT);
 // pinMode(echo,INPUT);
  pinMode(D5,OUTPUT);  // Led Pin Connected To D5 Pin   

WiFi.begin("Redmi Note 9","987654321");
while(WiFi.status() !=WL_CONNECTED)
{delay(100);
Serial.print(".");
}
Serial.println();
Serial.println("NodeMCU is Connected");
Serial.println(WiFi.localIP());
ThingSpeak.begin(client);
}
//pinMode(sensor,INPUT); 
//}
void loop()
{
  //////////////////////////////////// UltraSonic Sensor ////////////////////////////////////
//  digitalWrite(trigger,LOW);
//  delayMicroseconds(5);        
//  digitalWrite(trigger,HIGH);  
//  delayMicroseconds(10);      
//  digitalWrite(trigger,LOW); 
//  dist=pulseIn(echo,HIGH); 
//  dist = dist/58; // cm
//  dist2 = dist/2.54; //inch
//  Serial.print(dist2);
//  Serial.print("In  ");
//  Serial.print(dist);
//  Serial.println("Cm");     
//  delay(100);
//  ThingSpeak.writeField(myChannelNumber, 5, dist, myWriteAPIKey);
//  delay(2000);
//  //ThingSpeak.writeField(myChannelNumber, 2, , myWriteAPIKey);
//  //delay(2000);
//   
//   if(dist>10 && dist<60){
//    digitalWrite(D5,HIGH); 
//  }
//  else{
//   digitalWrite(D5,LOW); 
//   }
//   ////////////////////////////////////  IR SENSOR //////////////////////////
//   int s1=analogRead(A0); // IR Sensor output pin connected to A0  
//  Serial.println(s1);  // See the Value In Serial Monitor     
//  delay(50);  
//  if(s1< 900 )  
//  {  
//   digitalWrite(14,HIGH); // LED ON  
//  }  
//   else  
//  {  
//   digitalWrite(14,LOW); // LED OFF  
//  }  
//  ThingSpeak.writeField(myChannelNumber, 4, s1, myWriteAPIKey);
// delay(2000);
//   ///////////////////////////////DHT 11 Sensor (Moisture and Temperature ////////////////////////
     int h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  delay(2000);
    //float t = dht.readTemperature();
 // delay(2000);
  // Check if any reads failed and exit early (to try again).
//  if (isnan(h) || isnan(t)) {
//    Serial.println("Failed to read from DHT sensor !");
//    delay(500);
//    return;
//}
//  String Temp = "Temperature : " + String(t) + " °C";
  String Humi = "Humidity : " + String(h) + " %";
  
  Serial.println(Humi);
 // Serial.println(Temp);

    ThingSpeak.writeField(myChannelNumber, 3,h, myWriteAPIKey);
  //  ThingSpeak.writeField(myChannelNumber, 1,t, myWriteAPIKey);
  delay(2000);

////////////////////////////////////////////////// Air Quality /////////////
    MQ135 gasSensor = MQ135(A0);
    float air_quality = gasSensor.getPPM();
    Serial.print("Air Quality: ");  
    Serial.print(air_quality);
    Serial.println("  PPM");   
    Serial.println();  
    ThingSpeak.writeField(myChannelNumber, 2,air_quality, myWriteAPIKey);
    delay(2000);
}
