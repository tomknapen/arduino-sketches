#define NUMBER_OF_LIGHTS 4

static byte _lights[NUMBER_OF_LIGHTS] = {26, 28, 30, 32};

void setupLights(){
  for (int i = 0; i < NUMBER_OF_LIGHTS; i++){
    int light = _lights[i];
    
    pinMode(light, OUTPUT);
    _turnOff(i);
  }
}

void _turnOn(int lightIndex){
  digitalWrite(_lights[lightIndex], LOW);
}

void _turnOff(int lightIndex){
  Serial.print("turn off ");
  Serial.println(_lights[lightIndex]);
  
  digitalWrite(_lights[lightIndex], HIGH);
}

void processLight(int lightIndex, char* state){
  if(strcmp("OFF", state) == 0){
    _turnOff(lightIndex);
  }  if(strcmp("ON", state) == 0){
    _turnOn(lightIndex);
  }
}
