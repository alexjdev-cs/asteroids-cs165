/******************************************************************************
 * File:
 *   ship.h
 * Author:
 *   Alex Johnson
 * Description:
 *   The player's ship used to play the Asteroids game.
 *****************************************************************************/
#ifndef ship_h
#define ship_h

#include "flyingObject.h"

#define SHIP_SIZE 10
#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

class Ship : public FlyingObject
{
private:
  bool isThrusting = false;

public:
  Ship();

  void draw();
  void moveLeft();
  void moveRight();
  void thrust();
  void setThrust(bool);
  void kill();
  void update();
};

#endif /* ship_h */
