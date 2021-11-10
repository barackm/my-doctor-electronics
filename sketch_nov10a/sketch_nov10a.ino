#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

// api end point
const char* api_endpoint = "http://";

void setup() {
 
  Serial.begin(115200);                 //Serial connection
  WiFi.begin("yourSSID", "yourPASS");   //WiFi connection
 
  while (WiFi.status() != WL_CONNECTED) {  //Wait for the WiFI connection completion
 
    delay(500);
    Serial.println("Waiting for connection");
 
  }
 
}
 
void loop() {
  delay(30000);
  String data = "{\"heartRate\":\"80\",\"bloodPressure\":\"120/80\",\"temperature\":\"37.5\",\"kitIdentifier\":\"kit1\"}";
  sendData(data);
}

void sendData(String data) {
    if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 
    HTTPClient http;    //Declare object of class HTTPClient
 
    http.begin(api_endpoint);      //Specify request destination
    http.addHeader("Content-Type", "application/json");  //Specify content-type header
 
    int httpCode = http.POST(data);   //Send the request
    String payload = http.getString();                  //Get the response payload
    send the request with a json payload
 
    Serial.println(httpCode);   //Print HTTP return code
    Serial.println(payload);    //Print request response payload
 
    http.end();  //Close connection
 
  } else {
 
    Serial.println("Error in WiFi connection");
 
  }
}
  