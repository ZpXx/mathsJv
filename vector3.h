#ifndef VECTOR3
#define VECTOR3

#include <cmath>

typedef float real;

class vector3{
	real x;
	real y;
	real z;

	public:
		vector3() : x(0),y(0),z(0) {}

		vector3(const real t, const real p, const real v) : x(t),y(p),z(v) {}

		void invert(){

			x=-x;
			y=-y;
			z=-z;
		}

		real magnitude() const{

			return sqrt(x*x+y*y+z*z);
		}

		real squareMagnitude() const {

			return x*x+y*y+z*z;
		}

		void normalize(){

			real l=magnitude();
			if(l>0)
			{
				(*this) *= ((real)1)/l;
			}
		}

		vector3 operator*(real k){
			vector3 res;
			res.x=this->x*k;
			res.y=this->y*k;
			res.z=this->z*k;
			return res;
		}

		void operator*=(real k){
			this->x*=k;
			this->y*=k;
			this->z*=k;
		}

};
#endif
