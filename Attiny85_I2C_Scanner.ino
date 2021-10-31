#include <Adafruit_I2CDevice.h>

#include <Tiny4kOLED.h>
#include "TinyWireM.h" 
#include "Minimum_font.h"
const DCfont *currentFont = FONTMINIMUM; 
Adafruit_I2CDevice i2c_dev = Adafruit_I2CDevice(0x10);

void setup() {
   oled.begin();
  //while (!Serial) { delay(10); }
  //Serial.begin(115200);
  //Serial.println("I2C address detection test");
oled.setFont(currentFont);
oled.clear();
oled.on();
}

void loop() {
  
  byte error, address;
  int nDevices;
  oled.setCursor(0, 0);
  oled.println("Scanning...");
  nDevices = 0;
  for(address = 1; address < 127; address++ ) {
    TinyWireM.beginTransmission(address);
    error = TinyWireM.endTransmission();
    if (error == 0) {
      oled.print("I2C found at 0x");
      if (address<16) {
        oled.print("0");
      }
      oled.println(address,HEX);
      nDevices++;
    }
    else if (error==4) {
      oled.print("Unknow error at address 0x");
      if (address<16) {
        oled.print("0");
      }
      oled.println(address,HEX);
    }    
  }
  if (nDevices == 0) {
    oled.println("No I2C devices found\n");
  }
  else {
    oled.println("done\n");
  }
  delay(2000);  
  oled.clear();   
}
