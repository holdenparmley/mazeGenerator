// MazeGen class header                                                                                                                                                                     
// Tested/working, no errors or warnings                                                                                                                                                    

#ifndef MAZEGEN_H
#define MAZEGEN_H

#include <cstdlib>
#include "unionfind.h"
#include <ctime>
#include <string>

class MazeGen {
 public:
  MazeGen(int n);
  void generate();
  std::string print();
 private:
  int size;
  int n_val;
  UnionFind uf;
  int neighborDistances[4] = {-n_val, -1, 1, n_val};
  std::time_t seed = std::time(0);
  void breakWall(int x, int y);
  int randSquare() { return std::rand() % size; };
  int randDistance() { return neighborDistances[std::rand() % 4]; };
  bool validNeighbors(int x, int y);
};

#endif
