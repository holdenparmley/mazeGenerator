// Union-Find data structure header                                                                                               
// Tested/working, no errors or warnings                                                                                          

#ifndef UNIONFIND_H
#define UNIONFIND_H

class UnionFind {
public:
  UnionFind(int n);
  ~UnionFind();
  int* data;
  bool sameComponent(int x, int y);
  void unionSets(int x, int y);
  int find(int x);
  bool oneSet() { return numSets == 1; }
private:
  int* parent;
  int* rank;
  int numSets;
  int size;
  void link(int x, int y);
};

#endif
