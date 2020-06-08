#include <iostream>

#include "GridSize.h"

using namespace std;

GridSize::GridSize(size_t gsize) {
  _gridS = gsize;
  _data = new size_t[inputS];
}

GridSize::~GridSize() {
  delete[] _data;
}

void GridSize::SetGridSize() {
  do {
    std::cout << "Insert grid size (have to be from 10 to 32)\n";
    std::cout << "Default value is 32!\n";
    std::cin >> inputS;
  }
  while(CheckInputH() == false);
}

void GridSize::GetGridSize(size_t gsize) {
  std::cout << "Value of grid: " << inputS << "\n";
  if (inputS == 32)
  {
    gsize = 32;
  } else
  {
    gsize = inputS;
  }

}

bool GridSize::CheckInputH() {

  if(inputS > 32 || inputS < 10) {
      std::cout << "Wrong grid input please try again!\n";
      return false;
  } else {
      return true;
  }
}


