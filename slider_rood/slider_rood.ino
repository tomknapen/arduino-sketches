/*
Robotale Potentiometer Sample Sketch

http://henrysbench.capnfatz.com/henrys-bench/arduino-sensors-and-input/robotale-slide-potentiometer-arduino-tutorial/
*/

const int PORT_IN_Potentio = A0;

void setup(){  
  pinMode(PORT_IN_Potentio, INPUT);
  Serial.begin(115200);
}

void loop(){  
  int percentage = analogRead(PORT_IN_Potentio) / 1024.0 * 100.0;
 
  Serial.print(percentage);
  Serial.println("%");
  
  delay(500);   // 1/2 sec so your display doesnt't scroll too fast
}
