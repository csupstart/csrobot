#ifndef CSRobot_h
#define CSRobot_h

#include "Arduino.h"

// PUBLIC COLOR DEFS
#define RED 0
#define GREEN 1
#define BLUE 2
#define WHITE 3
#define YELLOW 4
#define PURPLE 5

// INTERNAL DEFINITIONS
// motor controller
/* #define R_ENA 9 */
/* #define R_IN1 8 */
/* #define R_IN2 11 */
/* #define R_ENB 10 */
/* #define R_IN3 12 */
/* #define R_IN4 13 */
#define R_ENA 10
#define R_IN1 12
#define R_IN2 13
#define R_ENB 9
#define R_IN3 8
#define R_IN4 11
// rgb led
#define R_RED 3
#define R_GREEN 5
#define R_BLUE 6
// inputs
#define R_BTN1 4
#define R_BTN2 2
#define R_LIGHT 0 // analog
// auto drive parameters
#define R_FIXEDSPEED 200
#define R_TURNDELAY 350
#define R_STOPDELAY 350
#define R_AROUNDSUB 120

class CSRobot {
  public:
    CSRobot();
    // driving
    void setAdjustment(int adj);
    void setSpeed(int speed);
    void driveForward();
    void driveBackwards();
    void stop();
    void driveFeet(int feet);
    void turnRight();
    void turnLeft();
    void turnAroundRight();
    void turnAroundLeft();
    void motorAControl(int level);
    void motorBControl(int level);
    // rgb led
    void setBrightness(int level);
    void displayColor(int colordef); // might need to change this data type in future
    void turnLightOff();
    // inputs
    bool buttonOnePressed(); // returns bool as state
    bool buttonTwoPressed();
    int lightLevel();
  private:
    int _motorspeed;
    int _ledbrightness;
    int _adj;
    void writeSpeed(int speed);
};

#endif
