#ifndef COLLIDER
#define COLLIDER
#include "vector3.h"

class physicalObject;

enum ColType{box, sphere};

class Collider{

  private:
    physicalObject* _parent;
    Vector3 _center; //ref vers parent pos ?

    //Center plus dim technique ?
    Vector3 _HalfDim; //On retient la demi dimension

    double _rDim; //Spherical Collider

    ColType _typ;

  public:
    Collider(double, physicalObject*);
    bool isCollide(Collider);
    ColType getColTyp(){return _typ;}
    Vector3 getPos(){return _center;}
    void setPos(Vector3 p){_center = p;}
    Collider(Vector3, physicalObject*);
    double getSDim(){return _rDim;}
    Vector3 getBDim(){return _HalfDim;}
    void appliColide (Collider, double);
    physicalObject* getParent(){return _parent;}
  private:
    bool solveBB(Collider, Collider);
    bool solveBS(Collider, Collider);
    bool solveSS(Collider, Collider);
};


#endif
