#include "game_element.h"
#include "opponent.h"
#include "player.h"

int main() {
  Game currentgame;
  currentgame.OnAnimationStep();
  currentgame.Init();
  currentgame.UpdateScreen();
  currentgame.Start();
  return 0;
}
