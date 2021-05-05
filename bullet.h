/******************************************************************************
 * File:
 *   bullet.h
 * Author:
 *   Alex Johnson
 * Description:
 *   The bullets shot by the player's ship. Inherits from FlyingObject.
 *****************************************************************************/
#ifndef bullet_h
#define bullet_h

#include "flyingObject.h"

// "Life" values in terms of units of game time (frames)
#define BULLET_SPEED 10
#define BULLET_LIFE 20

class Bullet : public FlyingObject
{
private:
  int life = 0;

public:
  Bullet(Point, Velocity, int);
  virtual void update();
  virtual void draw();
};

#endif /* bullet_h */
