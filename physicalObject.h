#ifndef PHYSICAL_OBJECT
#define PHYSICAL_OBJECT
#include <irrlicht/irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class physicalObject {

  private :
    IAnimatedMeshSceneNode* node;
    vector3 pos;
    vector3 eulerPos;
    /*TODO
      Collider col;
      Matrice rot; / Vector3 rot
    */

  public :
    physicalObject(IAnimatedMeshSceneNode* mesh){
      node = mesh;
    }

    IAnimatedMeshSceneNode* getAnimatedMeshSceneNode(){ return node; }
    void update(){
      node->setPosition(pos);
      node->setRotation(eulerPos);
    }

};

#endif
