#include <CSRobot.h>

CSRobot r;

void setup() {

}

void loop() {
  // colors!
  r.displayColor(RED);
  delay(1000);
  r.displayColor(GREEN);
  delay(1000);
  r.displayColor(BLUE);
  delay(1000);
  r.displayColor(WHITE);
  delay(1000);
  r.displayColor(YELLOW);
  delay(1000);
  r.displayColor(PURPLE);
  delay(1000);

  // brightness can be anywhere from 0 through 255
  // at the beginning of a new sketch, the brightness is automatically set to 255 (100%)
  r.setBrightness(100);
  // a new brightness setting is not used until the next time displayColor is run
  r.displayColor(PURPLE);
  delay(1000);
  // resetting the brightness to 255 for the next loop
  r.setBrightness(255);

  // turn off the light
  r.turnLightOff();
  delay(1000);
}
