/******************************************************************************
 * File:
 *   game.h
 * Author:
 *   Alex Johnson
 * Description:
 *   The Game class handles all of the essential aspects of maintaining the
 *   Asteroids game, including managing the game state and invoking UI methods.
 *****************************************************************************/
#ifndef GAME_H
#define GAME_H

#include <vector>
#include "flyingObject.h"
#include "uiInteract.h"
#include "bullet.h"
#include "rocks.h"
#include "ship.h"

#define GAME_WIDTH 200
#define GAME_HEIGHT 200

class Game
{
private:
  Point topLeft;
  Point bottomRight;
  int score;
  Ship *ship;
  std::vector<Bullet *> bullets;
  std::vector<Rock *> rocks;

  void addRocks(Rock *);
  void removeEntities();
  void handleCollisions();
  bool checkCollision(FlyingObject *, FlyingObject *);

public:
  /*********************************************
    * Constructor
    * Initializes the game
    *********************************************/
  Game(Point tl, Point br);
  ~Game();

  /*********************************************
    * Function: handleInput
    * Description: Takes actions according to whatever
    *  keys the user has pressed.
    *********************************************/
  void handleInput(const Interface &ui);

  /*********************************************
    * Function: advance
    * Description: Move everything forward one
    *  step in time.
    *********************************************/
  void advance();

  /*********************************************
    * Function: draw
    * Description: draws everything for the game.
    *********************************************/
  void draw(const Interface &ui);
};

#endif /* GAME_H */
