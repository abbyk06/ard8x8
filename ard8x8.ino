#include <LedControl.h>

//setup
LedControl lc = LedControl(12,11,10,1)
//12 : DIN (send data)
//11 : CLK (clock)
//10 : CS/LOAD (tells chip when to read data) 
//1 : # of matrix modules connected (1)

#define SOUND_PIN A0

void setup(){
  lc.shutdown(0,false); //wake up
  lc.setIntensity(0,8) //brightness:0-15
  lc.clearDisplay(0);

  Serial.begin(9600);
}

void loop() {
  int soundValue = analogRead(SOUND_PIN);

  int level = map(soundValue, 0, 1023, 0, 8);
  level = constrain(level, 0, 8);

  lc.clearDisplay(0);

  // Light based on sound level
  for (int row = 0; row < level; row++) {
    for (int col = 0; col < 8; col++) {
      lc.setLed(0, 7 - row, col, true);
    }
  }

  delay(50);
}
