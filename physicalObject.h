#ifndef PHYSICAL_OBJECT
#define PHYSICAL_OBJECT
#include <irrlicht/irrlicht.h>
#include <list>
#include "vector3.h"
#include "collider.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class physicalObject {

  private :
    IAnimatedMeshSceneNode* node;
    Vector3 pos;
    Vector3 accel;
    Vector3 spd;
    Vector3 angularAccel;
    Vector3 angularSpd;
    Vector3 eulerRot;
    real mass;
    std::list<Vector3> forceQ; //List of force for next update
    Collider* _col;

    /*TODO
      Quaternion;
    */

  public :


    physicalObject(IAnimatedMeshSceneNode* mesh){
      node = mesh;
      pos = Vector3();
      accel = Vector3();
      spd = Vector3();
      eulerRot = Vector3();
      forceQ = std::list<Vector3>();
      mass = 1;
    }

    IAnimatedMeshSceneNode* getAnimatedMeshSceneNode(){ return node; }

    void setPos(Vector3 vect){pos = vect;}
    void setRot(Vector3 vect){eulerRot = vect;}
    void setSpeed(Vector3 vect){spd = vect;}
    void setAccel(Vector3 vect){ accel= vect;}

    Vector3 getAngularAccel(){return angularAccel;}
    Vector3 getAngularSpd(){return angularSpd;}
    Vector3 getEulerAngle(){return eulerRot;}

    void setAngularAccel(Vector3 v){angularAccel = v;}
    void setAngularSpd(Vector3 v){angularSpd = v;}
    void setEulerRot(Vector3 v){eulerRot = v;}

    Vector3 getPos(){return pos;}
    Vector3 getRot(){return eulerRot;}
    Vector3 getAccel(){return pos;}
    Vector3 getSpd(){return spd;}
    double getMass(){return mass;}
    void setMass(double m){mass = m;}
    Collider* getCol(){return _col;}

    // Queue a force for next update force treated in adding order
    void addForce(Vector3 force){forceQ.push_back(force);}
    void addCollider(Vector3);
    void addCollider(double);

    private :
      //TODO Init Collider
      void treatForce(real); //Appli all forces in forceQ to the object (update spd)
      Vector3 integrate(Vector3, real); //return integrated vector
      void treatSpd(real);


      void treatAngularAccel(real);
      void treatAngularSpd(real);

    public :

      void update(real delta);
};

#endif
