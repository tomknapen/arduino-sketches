#include <WiFiLink.h>

#include "arduino_secrets.h"

#if !defined(ESP_CH_SPI) && !defined(HAVE_HWSERIAL3)
  #include "SoftwareSerial.h"
  SoftwareSerial Serial3(15, 14); // RX, TX
#endif

void setup_wifi() {
  initializeWifi();
  checkWifiModuleConnectionEstablished();
  connectToWifi();
}

void initializeWifi(){
  Serial3.begin(9600); // speed must match with BAUDRATE_COMMUNICATION setting in firmware config.h
  WiFi.init(&Serial3);
}

void checkWifiModuleConnectionEstablished(){
   if (WiFi.status() == WL_NO_WIFI_MODULE_COMM) {
    Serial.println("Communication with WiFi module not established.");
    while (true); // don't continue
  }
}

void connectToWifi(){
  int status = WL_IDLE_STATUS;
  
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(WIFI_SSID);
    
    status = WiFi.begin(WIFI_SSID, WIFI_PASS);
    
    delay(10000); // wait 10 seconds for connection:
  }

  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
}
