#include <CSRobot.h>

CSRobot r;

void setup() {

}

void loop() {
  // the functions buttonOnePressed and buttonTwoPressed simply return true or false!
  if (r.buttonOnePressed() && r.buttonTwoPressed()) {
    r.displayColor(RED);
  } else if (r.buttonOnePressed()) {
    r.displayColor(GREEN);
  } else if (r.buttonTwoPressed()) {
    r.displayColor(BLUE);
  } else {
    r.turnLightOff();
  }
}
