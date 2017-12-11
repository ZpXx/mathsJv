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

		Matrix toMatrix()
		{
			Matrix M = Matrix(3);
			M.data[0][0]=1-2*(this->v.y*this->v.y)-2*(this->v.z*this->v.z);
			M.data[0][1]=2*(this->v.x*this->v.y)-2*(this->w*this->v.z);
			M.data[0][2]=2*(this->v.x*this->v.z)+*(this->v.y*this->w);

			M.data[1][0]=2*(this->v.x*this->v.y)+2*(this->w*this->v.z);
			M.data[1][1]=1-2*(this->v.x*this->v.x)-2*(this->v.z*this->v.z);
			M.data[1][2]=2*(this->v.z*this->v.y)-2*(this->w*this->v.x);

			M.data[2][0]=2*(this->v.x*this->v.z)-2*(this->w*this->v.y);
			M.data[2][1]=2*(this->v.z*this->v.y)-2*(this->w*this->v.x);
			M.data[2][2]=1-2*(this->v.y*this->v.y)-2*(this->v.x*this->v.x);
			return M;
		}

		real magnitude()
		{
			return sqrt(this->w*this->w + this->v.x*this->v.x + this->v.y*this->v.y + this->v.z*this->v.z);
		}

		Quaternion operator*(Quaternion q){
			Quaternion p = Quaternion();
		p.w = this->w*q.w - this->v.x*q.v.x - this->v.y*q.v.y - this->v.z*q.v.z;
		p.v.x = this->v.x*q.w + this->w*q.v.x  +this->v.y*q.v.z - this->v.z*q.v.y;
		p.v.y = this->v.y*q.w + this->w*q.v.y - this->v.x*q.v.z + this->v.z*q.v.x;
		p.x.z = this->w*q.v.z + this->v.x*q.v.y - this->v.y*q.v.x  + this->v.z*q.w;
		return p;
		}

		void operator*=(Quaternion q){
		this->w = this->w*q.w - this->v.x*q.v.x - this->v.y*q.v.y - this->v.z*q.v.z;
		this->v.x = this->v.x*q.w + this->w*q.v.x  +this->v.y*q.v.z - this->v.z*q.v.y;
		this->v.y = this->v.y*q.w + this->w*q.v.y - this->v.x*q.v.z + this->v.z*q.v.x;
		this->x.z = this->w*q.v.z + this->v.x*q.v.y - this->v.y*q.v.x  + this->v.z*q.w;

		}





    void log(){ std::cout<<this->w<<"|"<<this->v.x<<"|"<<this->v.y<<"|"<<this->v.z<<std::endl; }

};
#endif
