/******************************************************************************
 * File:
 *   flyingObject.h
 * Author:
 *   Alex Johnson
 * Description:
 *   The base class for all elements in the game that fly, e.g., bullets, the
 *   ship, and asteroids.
 *****************************************************************************/
#ifndef flyingObject_h
#define flyingObject_h

#include "point.h"
#include "velocity.h"

#define COMPLETE_ROTATION 360

class FlyingObject
{
protected:
  Point point;
  Velocity velocity;

  int angle = 0;
  int radius = 0;
  bool alive = true;

  void rotateRight(int);
  void rotateLeft(int);

public:
  FlyingObject(Point);
  FlyingObject(Point, Velocity);
  FlyingObject(Point, float speed, int angle);
  FlyingObject(Point, Velocity, int);

  void setPoint(Point point) { this->point = point; }
  Point getPoint() const { return point; }
  void setVelocity(Velocity velocity) { this->velocity = velocity; }
  Velocity getVelocity() const { return velocity; }
  int getAngle() const { return angle; }
  int getRadius() const { return radius; };

  bool isAlive() { return alive; }
  void kill();

  virtual void draw();
  virtual void update();
};

#endif /* flyingObject_h */
