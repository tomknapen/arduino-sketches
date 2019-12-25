#include <WiFiLink.h>
#include <PubSubClient.h>   

#include "arduino_secrets.h"

IPAddress _MQTT_BROKER(192, 168, 1, 201);
int _MQTT_PORT = 1883;

void setup_mqtt(void (*callback)(char*, byte*, unsigned int)){
  mqttClient.setServer(_MQTT_BROKER, _MQTT_PORT);
  mqttClient.setCallback(callback);

  Serial.println("initialized MQTT client");
}

void reconnect_mqtt(){
  while (!mqttClient.connected()){
    Serial.println("connecting to MQTT");

    if(!mqttClient.connect("I am the client")){
      Serial.print("failed, rc = ");
      //Serial.print(mqttClient->state());
      Serial.println(", trying again in 5 seconds");

      delay(5000);
    } else {
      Serial.println("connection established");
    }  
  }
}
