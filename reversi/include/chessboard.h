#ifndef CHESSBOARD_H_
#define CHESSBOARD_H_

#include <algorithm>

#include "config.h"

class Chessboard {
 public:
  inline Chessboard() {
    std::fill(data_, data_ + 2 * CHESSBOARD_SIZE * CHESSBOARD_SIZE, 0);
  }

  inline void Set(int c, int x, int y) { data_[Index(c, x, y)] = 1; }

  bool Place(int c, int x, int y, Chessboard *output_chessboard) const;

  inline int At(int c, int x, int y) const {
    return (int)data_[Index(c, x, y)];
  }

  int GetWinner() const;

  void SetMemory(char *ptr);

  void Debug();

  inline char *Data() { return data_; }

 private:
  inline int Index(int c, int x, int y) const {
    return (c * CHESSBOARD_SIZE + x) * CHESSBOARD_SIZE + y;
  }

  char data_[2 * CHESSBOARD_SIZE * CHESSBOARD_SIZE];
};

#endif