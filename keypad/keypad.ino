/*
Robotale Potentiometer Sample Sketch

http://henrysbench.capnfatz.com/henrys-bench/arduino-sensors-and-input/robotale-slide-potentiometer-arduino-tutorial/
*/

const int PORT_IN_Keypad = A0;


void setup(){  
  Serial.begin(115200);
  
  pinMode(PORT_IN_Keypad, INPUT);
  
}

void loop(){  
  int keypadData = analogRead(PORT_IN_Keypad);
 
  Serial.print(keypadData);

  Serial.println();
  
  delay(500);   // 0.5 sec so your display doesnt't scroll too fast
}

/*
 *    1  2  3
 *    4  5  6
 *    7  8  9
 *    *  0  #
 * 
 * 1 = 1022 - 1023
 * 2 = 930 - 931
 * 3 = 852 - 853
 * 4 = 780 - 795
 * 5 = 729 - 734
 * 6 = 674 - 688
 * 7 = 637 - 651
 * 8 = 589 - 604
 * 9 = 555 - 574
 * * = 539 - 554
 * 0 = 496 - 521
 * # = 467 - 491
 */
