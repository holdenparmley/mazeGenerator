// Maze Gen class definitions                                                                                                                                                               
// Tested/working, no errors or warnings                                                                                                                                                    

#include "mazegen.h"
#include <cstdlib>

MazeGen::MazeGen(int n) : size(n * n), n_val(n), uf(size) {
  std::srand(seed);  // Initialize pseudo-random number generator at creation time                                                                                                          
  uf.data[0] = 11;
  uf.data[size - 1] = 14;
  for (int i = 1; i < size - 1; i++) {
    uf.data[i] = 15;
  }
}

void MazeGen::generate() {
  while (!uf.oneSet()) {
    int square = randSquare();  // Any value from 0 to size - 1, inclusive                                                                                                                  
    // "Distance" to the neighbor, either -n_val, -1, 1, or n_val; this makes                                                                                                               
    // the validNeighbors() function (basically a bounds checking function)                                                                                                                 
    // easier to read                                                                                                                                                                       
    int distance = randDistance();
    int neighbor = square + distance;  // The index of the neighboring cell                                                                                                                 
    if (validNeighbors(square, distance) && !uf.sameComponent(square, neighbor)) {
      breakWall(square, neighbor);
    }
  }
}

std::string MazeGen::print() {
  std::string output;
  for (int i = 0; i < size; i++) {
    int cell = uf.data[i];
    if (cell <= 9) cell += 48;
    else if (cell > 9) cell += 87;
    output += static_cast<char>(cell);
    if ((i + 1) % n_val == 0 && i != size - 1) output += '\n';
  }
  return output;
}

void MazeGen::breakWall(int x, int y) {
  // This is a private function, so no bounds checking is necessary                                                                                                                         
  uf.unionSets(x, y);
  // We manually augment the data in the MazeGen class; a different use of the                                                                                                              
  // UnionFind class might call for different data types or modifications                                                                                                                   
  if (y - x == -n_val) { uf.data[x] ^= 8; uf.data[y] ^= 2; };  // Top neighbor                                                                                                              
  if (y - x == -1) { uf.data[x] ^= 4; uf.data[y] ^= 1; };  // Left neighbor                                                                                                                 
  if (y - x == 1) { uf.data[x] ^= 1; uf.data[y] ^= 4; };  // Right neighbor                                                                                                                 
  if (y - x == n_val) { uf.data[x] ^= 2; uf.data[y] ^= 8; };  // Bottom neighbor                                                                                                            
}

bool MazeGen::validNeighbors(int square, int dist) {
  // If x is on the left wall, it has no left neighbor                                                                                                                                      
  if (!(square % n_val) && dist == -1) return false;
  // If x is on the right wall, it has no right neighbor                                                                                                                                    
  if (!((square + 1) % n_val) && dist == 1) return false;
  // If the neighbor's location would be out of bounds, we are trying to access                                                                                                             
  // either a nonexistent top neighbor or a nonexistent bottom neighbor                                                                                                                     
  if (square + dist < 0 || square + dist >= size) return false;
  return true;
}
