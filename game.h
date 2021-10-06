#ifndef GAME_H
#define GAME_H
#include <vector>

#include "cpputils/graphics/image.h"
#include "cpputils/graphics/image_event.h"
#include "game_element.h"
#include "opponent.h"
#include "player.h"

class Game : public graphics::AnimationEventListener,
             graphics::MouseEventListener {
 protected:
  graphics::Image game_screen;
  std::vector<Opponent> list_op;
  std::vector<OpponentProjectile> op_pro_list;
  std::vector<PlayerProjectile> p_pro_list;
  Player player;

 public:
  Game() : game_screen(800, 600) {}

  Game(int game_width, int game_height)
      : game_screen(game_width, game_height) {}

  graphics::Image &GetGameScreen() { return game_screen; }

  std::vector<Opponent> &GetOpponents() { return list_op; }

  std::vector<OpponentProjectile> &GetOpponentProjectiles() {
    return op_pro_list;
  }

  std::vector<PlayerProjectile> &GetPlayerProjectiles() { return p_pro_list; }

  Player &GetPlayer() { return player; }

  void CreateOpponents() {
    Opponent opponent(100, 100);
    list_op.push_back(opponent);
  }

  void CreateOpponentProjectiles() {
    OpponentProjectile opponent_projectile(300, 300);
    op_pro_list.push_back(opponent_projectile);
  }

  void CreatePlayerProjectiles() {
    PlayerProjectile player_projectile(500, 500);
    p_pro_list.push_back(player_projectile);
  }

  void Init();

  void UpdateScreen();

  void Start();

  void MoveGameElements();

  void OnAnimationStep() override;

  void OnMouseEvent(const graphics::MouseEvent &event) override;

  void FilterIntersections();
};

#endif
