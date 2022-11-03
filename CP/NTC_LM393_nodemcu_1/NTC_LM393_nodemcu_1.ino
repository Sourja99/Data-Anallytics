//int led = 11; // Connected to D5 pin of NodeMCU
//int flame_sensor = 14; //Connected to D6 pin of NodeMCU
////int buzzer = 4; //Connected to D2 pin of NodeMCU
////int relay = 5; //Connected to D1 pin of NodeMCU
////int smoke_sensor = A0; //Connected to A0 pin of NodeMCU
////int temp_smoke_sensor;
//int flame_sensor_read;

//// You should get Auth Token in the Blynk App.
//// Go to the Project Settings (nut icon).
//char auth[] = "Auth Token"; // Enter Auth Token
//
//// Your WiFi credentials.
//// Set password to "" for open networks.
//char ssid[] = "Your WiFi SSID"; //Enter the wifi name
//char pass[] = "Your WiFi Password";// Enter the wifi password

void setup()
{
  pinMode(D5, OUTPUT);
  pinMode(A0, INPUT);
//  pinMode(buzzer, OUTPUT);
//  pinMode(relay, OUTPUT);
//  pinMode(smoke_sensor, INPUT);
  
  digitalWrite(D5,HIGH);
//  digitalWrite(buzzer, LOW);
//  digitalWrite(relay, LOW);
  // Debug console
  Serial.begin(9600);
//  Blynk.begin(auth, ssid, pass);
}

void loop() 
{
  int flame = analogRead(A0); //reading the sensor data on A0 pin
  float x = (1023-flame)/10.23;
 // Blynk.virtualWrite(V0, flame_sensor_read); //sending data to Blynk
 
  Serial.print("Flame Status:");
  Serial.println(flame);
  Serial.println(x);
  delay(1000);

//  int led_status = digitalRead(led);
////  if (led_status == HIGH)
////  {
////   Blynk.virtualWrite(V1, 255);
////  }
////  else
////  {
////   Blynk.virtualWrite(V1, 0);
////  }
////  
////  temp_smoke_sensor = analogRead(smoke_sensor);
////  Blynk.virtualWrite(V2, temp_smoke_sensor);
////  Serial.print("Current Gas Level:");
////  Serial.println(temp_smoke_sensor);
////  if (temp_smoke_sensor > 500)
////  {
////    digitalWrite(led, HIGH);
////    digitalWrite(buzzer, HIGH);
////    digitalWrite(relay, HIGH);
////    Blynk.notify("Alert Smoke Detected");  
////    }
////  else
////    {
////     digitalWrite(led, LOW);
////     digitalWrite(buzzer, LOW);
////     digitalWrite(relay, LOW);
////    }
//
//if (flame_sensor_read == 0)
//    {
//    //Blynk.virtualWrite(V1, 255);
//    digitalWrite(led, HIGH);
////    digitalWrite(buzzer, HIGH);
////    digitalWrite(relay, HIGH);
////    Blynk.notify("Alert Fire Detected");  
//    }
//  else
//      {
//      digitalWrite(led, LOW);
//    //  digitalWrite(buzzer, LOW);
//    //  digitalWrite(relay, LOW);
//      }
//      delay(500);
//     // Blynk.run();
}
