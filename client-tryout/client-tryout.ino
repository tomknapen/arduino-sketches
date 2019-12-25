#include <WiFiLink.h>
#include <PubSubClient.h>   

#define PIN_RELAIS_1 26
#define PIN_RELAIS_2 28
#define PIN_RELAIS_3 30
#define PIN_RELAIS_4 32

#define ON LOW
#define OFF HIGH

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

void setup() { 
  //Initialize serial and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  setupWifi();
  setupMqtt(mqttCallback);
  
  pinMode(PIN_RELAIS_1, OUTPUT);
  pinMode(PIN_RELAIS_2, OUTPUT);
  pinMode(PIN_RELAIS_3, OUTPUT);
  pinMode(PIN_RELAIS_4, OUTPUT);

  
  digitalWrite(PIN_RELAIS_1, OFF);
  digitalWrite(PIN_RELAIS_2, OFF);
  digitalWrite(PIN_RELAIS_3, OFF);
  digitalWrite(PIN_RELAIS_4, OFF);
}

void loop() {
  ensureMqttConnectionActive();
  
//  digitalWrite(PIN_RELAIS_1, ON);
//  delay(1000);
//  
//  digitalWrite(PIN_RELAIS_2, ON);
//  delay(200);
//  
//  digitalWrite(PIN_RELAIS_3, ON);
//  delay(200);
//  
//  digitalWrite(PIN_RELAIS_4, ON);
//  digitalWrite(PIN_RELAIS_1, OFF);
//  delay(2000);
//
//  digitalWrite(PIN_RELAIS_2, OFF);
//  delay(200);
//
//  digitalWrite(PIN_RELAIS_3, OFF);
//  delay(200);
//
//  digitalWrite(PIN_RELAIS_4, OFF);
//  delay(200);
//  
//  delay(5000);
}  

void mqttCallback(char* topic, byte* payload, unsigned int length){
    Serial.println("callback!");
}
