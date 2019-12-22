int PIN_Relais_1 = 26;
int PIN_Relais_2 = 28;
int PIN_Relais_3 = 30;
int PIN_Relais_4 = 32;

#define ON LOW
#define OFF HIGH

void setup() { 
  //Initialize serial and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  setup_wifi();
  
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
//  delay(200);
//  
//  digitalWrite(PIN_Relais_2, ON);
//  delay(200);
//  
//  digitalWrite(PIN_Relais_3, ON);
//  delay(200);
//  
//  digitalWrite(PIN_Relais_4, ON);
//  digitalWrite(PIN_Relais_1, OFF);
//  delay(200);
//
//  digitalWrite(PIN_Relais_2, OFF);
//  delay(200);
//
//  digitalWrite(PIN_Relais_3, OFF);
//  delay(200);
//
//  digitalWrite(PIN_Relais_4, OFF);
//  delay(200);
//  
//  delay(5000);
}  
