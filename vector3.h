class vector3{
	real x;
	real y;
	real z;
	
	public:
		vector3() : x(0),y(0),z(0) {}
		
		vector3(const real t, const real p, const real v) : x(t),y(p),z(v) {}
		
		void invert()
		{
			x=-x;
			y=-y;
			z=-z;
		}
		
		real magnitude() const
		{
			return real_sqrt(x*x+y*y+z*z);
		}
		
		real squareMagnitude() const
		{
			return x*x+y*y+z*z;
		}
		
		void normalize()
		{
			real l=magnitude();
			if(l>0)
			{
				(*this) *= ((real)1)/l;
			}
		}
		
	
};
