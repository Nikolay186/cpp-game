#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

class Cell {
 public:
  bool has_wall = false;
  bool has_coin = false;

  Cell(bool wall, bool coin);
  Cell();
  char toChar();
};

#endif  // INCLUDE_CELL_H_
