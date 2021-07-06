#include <BearLibTerminal.h>
#include <Direction.h>
#include <Movement.h>

int Movement::GetDirection() {
  switch (terminal_read()) {
    case TK_W:
      return Direction::UP;
    case TK_S:
      return Direction::DOWN;
    case TK_A:
      return Direction::LEFT;
    case TK_D:
      return Direction::RIGHT;
    case TK_CLOSE:
      terminal_close();
      break;
    default:
      return 0;
  }
  return 0;
}
