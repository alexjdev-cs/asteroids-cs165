/******************************************************************************
 * File:
 *   velocity.cpp
 * Author:
 *   Alex Johnson
 * Description:
 *   The speed and direction with which a FlyingObject is traveling.
 *****************************************************************************/
#include "velocity.h"

/********************************************
 * Default constructor
 ********************************************/
Velocity::Velocity()
{
  this->dX = 0;
  this->dY = 0;
}

/********************************************
 * Non-default constructor
 ********************************************/
Velocity::Velocity(float dX, float dY)
{
  this->dX = dX;
  this->dY = dY;
}

/********************************************
 * getDx()
 * Returns the change in X of this
 ********************************************/
float Velocity::getDx() const
{
  return dX;
}

/********************************************
 * getDy()
 * Returns the change in Y of this
 ********************************************/
float Velocity::getDy() const
{
  return dY;
}

/********************************************
 * setDx()
 * Sets the change in X of this
 ********************************************/
void Velocity::setDx(float dX)
{
  this->dX = dX;
}

/********************************************
 * setDy()
 * Sets the change in Y of this
 ********************************************/
void Velocity::setDy(float dY)
{
  this->dY = dY;
}

/********************************************
 * addDx()
 * Adds velocity to Dx
 ********************************************/
void Velocity::addDx(float dX)
{
  this->dX += dX;
}

/********************************************
 * addDy()
 * Adds velocity to Dy
 ********************************************/
void Velocity::addDy(float dY)
{
  this->dY += dY;
}