// Union-Find data structure                                                                                                                                     
// Tested/working, no errors or warnings                                                                                                                                                    

#include "unionfind.h"

UnionFind::UnionFind(int n) : size(n), numSets(n) {
  // Size is n, not n * n; this is because this data structure might be used                                                                                                                
  // for things other than square maze generation                                                                                                                                           
  // We take into account the square n * n structure in our MazeGen class                                                                                                                   
  data = new int[n];
  parent = new int[n];
  rank = new int[n];
  for (int i = 0; i < size; i++) {
    parent[i] = i;
    rank[i] = 0;
  }
}

UnionFind::~UnionFind() {
  delete[] data;
  delete[] parent;
  delete[] rank;
}

bool UnionFind::sameComponent(int x, int y) {
  // First, a simple bounds check, incase the user calls this function                                                                                                                      
  if (x < 0 || y < 0 || x >= size || y >= size) return false;
  // The same bounds check is built in to the find function as well                                                                                                                         
  return (find(x) == find(y) && find(x) != -1 && find(y) != -1);
}

void UnionFind::unionSets(int x, int y) {
  // Another simple bounds check, making sure the integers are in bounds                                                                                                                    
  if (x < 0 || y < 0 || x >= size || y >= size) return;
  // Bounds check is still built into find as well                                                                                                                                          
  link(find(x), find(y));
}

int UnionFind::find(int x) {
  if (x < 0 || x >= size) return -1;  // Return -1 if integer is out of bounds                                                                                                              
  if (x != parent[x]) parent[x] = find(parent[x]);
  return parent[x];
}

void UnionFind::link(int x, int y) {
  // This function is private, but is called by unionSets, which is public                                                                                                                  
  // So, we do another (possibly redundant) bounds check                                                                                                                                    
  if (x == y || x == -1 || y == -1) return;
  if (rank[x] > rank[y]) {
    parent[y] = x;
  } else {
    parent[x] = y;
    if (rank[x] == rank[y]) rank[y]++;
  }
  numSets--;  // Continuously updated the number of sets                                                                                                                                    
}
