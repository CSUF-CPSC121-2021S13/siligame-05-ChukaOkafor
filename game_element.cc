#include "game_element.h"
#include <iostream>
#include "cpputils/graphics/image.h"

bool GameElement::IntersectsWith(GameElement& collision) {
  if (x_ + width_ <= collision.GetX()) {
    return false;
  }

  if (collision.GetX() + collision.GetWidth() <= x_) {
    return false;
  }

  if (y_ + height_ <= collision.GetY()) {
    return false;
  }

  if (collision.GetY() + collision.GetHeight() <= y_) {
    return false;
  }
  return true;
}

bool GameElement::IsOutOfBounds(const graphics::Image& outside_area) {
  if (y_ + height_ > outside_area.GetHeight() || y_ < 0 ||
      x_ + width_ > outside_area.GetWidth() || x_ < 0) {
    return true;
  } else {
    return false;
  }
}
