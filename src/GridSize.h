#ifndef GRIDSIZE_H
#define GRIDSIZE_H

using namespace std;

class GridSize {

  public:
   GridSize(size_t gsize) {_gridS = inputS;};
   ~GridSize(){};
   void GetGridSize(size_t gsize);
   void SetGridSize();
   bool CheckInputH();
   size_t inputS;


  private:
    size_t _gridS;
};
#endif