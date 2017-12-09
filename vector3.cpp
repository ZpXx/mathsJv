#include "vector3.h"

Vector3 Vector3::rotate_toward(Vector3 ori, Vector3 target){
    target-=ori;
    target.normalize();
    target*=this->magnitude();
    this->x = target.x;
    this->y = target.y;
    this->z = target.z;
    return *this;
}
