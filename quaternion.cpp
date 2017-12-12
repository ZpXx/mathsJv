#include "quaternion.h"



Matrix Quaternion::toMatrix()
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

real Quaternion::magnitude()
		{
			return sqrt(this->w*this->w + this->v.x*this->v.x + this->v.y*this->v.y + this->v.z*this->v.z);
		}

Quaternion Quaternion::operator*(Quaternion q){
			Quaternion p = Quaternion();
		p.w = this->w*q.w - this->v.x*q.v.x - this->v.y*q.v.y - this->v.z*q.v.z;
		p.v.x = this->v.x*q.w + this->w*q.v.x  +this->v.y*q.v.z - this->v.z*q.v.y;
		p.v.y = this->v.y*q.w + this->w*q.v.y - this->v.x*q.v.z + this->v.z*q.v.x;
		p.x.z = this->w*q.v.z + this->v.x*q.v.y - this->v.y*q.v.x  + this->v.z*q.w;
		return p;
		}

void Quaternion::operator*=(Quaternion q){
		this->w = this->w*q.w - this->v.x*q.v.x - this->v.y*q.v.y - this->v.z*q.v.z;
		this->v.x = this->v.x*q.w + this->w*q.v.x  +this->v.y*q.v.z - this->v.z*q.v.y;
		this->v.y = this->v.y*q.w + this->w*q.v.y - this->v.x*q.v.z + this->v.z*q.v.x;
		this->x.z = this->w*q.v.z + this->v.x*q.v.y - this->v.y*q.v.x  + this->v.z*q.w;

		}

		real Quaternion::scalarProduct(Quaternion q)
		{
			return (w*q.w+v.x*q.v.x+v.y*q.v.y+v.z*q.v.z);
		}

		Quaternion Quaternion::conjugue()
		{
			Quaternion p = Quaternion();
			p.w=this->w;
			p.v.x=this->v.x;
			p.v.y=this->v.y;
			p.v.z=this->v.z;
			return p;
		}

		real Quaternion::norm()
		{
			return sqrt(this->w*this->w+sqrt(this->v.x*this->v.x+this->v.y*this->v.y+this->v.z*this->v.z));
		}


		Vector3 toEulerAngle()
		{
			Vector3 vect = Vector3();
			// roll (x-axis rotation)
			double sinr = +2.0 * (this->.w() * this->v.x() + this->v.y() * this->v.z());
			double cosr = +1.0 - 2.0 * (this->v.x() * this->v.x() + this->v.y() * this->v.y());
			vect.x = atan2(sinr, cosr);

			// pitch (y-axis rotation)
			double sinp = +2.0 * (this->w() * this->v.y() - this->v.z() * this->v.x());
			if (fabs(sinp) >= 1)
				vect.y = copysign(M_PI / 2, sinp); // use 90 degrees if out of range
			else
				vect.y = asin(sinp);

			// yaw (z-axis rotation)
			double siny = +2.0 * (this->w() * this->v.z() + this->v.x() * this->v.y());
			double cosy = +1.0 - 2.0 * (this->v.y() * this->v.y() + this->v.z() * this->v.z());  
			vect.z = atan2(siny, cosy);
		}
