#include <CSRobot.h>

CSRobot r;

void setup() {

}

void loop() {
  if (r.buttonOnePressed()) { // won't start until button is clicked
    delay(200);
    // drive a number of feet forward
    r.driveFeet(2);

    // turning commands
    r.turnRight();
    r.turnLeft();
    // turn around clockwise or counterclockwise
    r.turnAroundRight();
    r.turnAroundLeft();

    // start driving forwards/backwards and do not stop until the stop command is issued
    r.driveForward();
    delay(500);
    r.driveBackwards();
    delay(500);
    r.stop();

    // speed can be anywhere from 0 through 255
    // at the beginning of a new sketch, the speed is automatically set to 250
    r.setSpeed(255);
    r.driveForward();
    delay(1000);
    r.stop();
    // reset the speed to 150 for the next loop
    r.setSpeed(150);
  }
}
