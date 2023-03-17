#include "ir_obstacle.h"

void irObstacleBegin() {
  pinMode(IR_LEFT_PIN, INPUT);
  pinMode(IR_RIGHT_PIN, INPUT);
}

byte irObstacleRead() {
  byte left = digitalRead(IR_LEFT_PIN);
  byte right = digitalRead(IR_RIGHT_PIN);
  return (left << 1) | right;
}

