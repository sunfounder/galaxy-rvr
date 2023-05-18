#ifndef __IR_OBSTACLE_H__
#define __IR_OBSTACLE_H__

#include "Arduino.h"

#define IR_LEFT_PIN 8
#define IR_RIGHT_PIN 7



/**
 * @brief init IR Obstacle Module
 * 
 */
void irObstacleBegin();

/**
 * @brief Returns the IO level status of the infrared obstacle avoidance module 
 *        connected with HC165 IO expansion chip.
 *        Actually it is the function hc165Read()
 * 
 * @return byte 
 */
byte irObstacleRead();

#endif // __IR_OBSTACLE_H__

