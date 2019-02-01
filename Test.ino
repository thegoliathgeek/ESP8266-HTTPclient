#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
 
const char* ssid = "yourNetworkName";
const char* password = "yourNetworkPassword";
 
void setup () {
 
  Serial.begin(115200);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
 
    delay(1000);
    Serial.print("Connecting..");
 
  }
 
}
 
void loop() {
 
  if (WiFi.status() == WL_CONNECTED) { 
 
    HTTPClient http;  
 
    http.begin("http://drunkdriver.herokuapp.com/api/subbha/get/json");  
    int httpCode = http.GET();                                                              
 
    if (httpCode > 0) {
 
      String payload = http.getString();   
      Serial.println(payload);               
 
    }
 
    http.end();
 
  }
 
  delay(30000); 
 
}