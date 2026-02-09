#include <LedControl.h>

//setup
LedControl lc = LedControl(12,11,10,1)
//12 : DIN (send data)
//11 : CLK (clock)
//10 : CS/LOAD (tells chip when to read data) 
//1 : # of matrix modules connected (1)

void setup(){
  lc.shutdown(0,false); //wake up
  lc.setIntensity(0,8) //brightness:0-15
  lc.clearDisplay(0);
}

void loop(){
  for (int i = 0; i<8; i++){
    lc.setLed(0,1,1,true);
    delay(100);
}

delay(500);
lc.clearDisplay(0)
}
