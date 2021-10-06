#include "game.h"
#include <iostream>
#include "cpputils/graphics/image.h"

void Game::Init() {
  game_screen.AddMouseEventListener(*this);
  game_screen.AddAnimationEventListener(*this);
  CreateOpponents();
  CreateOpponentProjectiles();
  CreatePlayerProjectiles();
  player.GameElement::SetX(player.GameElement::GetX() + 5);
  player.GameElement::SetY(player.GameElement::GetY() + 5);
}

void Game::MoveGameElements() {
  for (int i = 0; i < p_pro_list.size(); i++) {
    if (p_pro_list[i].GetIsActive()) {
      p_pro_list[i].Move(game_screen);
    }
  }
  for (int j = 0; j < op_pro_list.size(); j++) {
    if (op_pro_list[j].GetIsActive()) {
      op_pro_list[j].Move(game_screen);
    }
  }
  for (int k = 0; k < list_op.size(); k++) {
    if (list_op[k].GetIsActive()) {
      list_op[k].Move(game_screen);
    }
  }
  if (player.GetIsActive()) {
    player.Move(game_screen);
  }
}

void Game::UpdateScreen() {
  game_screen.DrawRectangle(0, 0, game_screen.GetWidth(),
                            game_screen.GetHeight(), 255, 255, 255);
  for (int i = 0; i < p_pro_list.size(); i++) {
    if (p_pro_list[i].GetIsActive()) {
      p_pro_list[i].Draw(game_screen);
    }
  }

  for (int j = 0; j < op_pro_list.size(); j++) {
    if (op_pro_list[j].GetIsActive()) {
      op_pro_list[j].Draw(game_screen);
    }
  }

  for (int k = 0; k < list_op.size(); k++) {
    if (list_op[k].GetIsActive()) {
      list_op[k].Draw(game_screen);
    }
  }
  if (player.GetIsActive()) {
    player.Draw(game_screen);
  }
}

void Game::Start() { game_screen.ShowUntilClosed(); }

void Game::FilterIntersections() {
  for (int i = 0; i < op_pro_list.size(); i++) {
    if (op_pro_list[i].IntersectsWith(player)) {
      op_pro_list[i].SetIsActive(false);
      player.SetIsActive(false);
    }
  }
  for (int i = 0; i < p_pro_list.size(); i++) {
    for (int j = 0; j < list_op.size(); j++) {
      if (list_op[j].IntersectsWith(p_pro_list[i])) {
        p_pro_list[i].SetIsActive(false);
        list_op[j].SetIsActive(false);
      }
    }
  }
  for (int i = 0; i < list_op.size(); i++) {
    if (list_op[i].IntersectsWith(player)) {
      player.SetIsActive(false);
      list_op[i].SetIsActive(false);
    }
  }
}

void Game::OnAnimationStep() {
  MoveGameElements();
  FilterIntersections();
  UpdateScreen();
  game_screen.Flush();
}

void Game::OnMouseEvent(const graphics::MouseEvent& event) {
  if (event.GetX() <= game_screen.GetWidth() && 0 <= event.GetX() &&
      event.GetY() <= game_screen.GetHeight() && 0 <= event.GetY()) {
    player.SetX(event.GetX() - 25);
    player.SetY(event.GetY() - 25);
  }
}
