#include <BearLibTerminal.h>
#include <Character.h>
#include <Direction.h>
#include <Map.h>
#include <Movement.h>

#include <cstdio>
#include <string>

void Character::Init() {
  currentX = startX;
  currentY = startY;
  terminal_put(startX, startY, model);
  GetInfo();
  terminal_refresh();
}

void Character::Move() {
  switch (Movement::GetDirection()) {
    case Direction::UP: {
      if (currentY - 1 >= 0 && !Map::CellAt(currentX, currentY - 1).has_wall) {
        currentY -= 1;
        CollectCoin(currentX, currentY);
        steps++;
      }
      break;
    }

    case Direction::DOWN: {
      if (currentY + 1 <= Map::sizeY - 1 && !Map::CellAt(currentX, currentY + 1).has_wall) {
        currentY += 1;
        CollectCoin(currentX, currentY);
        steps++;
      }
      break;
    }

    case Direction::LEFT: {
      if (currentX - 1 >= 0 && !Map::CellAt(currentX - 1, currentY).has_wall) {
        currentX -= 1;
        CollectCoin(currentX, currentY);
        steps++;
      }
      break;
    }

    case Direction::RIGHT: {
      if (currentX + 1 <= Map::sizeX - 1 && !Map::CellAt(currentX + 1, currentY).has_wall) {
        currentX += 1;
        CollectCoin(currentX, currentY);
        steps++;
      }
      break;
    }

    default:
      return;
  }
}

void Character::Update() {
  Move();
  terminal_put(currentX, currentY, model);
  GetInfo();
  terminal_refresh();
}

void Character::GetInfo() {
  std::string st = "Steps: " + std::to_string(steps) + '\n' + "Coins: " + std::to_string(coins);
  terminal_print(Map::sizeX - 12, Map::sizeY - 3, st.c_str());
}

void Character::CollectCoin(int x, int y) {
  if (Map::CellAt(currentX, currentY).has_coin) {
    coins++;
    Map::RemoveCoin(x, y);
  }
}
