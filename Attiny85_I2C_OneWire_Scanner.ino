#include <Adafruit_I2CDevice.h>
#include <Tiny4kOLED.h>
#include "TinyWireM.h" 
#include "Minimum_font.h"
const DCfont *currentFont = FONTMINIMUM; 
Adafruit_I2CDevice i2c_dev = Adafruit_I2CDevice(0x10);

#include <OneWire.h>
/** Broche pour le bus 1-Wire */
const byte ONEWIRE_BUS_PIN = 5;

/** L'object OneWire pour communiquer via le protocole 1-Wire sur la broche spécifiée */
OneWire ds(ONEWIRE_BUS_PIN);

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
  oled.println("Scanning Start");
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
      delay(500);
    }    
  }
  if (nDevices == 0) {
    oled.println("No I2C devices found\n");
  }
  else {
    oled.println("done\n");
  }
  delay(1000);
  oled.clear();
  oled.setCursor(0, 0);
  oled.println("Start Onewire");
  
  byte address_One[8];
  if (!ds.search(address_One)) {
    oled.println(F("End of Scan."));
    ds.reset_search();
    //for(;;);
  }
  
  /* Module 1-Wire découvert ! */
  oled.clear();
  oled.setCursor(0, 0);
  oled.println(F("One Wire Found:"));
  for(byte i = 0; i < 8; ++i) {
    if (address_One[i] < 0x10) oled.write('0');
    oled.print(address_One[i], HEX);
    //oled.write(' ');
  }
oled.println(" ");
delay(2000);
  /* Vérifie si l'adresse est valide */
  if (OneWire::crc8(address_One, 7) != address_One[7]) {
      oled.print(F("(CRC invalid)"));
  }
  
  /* Fin de ligne */
  oled.println();
  delay(2000);  
  oled.clear();   
}
