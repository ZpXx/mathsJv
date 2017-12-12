#include "collider.h"
#include "physicalObject.h"
#include <cmath>
#include <iostream>
#define COLLIDER_DEBUG


Collider::Collider(double r, physicalObject* p){
  _typ = sphere;
  _parent = p;
  _rDim = r;
  _center = p->getPos();
}

Collider::Collider(Vector3 v, physicalObject* p){
  _typ = box;
  _parent = p;
  _HalfDim = v;
  _center = p->getPos();
}

void Collider::appliColide (Collider col, double coef){
  Vector3 tmp;
  //V1
  tmp = col.getParent()->getSpd()-_parent->getSpd();
  tmp*=col.getParent()->getMass()*coef;
  tmp+=_parent->getSpd()*_parent->getMass();
  tmp+=col.getParent()->getSpd()*col.getParent()->getMass();
  tmp/=col.getParent()->getMass()+_parent->getMass();
  _parent->setSpeed(tmp);

  //V2
  tmp = _parent->getSpd() - col.getParent()->getSpd();
  tmp*=col.getParent()->getMass()*coef;
  tmp+=_parent->getSpd()*_parent->getMass();
  tmp+=col.getParent()->getSpd()*col.getParent()->getMass();
  tmp/=col.getParent()->getMass()+_parent->getMass();
  col.getParent()->setSpeed(tmp);

}

bool Collider::isCollide(Collider col){
  bool res=false;

  #ifdef COLLIDER_DEBUG
  std::cout << "COLLSOLV" << std::endl;
  #endif

  if(_typ== box){
    if(col.getColTyp()== box){
      res=solveBB(*this, col);
    }else if(col.getColTyp()== sphere){
      res=solveBS(*this, col);
    }else{
      //error
    }
  }else if(_typ== sphere){
    if(col.getColTyp()== sphere){
      res=solveSS(*this, col);
    }else if(col.getColTyp()== box){
      res=solveBS(col, *this);
    }
  }

  return res;

}

bool Collider::solveBB(Collider c1, Collider c2){
  bool res = true;

  Vector3 c1Dim=c1.getBDim();
  Vector3 c2Dim=c2.getBDim();
  Vector3 c1Center=c1.getPos();
  Vector3 c2Center=c2.getPos();

  if(c1Center.x+c1Dim.x < c2Center.x-c2Dim.x || c1Center.x-c1Dim.x > c2Center.x+c2Dim.x ){ //Pas de col en X
    if(c1Center.y+c1Dim.y < c2Center.y-c2Dim.y || c1Center.y-c1Dim.y > c2Center.y+c2Dim.y){ //Pas de col en Y
      if(c1Center.z+c1Dim.z < c2Center.z-c2Dim.z || c1Center.z-c1Dim.z > c2Center.z+c2Dim.z){ //Pas de col en Z
        res = false; //Donc pas de col
      }
    }
  }

  return res;

}

bool Collider::solveBS(Collider box, Collider sph){

  bool res=true;

  Vector3 dist=box.getPos()-sph.getPos();

  dist.x = abs(dist.x);
  dist.y = abs(dist.y);
  dist.z = abs(dist.z);

  Vector3 boxCenter=box.getPos();
  Vector3 sphCenter=sph.getPos();

  double sphR = sph.getSDim();

  Vector3 boxDim = box.getBDim();

  if(dist.x > boxDim.x+sphR ){
    if(dist.y > boxDim.y+sphR ){
      if(dist.z > boxDim.z+sphR ){
        res=false;
      }
    }
  }

  return res;
}

bool Collider::solveSS(Collider c1, Collider c2){
  bool res=false;

  #ifdef COLLIDER_DEBUG
  std::cout <<"COLLSPH ENTER" <<std::endl;
  #endif

  double dist=(c1.getPos()-c2.getPos()).magnitude(); //Distance des centres
  //Si distance plus

  #ifdef COLLIDER_DEBUG
  std::cout << "COLLSPH :" << dist << ":" << c1.getSDim()+c2.getSDim() <<std::endl;
  #endif
  if(dist < c1.getSDim()+c2.getSDim()) res = true;

  return res;
}
