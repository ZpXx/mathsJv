#ifndef PHYSICAL_OBJECT
#define PHYSICAL_OBJECT
#include <irrlicht/irrlicht.h>
#include <list>
#include "vector3.h"

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
    Vector3 eulerRot;
    real mass;
    std::list<Vector3> forceQ; //List of force for next update

    /*TODO
      Collider col;
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
    void setAccel(Vector3 vect){ accel= vect;}

    Vector3 getPos(){return pos;}
    Vector3 getRot(){return eulerRot;}
    Vector3 getAccel(){return pos;}

    // Queue a force for next update force treated in adding order
    void addForce(Vector3 force){forceQ.push_back(force);}

    private :
      //TODO Init Collider
      void treatForce(real); //Appli all forces in forceQ to the object (update spd)
      Vector3 integrate(Vector3, real); //return integrated vector
      void treatSpd(real);
    public :

    vector3df Vector3Tovector3df(Vector3 v);
    void update(real delta);
};

#endif
