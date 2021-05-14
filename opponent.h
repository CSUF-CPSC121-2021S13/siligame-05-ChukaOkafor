#ifndef OPPONENT_H
#define OPPONENT_H

#include <iostream>
#include <string>
#include <vector>
#include "cpputils/graphics/image.h"
#include "game_element.h"

class Opponent : public GameElement {
 public:
  Opponent(int x, int y) : GameElement(x, y, 50, 50) {}

  Opponent() : GameElement() {}

  void Draw(graphics::Image& obj_op) override;
  void Move(const graphics::Image& moving) override;
};

class OpponentProjectile : public GameElement {
 public:
  OpponentProjectile(int x, int y) : GameElement(x, y, 5, 5) {}

  OpponentProjectile() : GameElement() {}

  void Draw(graphics::Image& obj_op_pro) override;
  void Move(const graphics::Image& moving) override;
};

#endif
