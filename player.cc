#include "player.h"
#include <iostream>
#include <string>
#include "cpputils/graphics/image.h"
#include "game_element.h"
#include "opponent.h"

void PlayerProjectile::Draw(graphics::Image& obj_pl_pro) {
  obj_pl_pro.DrawCircle(x_ + 1, y_ + 1, 1, 190, 3, 252);
}

void PlayerProjectile::Move(const graphics::Image& moving) {
  if (GameElement::IsOutOfBounds(moving)) {
    SetIsActive(false);
  } else {
    GameElement::SetX(GetX() + 1);
    GameElement::SetY(GetY() + 1);
  }
}

void Player::Draw(graphics::Image& obj_pl) {
  obj_pl.DrawCircle(x_ + 1, y_ + 1, 1, 252, 186, 3);
}

void Player::Move(const graphics::Image& moving) {}
