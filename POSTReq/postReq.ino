#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
 
void setup() {
 
  Serial.begin(115200);                              
  WiFi.begin("SSID", "Password"); 
 
  while (WiFi.status() != WL_CONNECTED) {  
    delay(500);
    Serial.println("Waiting for connection");
 
  }
 
}
 
void loop() {
 
 if(WiFi.status()== WL_CONNECTED){  
   HTTPClient http; 
   http.begin("http://yourlink with request parameters"); 
 
   int httpCode = http.POST("Message for posting");  
   String payload = http.getString();

   Serial.println(httpCode);
   Serial.println(payload); 
 
   http.end();
 
 }else{
 
    Serial.println("WiFi Not connected");   
 
 }
 
  delay(30000);
 
}
