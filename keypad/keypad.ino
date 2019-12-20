#include <ErriezRobotDynKeypad3x4Analog.h>

const int PORT_IN_Keypad = A0;

RobotDynKeypad3x4Analog keypad(PORT_IN_Keypad);

void setup(){  
  Serial.begin(115200);
  
  pinMode(PORT_IN_Keypad, INPUT);
}

void loop(){  
  int keypadData = analogRead(PORT_IN_Keypad);

  if (keypadData < 100){
    return;
  }
 
  Serial.print(keypadData);

  Serial.print("\t|\t");

  int keypadState = keypad.getButtons();

  Serial.print(keypadState);

  Serial.println();
}

/*
 *    1  2  3
 *    4  5  6
 *    7  8  9
 *    *  0  #
 * 
 * 1 = 1022 - 1023  1023
 * 2 = 930 - 931    930
 * 3 = 852 - 853    850
 * 4 = 780 - 795    790
 * 5 = 729 - 734    730
 * 6 = 674 - 688    680
 * 7 = 637 - 651    640
 * 8 = 589 - 604    600
 * 9 = 555 - 574    570
 * * = 539 - 554    540
 * 0 = 496 - 521    510
 * # = 467 - 491    490
 */
