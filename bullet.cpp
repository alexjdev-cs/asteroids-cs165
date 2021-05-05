/******************************************************************************
 * File:
 *   bullet.cpp
 * Author:
 *   Alex Johnson
 * Description:
 *   The bullets shot by the player's ship. Inherits from FlyingObject.
 *****************************************************************************/
#include "bullet.h"
#include "uiDraw.h"

/********************************************************************
 * Constructor
 ********************************************************************/
Bullet::Bullet(Point point, Velocity velocity, int angle) : FlyingObject(point)
{
  this->radius = 2;

  // Parameters; we're not assigning to _this_ just yet
  velocity.addDx(BULLET_SPEED * cos(radians(angle)));
  velocity.addDy(BULLET_SPEED * sin(radians(angle)));

  // Now assign to _this_
  this->velocity = velocity;
  this->angle = angle;
}

/********************************************************************
 * update()
 * Updates the object's state.
 ********************************************************************/
void Bullet::update()
{
  FlyingObject::update();

  life++;
  if (life > BULLET_LIFE)
    kill();
}

/********************************************************************
 * draw()
 * Invoke the drawDot() function to place the bullet on the game surface.
 ********************************************************************/
void Bullet::draw()
{
  drawDot(point);
}
