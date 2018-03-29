#include <CSRobot.h>

CSRobot r;

void setup() {
  /*
  Not every light sensor is the same, and figuring out the threshold
  to use for your programs is tedious to do through trial and error.
  Using the serial console, we can output the current light level to
  your arduino IDE and edit our program as needed.
  */

  // initialize the serial connection
  Serial.begin(9600);
}

void loop() {
  if (r.lightLevel() < 200) { // if the sensor is covered, turn on the light
    r.displayColor(WHITE);
  } else { // else: turn it off
    r.turnLightOff();
  }

  // send the current light level to the serial console
  Serial.println(r.lightLevel());
  // add a slight delay so that the console is not flooded
  delay(100);
}
