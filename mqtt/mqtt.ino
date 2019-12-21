#include "arduino_secrets.h"

int PIN_Relais_1 = 26;
int PIN_Relais_2 = 28;
int PIN_Relais_3 = 30;
int PIN_Relais_4 = 32;

#define ON LOW
#define OFF HIGH

void setup() { 
  pinMode(PIN_Relais_1, OUTPUT);
  pinMode(PIN_Relais_2, OUTPUT);
  pinMode(PIN_Relais_3, OUTPUT);
  pinMode(PIN_Relais_4, OUTPUT);

  
  digitalWrite(PIN_Relais_1, OFF);
  digitalWrite(PIN_Relais_2, OFF);
  digitalWrite(PIN_Relais_3, OFF);
  digitalWrite(PIN_Relais_4, OFF);
}

void loop() {
//  digitalWrite(PIN_Relais_1, ON);
//  delay(1000);
//  digitalWrite(PIN_Relais_2, ON);
//  delay(1000);
//  digitalWrite(PIN_Relais_3, ON);
//  delay(1000);
//  digitalWrite(PIN_Relais_4, ON);
//  delay(1000);
//  digitalWrite(PIN_Relais_1, OFF);
//  digitalWrite(PIN_Relais_2, OFF);
//  digitalWrite(PIN_Relais_3, OFF);
//  digitalWrite(PIN_Relais_4, OFF);
//  delay(5000);
}  
