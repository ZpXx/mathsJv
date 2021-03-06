#ifndef VECTOR3
#define VECTOR3

#include <cmath>
#include <irrlicht/irrlicht.h>
#include <iostream>

typedef float real;

class Vector3{

 public:
		real x;
		real y;
		real z;


		Vector3() : x(0),y(0),z(0) {}

		Vector3(const real t, const real p, const real v) : x(t),y(p),z(v) {}

		void invert(){ x=-x; y=-y; z=-z; }

		real magnitude() const{ return sqrt(x*x+y*y+z*z); }

		real squareMagnitude() const { return x*x+y*y+z*z; }

    void normalize(){
			real l=magnitude();
			if(l>0)
			{
				(*this) *= ((real)1)/l;
			}
		}

    Vector3 operator*(real k){ return Vector3(x*k,y*k,z*k); }

		void operator*=(real k){ this->x*=k; this->y*=k; this->z*=k; }

		void operator/=(real k){ this->x/=k; this->y/=k; this->z/=k; }

		Vector3 operator/(real k){ return Vector3(x/k, y/k, z/k); }

		void operator+=(Vector3 v){ this->x+=v.x; this->y+=v.y; this->z+=v.z; }

		Vector3 operator+(const Vector3 v){ return Vector3(x+v.x,y+v.y,z+v.z);}

		void addScaledVector(const Vector3 vector, real scale){
			x += vector.x+scale;
			y += vector.y+scale;
			z += vector.z+scale;
		}

		Vector3 componentProduct(const Vector3 &vector) const{
			return Vector3(x*vector.x, y*vector.y,z*vector.z);
		}

		Vector3 componentProductUpdate(const Vector3 &vector){
			x*=vector.x;
			y*=vector.y;
			z*=vector.z;
		}

		real scalarProduct(const Vector3 &vector) const{
			return x*vector.x+y*vector.y+z*vector.z;
		}

		real operator *(const Vector3 &vector) const{ return x*vector.x+y*vector.y+z*vector.z;}

		Vector3 vectorProduct(const Vector3 &vector) const{
			return Vector3(y*vector.z-z*vector.y,
					z*vector.x-x*vector.x,
					x*vector.y-y*vector.x);
		}

		void operator %=(const Vector3 &vector) { *this = vectorProduct(vector); }

		Vector3 operator%(const Vector3 &vector) const{
			return Vector3(y*vector.z-z*vector.y,
					z*vector.x-x*vector.x,
					x*vector.y-y*vector.x);
		}

    Vector3 operator-(const Vector3 v){ return Vector3(x-v.x, y-v.y, z-v.z); }

    void operator-=(const Vector3 v){ this->x-=v.x; this->y-=v.y; this->z-=v.z; }

		irr::core::vector3df toVector3df(){ return irr::core::vector3df(this->x, this->y, this->z); }

    Vector3 rotate_toward(Vector3, Vector3);

    void log(){ std::cout<<this->x<<"|"<<this->y<<"|"<<this->z<<std::endl; }

};
#endif
