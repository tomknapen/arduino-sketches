#include <WiFiLink.h>
#include <PubSubClient.h>   


WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

void setup() { 
  //Initialize serial and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  setupWifi();
  setupMqtt();
  setupLights();
}

void loop() {
  ensureMqttConnectionActive();

  mqttClient.loop();
}
