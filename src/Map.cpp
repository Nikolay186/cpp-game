#include <BearLibTerminal.h>
#include <Map.h>
#include <Utils.h>

#include <fstream>
#include <ios>
#include <string>
#include <vector>

std::vector<std::vector<Cell>> Map::cells;

void Map::ReadFromFile(std::string path) {
  std::ifstream reader;
  reader.open(path, std::ios::in);
  if (reader.is_open()) {
    char tmp;
    std::vector<Cell> row;
    while (!reader.eof()) {
      tmp = reader.get();
      if (tmp == '#') {
        row.push_back(Cell(true, false));
      } else if (tmp == ' ') {
        row.push_back(Cell(false, false));
      } else if (tmp == '\n') {
        cells.push_back(row);
        row.clear();
      }
    }
  }
  reader.close();

  if (cells.size() != 0) {
    GenerateCoins();
    Render();
  }
}

void Map::Init() {
  for (int x = 0; x < sizeX; x++) {
    std::vector<Cell> row;
    for (int y = 0; y < sizeY; y++) {
      double tmp = Utils::drand(0.0, 1.0);
      if (tmp > 0.50 && tmp < 0.55)
        row.push_back(Cell(false, true));
      else if (tmp > 0.48 && tmp < 0.50)
        row.push_back(Cell(true, false));
      else
        row.push_back(Cell(false, false));
    }
    cells.push_back(row);
  }

  Render();
}

void Map::Render() {
  auto tarr = cells;
  for (int y = 0; y < sizeY; y++) {
    for (int x = 0; x < sizeX; x++) {
      terminal_put(x, y, cells[y][x].toChar());
    }
  }
}

Cell Map::CellAt(int x, int y) {
  return cells[y][x];
}

void Map::GenerateCoins() {
  for (int y = 0; y < sizeY - 1; y++) {
    for (int x = 0; x < sizeX - 1; x++) {
      double tmp = Utils::drand(0.0, 0.1);
      if (tmp < 0.001 && !cells[y][x].has_wall) cells[y][x].has_coin = true;
    }
  }
}

void Map::RemoveCoin(int x, int y) {
  cells[y][x].has_coin = false;
}
