#include <BearLibTerminal.h>
#include <Character.h>
#include <Map.h>

#include <cstdio>
#include <string>

int main() {
  terminal_open();
  Character player;
  Map::ReadFromFile("1.map");
  std::string cfg = "window: size=" + std::to_string(Map::sizeX) + "x" + std::to_string(Map::sizeY);
  terminal_set(cfg.c_str());
  terminal_refresh();

  player.Init();

  while (true) {
    terminal_clear();
    Map::Render();
    player.Update();
    if (terminal_has_input()) {
      if (terminal_read() == TK_CLOSE) break;
    }
  }
  terminal_close();
}
