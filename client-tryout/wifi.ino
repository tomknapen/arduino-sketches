#include <WiFiLink.h>

#include "arduino_secrets.h"

char ssid[] = WIFI_SSID;
char pass[] = WIFI_PASS;

WiFiClient wifiClient;

#if !defined(ESP_CH_SPI) && !defined(HAVE_HWSERIAL3)
  #include "SoftwareSerial.h"
  SoftwareSerial Serial3(15, 14); // RX, TX
#endif

void(* resetFunc) (void) = 0; // declare reset function @ address 0

void setup_wifi() {
  initializeWifi();
  resetEsp();
  checkWifiModuleConnectionEstablished();
  connectToWifi();
}

void initializeWifi(){
#if !defined(ESP_CH_SPI)
  Serial3.begin(9600); // speed must match with BAUDRATE_COMMUNICATION setting in firmware config.h
  WiFi.init(&Serial3);
#endif
}

void resetEsp(){
  if (WiFi.checkFirmwareVersion("1.1.0")) {
    Serial.println("resetting ESP");
    WiFi.resetESP(); // to clear 'sockets' after sketch upload
    delay(3000); // wait while WiFiLink firmware connects to WiFi
  }
}

void checkWifiModuleConnectionEstablished(){
   if (WiFi.status() == WL_NO_WIFI_MODULE_COMM) {
    delay(2000);
    Serial.println("Communication with WiFi module not established. Resetting...");
    resetFunc(); 
  }
}

void connectToWifi(){
  do {
    Serial.print("Attempting to connect to ");
    Serial.println(ssid);

    delay(1000); // wait for connection
  }
  while ( WiFi.status() != WL_CONNECTED);

  Serial.print("Connected to ");
  Serial.println(ssid);
}
