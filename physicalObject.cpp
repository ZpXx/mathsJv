#include "physicalObject.h"
#include <iostream>
#include <cmath>

void physicalObject::treatForce(real delta){
  Vector3 resultante = Vector3();

  while(!forceQ.empty()){
    resultante+=forceQ.front();
    forceQ.pop_front();
  }
  resultante/=mass;
  resultante = integrate(resultante, delta);
  accel=resultante;
  #ifdef FORCE_DEBUG
    std::cout << "RESULTANTE" ;
    resultante.log();
  #endif
  this->spd+=resultante;
}

void physicalObject::addCollider(Vector3 v){
  _col = new Collider(v, this);
}

void physicalObject::addCollider(double r){
  _col = new Collider(r, this);
}

void physicalObject::treatSpd(real delta){
  Vector3 v = this->spd;
  v=integrate(v, delta);
  this->pos+=v;
}

Vector3 physicalObject::integrate(Vector3 v, real delta){
  return v*delta;
}


void physicalObject::treatAngularAccel(real delta){
  angularSpd += integrate(angularAccel, delta);
}

void physicalObject::treatAngularSpd(real delta){
  eulerRot += integrate(angularSpd, delta);
  eulerRot.x = fmod(eulerRot.x,360.0);
  eulerRot.y = fmod(eulerRot.y,360.0);
  eulerRot.z = fmod(eulerRot.z,360.0);
}

void physicalObject::update(real delta){

  //Update Force->Spd
  treatForce(delta);

  //Update Spd->Pos
  treatSpd(delta);

  treatAngularAccel(delta);
  treatAngularSpd(delta);

  _col->setPos(pos);
  node->setPosition(pos.toVector3df());
  node->setRotation(eulerRot.toVector3df());
}
