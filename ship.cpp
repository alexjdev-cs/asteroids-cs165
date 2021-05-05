/******************************************************************************
 * File:
 *   ship.cpp
 * Author:
 *   Alex Johnson
 * Description:
 *   The player's ship used to play the Asteroids game.
 *****************************************************************************/
#include "ship.h"
#include "uiDraw.h"

/********************************************************************
 * Constructor
 ********************************************************************/
Ship::Ship() : FlyingObject(Point(0, 0))
{
  radius = 10;
}

/********************************************************************
 * draw()
 * Invokes the superclass draw(), then performs its own functionality.
 ********************************************************************/
void Ship::draw()
{
  drawShip(point, angle - 90, isThrusting);
}

/********************************************************************
 * moveLeft()
 * Rotates the ship to the left.
 ********************************************************************/
void Ship::moveLeft()
{
  rotateLeft(ROTATE_AMOUNT);
}

/********************************************************************
 * moveRight()
 * Rotates the ship to the right.
 ********************************************************************/
void Ship::moveRight()
{
  rotateRight(ROTATE_AMOUNT);
}

/********************************************************************
 * thrust()
 * Thrusts the ship in the direction it's facing.
 ********************************************************************/
void Ship::thrust()
{
  velocity.addDx(THRUST_AMOUNT * cos(radians(angle)));
  velocity.addDy(THRUST_AMOUNT * sin(radians(angle)));
}

/********************************************************************
 * setThrust()
 * Determines whether the ship should thrust during the next update.
 ********************************************************************/
void Ship::setThrust(bool isThrusting)
{
  this->isThrusting = isThrusting;
}

/********************************************************************
 * kill()
 * Invokes the superclass kill() to kill the ship.
 ********************************************************************/
void Ship::kill()
{
  FlyingObject::kill();
}

/********************************************************************
 * update()
 * Invokes the superclass update() to update the ship.
 ********************************************************************/
void Ship::update()
{
  FlyingObject::update();
}
