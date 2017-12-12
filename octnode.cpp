#include "octnode.h"




void Octnode::Expand(){                                                       // Who's that man with the three piece suit?
children=(Octnode**)malloc(8*sizeof(Octnode*));                               // Makin' a doll with a log and fruit
int i=0;                                                                      // Who's that man with the eight strong legs?
for (i=0;i<8;i++){                                                            // Tried to make me breakfast but he broke my eggs
  children[i]=&(Octnode(this,i));
  }                                                                           // Octodad - nobody suspects a thing
}
// ALWAYS DESTROY NEAREST NODE TO ROOT!                                       // Who's that man with the hard, hard beak?
void Octnode::Destroy(){                                                      // Three feet tall with a soft physique
    if (children!=NULL){                                                      // How's a man like that man feel?
      int i=0;                                                                // Running for his life from a moray eel
      for (i=0;i<8;i++){
      *children[i].Destroy();                                                 // Octodad - nobody suspects a thing
      }
      children=NULL;                                                          // Octodad - he's got a good thing going
    }
  }
