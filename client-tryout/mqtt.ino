#include <WiFiLink.h>
#include <PubSubClient.h>   

#include "arduino_secrets.h"

IPAddress _MQTT_BROKER(192, 168, 1, 201);
int _MQTT_PORT = 1883;

void setupMqtt(){
  mqttClient.setServer(_MQTT_BROKER, _MQTT_PORT);
  mqttClient.setCallback(_mqttCallback);

  Serial.println("initialized MQTT client");
}

void ensureMqttConnectionActive(){
  while (!mqttClient.connected()){
    Serial.println("connecting to MQTT");

    if(!mqttClient.connect("I am the client")){
      Serial.print("failed, rc = ");
      //Serial.print(mqttClient->state());
      Serial.println(", trying again in 5 seconds");

      delay(5000);

      continue;
    }
    
    Serial.println("connection established");

    mqttClient.subscribe("lights/#");
  }
}

void _mqttCallback(char* topic, byte* payload, unsigned int length){
  _printMqttMessage(topic, payload, length);

  char topicName[20] = "";
  int topicNumber;

  sscanf(topic, "%[^/]/%d", topicName, &topicNumber);

  if (strcmp(topicName, "lights") == 0){
    processLight(topicNumber, getPayloadMsg(payload, length));
  }
}

void _printMqttMessage(char* topic, byte* payload, unsigned int length){
  Serial.print("Received message [");
  Serial.print(topic);
  Serial.print("], payload: ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

char* getPayloadMsg(byte* payload, unsigned int length){
  payload[length] = '\0';
  return (char*) payload;
}
