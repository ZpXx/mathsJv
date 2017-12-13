#include "vector3.h"

Vector3 Vector3::rotate_toward(Vector3 ori, Vector3 target){
  Vector3 res= Vector3();
    target-=ori;
    target.normalize();
    target*=this->magnitude();
    res.x = target.x;
    res.y = target.y;
    res.z = target.z;
    return res;
}
