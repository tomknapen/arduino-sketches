#include <WiFiLink.h>

#include "arduino_secrets.h"

#if !defined(ESP_CH_SPI) && !defined(HAVE_HWSERIAL3)
  #include "SoftwareSerial.h"
  SoftwareSerial Serial3(15, 14); // RX, TX
#endif

void(* resetFunc) (void) = 0; // declare reset function @ address 0

void setupWifi() {
  _initializeWifi();
  _resetEsp();
  _checkWifiModuleConnectionEstablished();
  _connectToWifi();
}

void _initializeWifi(){
#if !defined(ESP_CH_SPI)
  Serial3.begin(9600); // speed must match with BAUDRATE_COMMUNICATION setting in firmware config.h
  WiFi.init(&Serial3);
#endif
}

void _resetEsp(){
  if (WiFi.checkFirmwareVersion("1.1.0")) {
    Serial.println("resetting ESP");
    WiFi.resetESP(); // to clear 'sockets' after sketch upload
    delay(5000); // wait while WiFiLink firmware connects to WiFi
  }
}

void _checkWifiModuleConnectionEstablished(){
   if (WiFi.status() == WL_NO_WIFI_MODULE_COMM) {
    delay(2000);
    Serial.println("communication with WiFi module not established. Resetting...");
    resetFunc(); 
  }
}

void _connectToWifi(){
  do {
    Serial.println("attempting to connect to wifi");

    delay(1000); // wait for connection
  }
  while ( WiFi.status() != WL_CONNECTED);

  Serial.println("connected to wifi");
}
