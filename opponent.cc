#include "opponent.h"
#include <iostream>
#include "cpputils/graphics/image.h"
#include "game_element.h"

void OpponentProjectile::Draw(graphics::Image& background) {
  background.DrawCircle(x_ + 1, y_ + 1, 1, 190, 3, 252);
}

void OpponentProjectile::Move(const graphics::Image& moving) {
  if (GameElement::IsOutOfBounds(moving)) {
    SetIsActive(false);
  } else {
    GameElement::SetX(GetX() + 1);
    GameElement::SetY(GetY() + 1);
  }
}

void Opponent::Draw(graphics::Image& background) {
  background.DrawCircle(x_ + 1, y_ + 1, 1, 252, 186, 3);
}

void Opponent::Move(const graphics::Image& moving) {
  if (GameElement::IsOutOfBounds(moving)) {
    SetIsActive(false);
  } else {
    GameElement::SetX(GetX() + 1);
    GameElement::SetY(GetY() + 1);
  }
}
