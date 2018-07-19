#include "Arduino.h"
#include "CSRobot.h"

CSRobot::CSRobot() {
  pinMode(R_ENA, OUTPUT);
  pinMode(R_IN1, OUTPUT);
  pinMode(R_IN2, OUTPUT);
  pinMode(R_ENB, OUTPUT);
  pinMode(R_IN3, OUTPUT);
  pinMode(R_IN4, OUTPUT);
  pinMode(R_RED, OUTPUT);
  pinMode(R_GREEN, OUTPUT);
  pinMode(R_BLUE, OUTPUT);
  pinMode(R_BTN1, INPUT_PULLUP);
  pinMode(R_BTN2, INPUT_PULLUP);
  // set default speed and brightness
  _motorspeed = 150;
  writeSpeed(_motorspeed);
  _ledbrightness = 255;
  _adj = 0;
}

// driving
void CSRobot::setAdjustment(int adj) {
  _adj = adj;
}
void CSRobot::writeSpeed(int speed) {
  if (_adj > 0) {
      if (speed + _adj > 255) {
        analogWrite(R_ENA, 255);
      } else {
        analogWrite(R_ENA, speed + _adj);
      }
      analogWrite(R_ENB, speed);
  } else if (_adj < 0) {
      if (speed + _adj > 255) {
        analogWrite(R_ENB, 255);
      } else {
        analogWrite(R_ENB, speed + abs(_adj));
      }
      analogWrite(R_ENA, speed);
  } else {
      analogWrite(R_ENA, speed);
      analogWrite(R_ENB, speed);
  }
}
void CSRobot::setSpeed(int speed) {
  // 0 through 255 (pwm)
  _motorspeed = speed;
  writeSpeed(speed);
}
void CSRobot::driveForward() {
  digitalWrite(R_IN1, HIGH);
  digitalWrite(R_IN2, LOW);
  digitalWrite(R_IN3, HIGH);
  digitalWrite(R_IN4, LOW);
}
void CSRobot::driveBackwards() {
  digitalWrite(R_IN1, LOW);
  digitalWrite(R_IN2, HIGH);
  digitalWrite(R_IN3, LOW);
  digitalWrite(R_IN4, HIGH);
}
void CSRobot::stop() {
  digitalWrite(R_IN1, LOW);
  digitalWrite(R_IN2, LOW);
  digitalWrite(R_IN3, LOW);
  digitalWrite(R_IN4, LOW);
}
void CSRobot::driveFeet(int feet) {
  writeSpeed(R_FIXEDSPEED);
  driveForward();
  delay(1000 * feet);
  stop();
  delay(R_STOPDELAY);
  writeSpeed(_motorspeed);
}
void CSRobot::turnRight() {
  writeSpeed(R_FIXEDSPEED);
  digitalWrite(R_IN1, HIGH);
  digitalWrite(R_IN2, LOW);
  digitalWrite(R_IN3, LOW);
  digitalWrite(R_IN4, HIGH);
  delay(R_TURNDELAY);
  stop();
  delay(R_STOPDELAY);
  writeSpeed(_motorspeed);
}
void CSRobot::turnLeft() {
  writeSpeed(R_FIXEDSPEED);
  digitalWrite(R_IN1, LOW);
  digitalWrite(R_IN2, HIGH);
  digitalWrite(R_IN3, HIGH);
  digitalWrite(R_IN4, LOW);
  delay(R_TURNDELAY);
  stop();
  delay(R_STOPDELAY);
  writeSpeed(_motorspeed);
}
void CSRobot::turnAroundRight() {
  writeSpeed(R_FIXEDSPEED);
  digitalWrite(R_IN1, HIGH);
  digitalWrite(R_IN2, LOW);
  digitalWrite(R_IN3, LOW);
  digitalWrite(R_IN4, HIGH);
  delay((R_TURNDELAY * 2) - R_AROUNDSUB);
  stop();
  delay(R_STOPDELAY);
  writeSpeed(_motorspeed);
}
void CSRobot::turnAroundLeft() {
  writeSpeed(R_FIXEDSPEED);
  digitalWrite(R_IN1, LOW);
  digitalWrite(R_IN2, HIGH);
  digitalWrite(R_IN3, HIGH);
  digitalWrite(R_IN4, LOW);
  delay((R_TURNDELAY * 2) - R_AROUNDSUB);
  stop();
  delay(R_STOPDELAY);
  writeSpeed(_motorspeed);
}
void CSRobot::motorAControl(int level) {
  if (level < 0) {
    digitalWrite(R_IN1, LOW);
    digitalWrite(R_IN2, HIGH);
  } else {
    digitalWrite(R_IN1, HIGH);
    digitalWrite(R_IN2, LOW);
  }
  analogWrite(R_ENA, abs(level));
}
void CSRobot::motorBControl(int level) {
  if (level < 0) {
    digitalWrite(R_IN3, LOW);
    digitalWrite(R_IN4, HIGH);
  } else {
    digitalWrite(R_IN3, HIGH);
    digitalWrite(R_IN4, LOW);
  }
  analogWrite(R_ENB, abs(level));
}

// rgb led
void CSRobot::setBrightness(int level) {
  // 0 to 255
  _ledbrightness = level;
}
void CSRobot::displayColor(int colordef) {
  switch(colordef) {
    case 0: // RED
      analogWrite(R_RED, 	_ledbrightness);
      analogWrite(R_GREEN, 0);
      analogWrite(R_BLUE, 0);
      break;
    case 1: // GREEN
      analogWrite(R_RED, 0);
      analogWrite(R_GREEN, 	_ledbrightness);
      analogWrite(R_BLUE, 0);
      break;
    case 2: // BLUE
      analogWrite(R_RED, 0);
      analogWrite(R_GREEN, 0);
      analogWrite(R_BLUE, 	_ledbrightness);
      break;
    case 3: // WHITE
      analogWrite(R_RED, 	_ledbrightness);
      analogWrite(R_GREEN, 	_ledbrightness);
      analogWrite(R_BLUE, 	_ledbrightness);
      break;
    case 4: // YELLOW
      analogWrite(R_RED, 	_ledbrightness);
      analogWrite(R_GREEN, 	_ledbrightness);
      analogWrite(R_BLUE, 0);
      break;
    case 5: // PURPLE
      analogWrite(R_RED, 	_ledbrightness);
      analogWrite(R_GREEN, 0);
      analogWrite(R_BLUE, 	_ledbrightness);
      break;
  }
}
void CSRobot::turnLightOff() {
  digitalWrite(R_RED, LOW);
  digitalWrite(R_GREEN, LOW);
  digitalWrite(R_BLUE, LOW);
}

// inputs
bool CSRobot::buttonOnePressed() {
  int val = digitalRead(R_BTN1);
  if (val == LOW) {
    return true;
  } else {
    return false;
  }
}
bool CSRobot::buttonTwoPressed() {
  int val = digitalRead(R_BTN2);
  if (val == LOW) {
    return true;
  } else {
    return false;
  }
}
int CSRobot::lightLevel() {
  return analogRead(R_LIGHT);
}
