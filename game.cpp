/******************************************************************************
 * File:
 *   game.cpp
 * Author:
 *   Alex Johnson
 * Description:
 *   The Game class handles all of the essential aspects of maintaining the
 *   Asteroids game, including managing the game state and invoking UI methods.
 *****************************************************************************/
#include <limits>
#include <algorithm>
#include <math.h>
#include "game.h"

using namespace std;

/********************************************************************
 * Non-default constructor
 * Takes two Point parameters and initializes the Game object.
 ********************************************************************/
Game::Game(Point tl, Point br) : topLeft(tl), bottomRight(br)
{
  ship = new Ship();
  score = 0;

  for (unsigned int i = 0; i < 5; i++)
  {
    rocks.push_back(new BigRock(Point(50, 50)));
  }
}

/********************************************************************
 * Destructor
 * Frees memory of all dynamically allocated objects belonging to the
 * Game class at time of destruction.
 ********************************************************************/
Game ::~Game()
{
  if (this->ship)
    delete ship;

  while (!this->bullets.empty())
  {
    delete this->bullets.back();
    this->bullets.pop_back();
  }

  while (!this->rocks.empty())
  {
    delete this->rocks.back();
    this->rocks.pop_back();
  }
}

/********************************************************************
 * advance()
 * Advance the game one "unit of time" forward 
 * (in this case, one frame.)
 ********************************************************************/
void Game::advance()
{
  ship->update();

  for (unsigned int i = 0; i < rocks.size(); i++)
    rocks[i]->update();

  for (unsigned int i = 0; i < bullets.size(); i++)
    bullets[i]->update();

  handleCollisions();
  removeEntities();
}

/********************************************************************
 * handeInput()
 * Handle keyboard interrupts and reflect the action in-game.
 ********************************************************************/
void Game::handleInput(const Interface &ui)
{
  if (ui.isUp())
  {
    ship->thrust();
    ship->setThrust(true);
  }
  else
    ship->setThrust(false);

  if (ui.isLeft())
  {
    ship->moveLeft();
  }

  if (ui.isRight())
  {
    ship->moveRight();
  }

  if (ui.isSpace())
  {
    bullets.push_back(new Bullet(ship->getPoint(), ship->getVelocity(), ship->getAngle()));
  }
}

/********************************************************************
 * draw()
 * Place the game elements on the window surface.
 ********************************************************************/
void Game::draw(const Interface &ui)
{
  ship->draw();

  for (unsigned int i = 0; i < rocks.size(); i++)
    rocks[i]->draw();

  for (unsigned int i = 0; i < bullets.size(); i++)
    bullets[i]->draw();
}

/********************************************************************
 * removeEntities()
 * Remove elements from the game when called in accordance with game logic.
 ********************************************************************/
void Game::removeEntities()
{
  vector<Rock *>::iterator rockIt = rocks.begin();
  while (rockIt != rocks.end())
  {
    if (!dynamic_cast<Rock *>(*rockIt)->isAlive())
    {
      rockIt = rocks.erase(rockIt);
    }
    else
    {
      rockIt++;
    }
  }

  vector<Bullet *>::iterator bulletIt = bullets.begin();
  while (bulletIt != bullets.end())
  {
    if (!dynamic_cast<Bullet *>(*bulletIt)->isAlive())
    {
      bulletIt = bullets.erase(bulletIt);
    }
    else
    {
      bulletIt++; // advance
    }
  }
}

/********************************************************************
 * handleCollisions
 * Handle keyboard interrupts and reflect the action in-game.
 ********************************************************************/
void Game::handleCollisions()
{
  // Loop through all the rocks and check collisions (for bullets and ship)
  for (unsigned int i = 0; i < rocks.size(); i++)
  {
    if (checkCollision(rocks[i], ship))
    {
      ship->kill();
    }

    for (unsigned int j = 0; j < bullets.size(); j++)
    {
      if (checkCollision(rocks[i], bullets[j]))
      {
        addRocks(rocks[i]);
        rocks[i]->kill();
        bullets[j]->kill();
      }
    }
  }
}

/********************************************************************
 * checkCollision()
 * Calculate the distance between two objects and determine whether
 * a collision has occurred.
 ********************************************************************/
bool Game::checkCollision(FlyingObject *a, FlyingObject *b)
{
  return (
      sqrt(
          ((a->getPoint().getX() - b->getPoint().getX()) *
           (a->getPoint().getX() - b->getPoint().getX())) +
          ((a->getPoint().getY() - b->getPoint().getY()) *
           (a->getPoint().getY() - b->getPoint().getY()))) <= (a->getRadius() + b->getRadius()));
}

/********************************************************************
 * addRocks()
 * Create new, smaller rock objects when their parent is destroyed 
 * by the player.
 ********************************************************************/
void Game::addRocks(Rock *oldRock)
{
  if (oldRock->getType() == LARGE)
  {
    rocks.push_back(new MediumRock(oldRock->getPoint(), Velocity(oldRock->getVelocity().getDx(), oldRock->getVelocity().getDy() + 1.0f)));
    rocks.push_back(new MediumRock(oldRock->getPoint(), Velocity(oldRock->getVelocity().getDx(), oldRock->getVelocity().getDy() - 1.0f)));
    rocks.push_back(new SmallRock(oldRock->getPoint(), Velocity(oldRock->getVelocity().getDx() + 2, oldRock->getVelocity().getDy())));
  }
  if (oldRock->getType() == MEDIUM)
  {
    rocks.push_back(new SmallRock(oldRock->getPoint(), Velocity(oldRock->getVelocity().getDx() - 3, oldRock->getVelocity().getDy())));
    rocks.push_back(new SmallRock(oldRock->getPoint(), Velocity(oldRock->getVelocity().getDx() + 3, oldRock->getVelocity().getDy())));
  }
}