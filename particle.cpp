#include<assert.h>
#include 'particle.h'

using namespace std;
void Particle::integrate(real duration)
{
	if(inverseMass <= 0.0f)return;
	assert(duration > 0.0);
	position.addScaledVector(velocity,duration);
	Vector3 resultingAcc = acceleration;

	velocity.addScaledVector(resultingAcc,duration);
	velocity *= powf(damping,duration);
	clearAccumulator();
}