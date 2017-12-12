#ifndef QUADNODE
#define QUADNODE

class Quadnode{

private:
  float[2]bounds_x;
  float[2]bounds_y;
  float[2]bounds_z;

  Quadnode** children;
  Quadnode*  parent;


};

#endif
