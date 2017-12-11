#ifndef COLLIDER
#define COLLIDER
#include "vector3.h"

class physicalObject;

enum ColType{box, sphere};

class Collider{

  private :
    physicalObject* _parent;
    Vector3 _center; //ref vers parent pos ?

    //Center plus dim technique ?
    double _xDim;
    double _yDim;
    double _zDim;

    double _rDim; //Spherical Collider

    ColType _typ;

  public:
    Collider(ColType);
};


#endif
