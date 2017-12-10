#ifndef PARTICLE
#define PARTICLE

#include <cmath>

typedef float real;

class Particle{
protected:
	Vector3 position;
	Vector3 velocity;
	Vector3 acceleration;

	real damping;
	real inverseMass;

	void integrate(real duration);
	
}

#endif