#include "ir_obstacle.h"

void irObstacleBegin() {
  pinMode(IR_LEFT_PIN, INPUT);
  pinMode(IR_RIGHT_PIN, INPUT);
}

bool irObstacleIsLeftDetected() { return digitalRead(IR_LEFT_PIN) == LOW; }

bool irObstacleIsRightDetected() { return digitalRead(IR_RIGHT_PIN) == LOW; }

byte irObstacleRead() {
  byte left = irObstacleIsLeftDetected();
  byte right = irObstacleIsRightDetected();
  return (left << 1) | right;
}
