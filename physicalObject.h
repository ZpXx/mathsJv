#ifndef PHYSICAL_OBJECT
#define PHYSICAL_OBJECT
#include <irrlicht/irrlicht.h>
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
    List<Vector3> forceQ; //List of force for next update

    /*TODO
      Collider col;
      Quaternion;
    */

  public :
    physicalObject(IAnimatedMeshSceneNode* mesh){
      node = mesh;
      pos = new Vector3();
      accel = new Vector3();
      spd = new Vector3();
      eulerRot = new Vector3();
      forceQ = new List<Vector3>();
    }

    IAnimatedMeshSceneNode* getAnimatedMeshSceneNode(){ return node; }

    void setPos(Vector3 vect){pos = vect}
    void setRot(Vector3 vect){eulerPos = vect}
    void setAccel(Vector3 vect){ = vect}

    Vector3 getPos(){return pos;}
    Vector3 getRot(){return eulerRot;}
    Vector3 getAccel(){return pos;}

    // Queue a force for next update force treated in adding order
    void addForce(Vector3 force){forceQ.push_back(force);}

    private :
      //TODO Init Collider
    public :

    void update(real delta){
      //Treat force
      //Treat spd
      //Maj aff
      node->setPosition(pos);
      node->setRotation(eulerRot);
    }
};

#endif
