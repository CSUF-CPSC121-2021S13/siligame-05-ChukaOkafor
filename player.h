#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "cpputils/graphics/image.h"
#include "game_element.h"

class Player : public GameElement {
 public:
  Player(int x, int y) : GameElement(x, y, 50, 50) {}

  Player() : GameElement() {}

  void Draw(graphics::Image& obj_pl) override;
  void Move(const graphics::Image& moving) override;
};

class PlayerProjectile : public GameElement {
 public:
  PlayerProjectile(int x, int y) : GameElement(x, y, 5, 5) {}

  PlayerProjectile() : GameElement() {}

  void Draw(graphics::Image& obj_op) override;
  void Move(const graphics::Image& moving) override;
};

#endif
