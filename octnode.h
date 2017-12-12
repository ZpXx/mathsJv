#ifndef OCTNODE
#define OCTNODE
#include <iostream>
#include <cmath>
#include <irrlicht/irrlicht.h>

// TAKOYAKI ! TAKOYAKI! OSAKA NO TAKOYAKI WO TABETAI!!
class Octnode{

private:
  float bounds_x[2];
  float bounds_y[2];
  float bounds_z[2];

  Octnode** children;
  Octnode*  parent; // OCTODAD
public:

  Octnode(float mix, float max, float miy, float may, float miz, float maz){
    bounds_x[0]=mix;
    bounds_x[1]=max;
    bounds_y[0]=miy;
    bounds_y[1]=may;
    bounds_z[0]=miz;
    bounds_z[1]=maz;
    parent=NULL; /* I AM ROOT! THE FATHER OF ALL NODES,
                  * ORIGIN OF THE TREE,
                  * THE GREAT DETECTING SQUARE!
                  * NOW KNEEL MORTAL,
                  * FOR MY WRATH IS SWIFT,
                  * AND MY MIGHT IS AS GREAT AS MY STRENGTH!
                  * I WON'T SHOW YOU ANY MERCY,
                  * SHOULD YOU CHOOSE TO FACE ME ON THE BATTLEFIELD!! */
  }
  Octnode(Octnode *p, int n){
    parent=p;
    if (n%2){
      bounds_x[0]=p->bounds_x[0];
      bounds_x[1]=((p->bounds_x[0]+p->bounds_x[1])/2);
    } else {
      bounds_x[0]=((p->bounds_x[0]+p->bounds_x[1])/2);
      bounds_x[1]=p->bounds_x[1];
    }
    if (n%4==1 || n%4==2){
      bounds_y[0]=p->bounds_y[0];
      bounds_y[1]=((p->bounds_y[0]+p->bounds_y[1])/2);
    } else {
      bounds_y[0]=((p->bounds_y[0]+p->bounds_y[1])/2);
      bounds_y[1]=p->bounds_y[1];
    }
    if (n>4){
          bounds_z[0]=p->bounds_z[0];
          bounds_z[1]=((p->bounds_z[0]+p->bounds_z[1])/2);
    } else {
          bounds_z[0]=((p->bounds_z[0]+p->bounds_z[1])/2);
          bounds_z[1]=p->bounds_z[1];
    }
  }


  float GetMiX(){return bounds_x[0];}
  float GetMaX(){return bounds_x[1];}
  float GetMiY(){return bounds_y[0];}
  float GetMaY(){return bounds_y[1];}
  float GetMiZ(){return bounds_z[0];}
  float GetMaZ(){return bounds_z[1];}
  void Expand();
  void Destroy();
  Octnode* GetChildren(int n){return children[n];}
};

#endif
