#include <Cell.h>

Cell::Cell(bool wall, bool coin) {
  has_wall = wall;
  has_coin = coin;
}

char Cell::toChar() {
  if (has_wall)
    return '#';
  else if (has_coin)
    return '$';
  else
    return ' ';
}
