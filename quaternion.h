#ifndef QUATERNION
#define QUATERNION

#include <cmath>
#include <irrlicht/irrlicht.h>
#include "vector3.h"
#include "matrix.h"
#include <iostream>

typedef float real;

class Quaternion{

 public:
		real w;
		Vector3 v;




		Quaternion() : w(0), v.x(0),v.y(0),v.z(0) {}

		Quaternion(const t, Vector3 p) :w(t),v.x(p.x),v.y(p.y), v.z(p.z) {}

		Matrix toMatrix(){}

		real magnitude(){}

		Quaternion operator*(Quaternion q){}

		void operator*=(Quaternion q){}

		real scalarProduct(Quaternion q){}

		Quaternion conjugue(){}

		real norm(){}

    	void log(){ std::cout<<this->w<<"|"<<this->v.x<<"|"<<this->v.y<<"|"<<this->v.z<<std::endl; }

};
#endif
