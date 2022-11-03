#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
//#include "DHT.h"
//#define DHTPIN D1
//#define DHTTYPE DHT11 

 
const char* ssid     = "realme X7 5G";
const char* password = "12345678";
const char* host = "script.google.com"; 
const char* fingerprint = "d8 e8 41 d4 8a e2 98 3a 46 d6 6d f9 b7 57 d2 55 f2 ea ca 25";
String url;

const int trigger=D7; 
const int echo=D6; 
float dist,dist2;
int sensorPin = A0;

//DHT dht(DHTPIN, DHTTYPE);

void setup() {
 // Serial.begin(115200);
 Serial.begin(9600);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(D5,OUTPUT);
  
  
  delay(100);
  //dht.begin();
  Serial.println();
  //Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
}

 
void loop() {
 
  Serial.print("connecting to ");
  Serial.println(host);
 
  WiFiClientSecure client;

  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

 if (client.verify(fingerprint, host)) {
  Serial.println("certificate matches");
  } else {
  Serial.println("certificate doesn't match");
  }

  digitalWrite(trigger,LOW);
  delayMicroseconds(5);        
  digitalWrite(trigger,HIGH);  
  delayMicroseconds(10);      
  digitalWrite(trigger,LOW); 
  dist=pulseIn(echo,HIGH); 
  dist = dist/58; // cm
  dist2 = dist/2.54; //inch
  Serial.print(dist2);
  Serial.print("In  ");
  Serial.print(dist);
  Serial.println("Cm");     
  delay(100);

  //float h = dht.readHumidity();
  //float t = dht.readTemperature();
  //if (isnan(h) || isnan(t)) 
 // {
   //  Serial.println("Failed to read from DHT sensor!");
     //return;
  //}
  
  url = "/macros/s/AKfycbwvv1ia_2tmsfvajXQlsLVtBeN9g0Z1Fg_kRWUL6njqu3NO4neGFmNSDjsl7Oqfc-iB/exec?func=addData&val="+ String(dist);
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(500);
  String section="header";
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  Serial.println();
  Serial.println("closing connection");
  delay(60000);
}
