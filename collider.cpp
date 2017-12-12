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
  Vector3 _parentSpd = _parent->getSpd();

  //V1
  tmp = col.getParent()->getSpd()-_parent->getSpd();
  tmp*= col.getParent()->getMass()*coef;
  tmp+=_parent->getSpd()*_parent->getMass();
  tmp+=col.getParent()->getSpd()*col.getParent()->getMass();
  tmp/=col.getParent()->getMass()+_parent->getMass();
  _parent->setSpeed(tmp);

  //V2
  tmp = _parentSpd - col.getParent()->getSpd();
  tmp*= _parent->getMass()*coef;
  tmp+=_parentSpd*_parent->getMass();
  tmp+=col.getParent()->getSpd()*col.getParent()->getMass();
  tmp/=col.getParent()->getMass()+_parent->getMass();
  col.getParent()->setSpeed(tmp);

  #ifdef COLLIDER_DEBUG
    std::cout << "VCOLLIDE :\nV2 : ";
    col.getParent()->getSpd().log();
    std::cout << std::endl;
    std::cout << "V1 : " ;
    _parent->getSpd().log();
    std::cout << std::endl;
  #endif

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
  bool res = false;

  #ifdef COLLIDER_DEBUG
    std::cout <<"COLLBOX ENTER" <<std::endl;
  #endif

  Vector3 c1Dim=c1.getBDim();
  Vector3 c2Dim=c2.getBDim();
  Vector3 c1Center=c1.getPos();
  Vector3 c2Center=c2.getPos();

  bool colX = oneAxisCollide(c1Center.x-c1Dim.x, c1Center.x+c1Dim.x, c2Center.x-c2Dim.x, c2Center.x+c2Dim.x  ) ;
  bool colY = oneAxisCollide(c1Center.y-c1Dim.y, c1Center.y+c1Dim.y, c2Center.y-c2Dim.y, c2Center.y+c2Dim.y  ) ;
  bool colZ = oneAxisCollide(c1Center.z-c1Dim.z, c1Center.z+c1Dim.z, c2Center.z-c2Dim.z, c2Center.z+c2Dim.z  ) ;

  #ifdef COLLIDER_DEBUG
    std::cout << "COLLBOX AXIS BOOL" << colX << ":" << colY << ":" << colZ << std::endl;
  #endif

  if(colX && colY && colZ) res = true;

  return res;

}

bool Collider::oneAxisCollide(double m1, double M1, double m2, double M2){
  bool res = false;
  #ifdef COLLIDER_DEBUG
    std::cout << "## Axis Interval " << m1 << ":" << M1 << ":" << m2 << ":" << M2 << std::endl;
  #endif
  if(M1>=m2 && M1<=M2) res = true;
  else if(m1<=M2 && m1>=m2) res = true;
  else res = false;

  return res;
}

bool Collider::solveBS(Collider box, Collider sph){

  bool res=false;

  Vector3 dist=box.getPos()-sph.getPos();

  #ifdef COLLIDER_DEBUG
  std::cout <<"COLLBS ENTER" <<std::endl;
  #endif


  dist.x = abs(dist.x);
  dist.y = abs(dist.y);
  dist.z = abs(dist.z);

  Vector3 boxCenter=box.getPos();
  Vector3 sphCenter=sph.getPos();

  double sphR = sph.getSDim();

  Vector3 boxDim = box.getBDim();

  bool colX = oneAxisCollide(boxCenter.x-boxDim.x, boxCenter.x+boxDim.x, sphCenter.x-sphR,sphCenter.x+sphR);
  bool colY = oneAxisCollide(boxCenter.y-boxDim.y, boxCenter.y+boxDim.y, sphCenter.y-sphR,sphCenter.y+sphR);
  bool colZ = oneAxisCollide(boxCenter.z-boxDim.z, boxCenter.z+boxDim.z, sphCenter.z-sphR,sphCenter.z+sphR);

  #ifdef COLLIDER_DEBUG
    std::cout << "COLLBS AXIS BOOL" << colX << ":" << colY << ":" << colZ << std::endl;
  #endif

  if(colX && colY && colZ) res=true;

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
