#include "physicalObject.h"
#include <iostream>

void physicalObject::treatForce(real delta){
  Vector3 resultante = Vector3();

  while(!forceQ.empty()){
    resultante+=forceQ.front();
    forceQ.pop_front();
  }
  resultante/=mass;
  resultante = integrate(resultante, delta);
  std::cout << "RESULTANTE" ;
  resultante.log();
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

void physicalObject::update(real delta){

  //Update Force->Spd
  treatForce(delta);

  //Update Spd->Pos
  treatSpd(delta);

  node->setPosition(pos.toVector3df());
  node->setRotation(eulerRot.toVector3df());
}
