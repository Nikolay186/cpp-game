#ifndef INCLUDE_MAP_H_
#define INCLUDE_MAP_H_

#include <Cell.h>

#include <string>
#include <vector>

class Map {
 public:
  static const int sizeX = 80;
  static const int sizeY = 25;

  static void ReadFromFile(std::string path);
  static Cell CellAt(int x, int y);
  static void Init();
  static void Render();
  static void GenerateCoins();
  static void RemoveCoin(int x, int y);

 private:
  static std::vector<std::vector<Cell>> cells;
};

#endif  // INCLUDE_MAP_H_
