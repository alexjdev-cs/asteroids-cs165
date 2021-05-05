/******************************************************************************
 * File:
 *   rocks.cpp
 * Author:
 *   Alex Johnson
 * Description:
 *   Contains the classes of all Rocks used in the game.
 *****************************************************************************/
#include "rocks.h"
#include "uiDraw.h"

/********************************************************************
 * Superclass Constructor
 ********************************************************************/
Rock::Rock(Point point) : FlyingObject(point)
{
  angle = random(0, COMPLETE_ROTATION);
}

/********************************************************************
 * Virtual draw() function
 ********************************************************************/
void Rock::draw()
{
}

/********************************************************************
 * Rock::update()
 * Invokes the super's update() and provides extensibility for children.
 ********************************************************************/
void Rock::update()
{
  FlyingObject::update();
}

/********************************************************************
 * BigRock Constructor
 ********************************************************************/
BigRock::BigRock(Point point) : Rock(point)
{
  type = LARGE;
  radius = 16;
  velocity.setDx(cos(radians(angle)));
  velocity.setDy(sin(radians(angle)));
}

/********************************************************************
 * BigRock::draw()
 * Invokes the super's draw() and its own draw function.
 ********************************************************************/
void BigRock::draw()
{
  drawLargeAsteroid(point, angle);
}

/********************************************************************
 * BigRock::update()
 * Invokes the super's update() and its own update function.
 ********************************************************************/
void BigRock::update()
{
  Rock::update();
  rotateRight(2);
}

/********************************************************************
 * MediumRock Constructor
 ********************************************************************/
MediumRock::MediumRock(Point point, Velocity velocity) : Rock(point)
{
  type = MEDIUM;
  radius = 8;
  this->velocity = velocity;
}

/********************************************************************
 * MediumRock::draw()
 * Invokes the super's draw() and its own draw function.
 ********************************************************************/
void MediumRock::draw()
{
  drawMediumAsteroid(point, angle);
}

/********************************************************************
 * MediumRock::update()
 * Invokes the super's update() and its own update function.
 ********************************************************************/
void MediumRock::update()
{
  Rock::update();
  rotateRight(5);
}

/********************************************************************
 * SmallRock Constructor
 ********************************************************************/
SmallRock::SmallRock(Point point, Velocity velocity) : Rock(point)
{
  type = SMALL;
  radius = 4;
  this->velocity = velocity;
}

/********************************************************************
 * SmallRock::draw()
 * Invokes the super's draw() and its own draw function.
 ********************************************************************/
void SmallRock::draw()
{
  drawSmallAsteroid(point, angle);
}

/********************************************************************
 * SmallRock::update()
 * Invokes the super's update() and its own update function.
 ********************************************************************/
void SmallRock::update()
{
  Rock::update();
  rotateRight(10);
}
