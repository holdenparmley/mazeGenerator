// Main function for maze generation
// Expects input to be the executable name followed by an integer n
// The maze will be n cells by n cells
// Working/tested, no errors or warnings                                                                                                                                                    

#include <iostream>
#include <string>
#include "unionfind.h"
#include "mazegen.h"

int main(int argc, char* argv[]) {
  if (!argv[1]) {
    std::cout << "You must specify the size of your maze!" << std::endl;
    return 0;
  }
  std::string num = argv[1];
  int n = std::stoi(num);
  if (n < 3) {
    std::cout << "Command line parameter n must be at least 3!" << std::endl;
    return 0;
  }
  MazeGen myMaze = MazeGen(n);
  myMaze.generate();
  std::cout << myMaze.print() << std::endl;
}

