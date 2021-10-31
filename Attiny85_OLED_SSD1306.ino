
#include <Tiny4kOLED.h>
#include "Minimum_font.h"
const DCfont *currentFont = FONTMINIMUM;  

void setup() {
  oled.begin();

  // Two rotations are supported,
  // The begin() method sets the rotation to 1.
  //oled.setRotation(0);

  // Some newer devices do not contain an external current reference.
  // Older devices may also support using the internal curret reference,
  // which provides more consistent brightness across devices.
  // The internal current reference can be configured as either low current, or high current.
  // Using true as the parameter value choses the high current internal current reference,
  // resulting in a brighter display, and a more effective contrast setting.
  //oled.setInternalIref(true);

  // Two fonts are supplied with this library, FONT8X16 and FONT6X8
  // Other fonts are available from the TinyOLED-Fonts library
  //oled.setFont(FONT2X6);

oled.setFont(currentFont);
oled.clear();
  oled.on();
}

void loop() {

      //analogRead on pin P5
  oled.setCursor(0, 0);
  oled.print( "V0: ");
 // oled.setCursor(30, 0);
  //oled.printAnalog(0);
  oled.println(" V");

  //analogRead on pin P2
  //oled.setCursor(0, 18);
  oled.print( "V1: ");
  //oled.setCursor(30, 18);
  //oled.printAnalog(1);
  oled.println(" V");

  //analogRead on pin P4
 // oled.setCursor(0, 36);
  oled.print( "V2: ");
  //oled.setCursor(30, 36);
//  oled.printAnalog(2);
  oled.println(" V");

  //analogRead on pin P3
  //oled.setCursor(0, 54);
  oled.print( "V3: ");
  //oled.setCursor(30, 54);
  //oled.printAnalog(3);
  oled.println(" V");

  delay(200);  // slow down jittery screen updates from ADC readings
}
