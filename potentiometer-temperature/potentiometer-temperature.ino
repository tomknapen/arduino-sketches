#include <DallasTemperature.h>
#include <OneWire.h>

/*
Robotale Potentiometer Sample Sketch

http://henrysbench.capnfatz.com/henrys-bench/arduino-sensors-and-input/robotale-slide-potentiometer-arduino-tutorial/
*/

const int PORT_IN_Potentio = A0;

#define ONE_WIRE_BUS 24

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

void setup(){  
  Serial.begin(115200);
  
  pinMode(PORT_IN_Potentio, INPUT);

  sensors.begin();
  
}

void loop(){  
  int percentage = analogRead(PORT_IN_Potentio) / 1024.0 * 100.0;

  sensors.requestTemperatures();

  int temperature = sensors.getTempCByIndex(0);
 
  Serial.print(percentage);
  Serial.print("%");
  
  Serial.print("\t");

  Serial.print(temperature);
  Serial.print("°C");

  Serial.println();
  
  delay(500);   // 0.5 sec so your display doesnt't scroll too fast
}
