#ifndef INCLUDE_CHARACTER_H_
#define INCLUDE_CHARACTER_H_

class Character {
 public:
  const int startX = 1;
  const int startY = 1;
  const char model = '@';

  int currentX;
  int currentY;
  int steps = 0;
  int coins = 0;

  void Init();
  void Move();
  void Update();
  void GetInfo();
  void CollectCoin(int x, int y);
};

#endif  // INCLUDE_CHARACTER_H_
