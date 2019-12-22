#include <WiFiLink.h>
#include <PubSubClient.h>   

#include "arduino_secrets.h"

IPAddress _MQTT_BROKER(192, 168, 1, 201);
int _MQTT_PORT = 1883;

void setup_mqtt(WiFiClient wifiClient, void (*callback)(char*, byte*, unsigned int)){
  PubSubClient mqttClient(wifiClient);

  mqttClient.setServer(_MQTT_BROKER, _MQTT_PORT);
  mqttClient.setCallback(callback);
}
