#ifndef GAME_ELEMENT_H
#define GAME_ELEMENT_H

#include <iostream>
#include "cpputils/graphics/image.h"

class GameElement {
 protected:
  int x_;
  int y_;
  int width_;
  int height_;
  bool is_active_ = true;

 public:
  int GetX() const { return x_; }

  int GetY() const { return y_; }

  void SetIsActive(bool is_active) { is_active_ = is_active; }

  void SetX(int x) { x_ = x; }

  void SetY(int y) { y_ = y; }

  int GetWidth() const { return width_; }

  int GetHeight() const { return height_; }

  bool GetIsActive() const { return is_active_; }

  virtual void Draw(graphics::Image& drawing) = 0;
  virtual void Move(const graphics::Image& moving) = 0;
  bool IntersectsWith(GameElement& collision);
  bool IsOutOfBounds(const graphics::Image& outside_area);

  GameElement(int x, int y, int width, int height) {
    x_ = x;
    y_ = y;
    width_ = width;
    height_ = height;
  }

  GameElement() : x_(0), y_(0), width_(50), height_(50) {}
};
#endif
