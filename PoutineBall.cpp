#include <irrlicht/irrlicht.h>
#include <iostream>
#include "vector3.h"
#include "physicalObject.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int main(void){

		std::cout << "HelloWorld" << std::endl ; // Toi même tu sais

    IrrlichtDevice *device = createDevice( // creation device
        EDT_OPENGL,                       // l'API est OpenGL
        dimension2d<u32>(320,260),       // taille de la fenetre 800x600
        32, false, true, false, 0);		// Profondeur de couleur, fullscreen, stencil buffer, vsync, event (0 sur ce device)

		if(!device)																			// Crash si device pas disponible
			return 1;

		device->setWindowCaption(L"- PoutineBall -"); //Nom de la fenetre

    IVideoDriver* driver =
        device->getVideoDriver();                    // creation driver
    ISceneManager *smgr =
        device->getSceneManager ();                  // creation scene manager
		IGUIEnvironment* guienv =
		 		device->getGUIEnvironment();								// on prend le gui

		guienv->addStaticText(L"Cette simulation vous est offert par les Poutines au Boivin", rect<s32>(10,10,260,22), true);
		// Text, rectangle de placement

		IAnimatedMesh* mesh = smgr->getMesh("skull.stl"); // On charge le mesh
		if(!mesh){
			device->drop();  //On crash tout si le mesh n'est pas chargé
			return 1;
		}

		IAnimatedMesh* mesh2 = smgr->getMesh("skull.stl"); // On charge le mesh
		if(!mesh2){
			device->drop();  //On crash tout si le mesh n'est pas chargé
			return 1;
		}


		IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode(mesh); // Ajout du mesh à la scene
		node->addShadowVolumeSceneNode();

		if(node){
			node->setMaterialFlag(EMF_LIGHTING, true); //On déactive la lumiére dynamic
			node->setMaterialFlag(EMF_GOURAUD_SHADING, true);
		}

			IAnimatedMeshSceneNode* node2 = smgr->addAnimatedMeshSceneNode(mesh2); // Ajout du mesh à la scene
		node2->addShadowVolumeSceneNode();

		if(node2){
			node2->setMaterialFlag(EMF_LIGHTING, true); //On déactive la lumiére dynamic
			node2->setMaterialFlag(EMF_GOURAUD_SHADING, true);
		}


		ILightSceneNode *light = smgr->addLightSceneNode();

		if(light){
				light->setPosition(vector3df(40,40,40));
		}

    smgr->addCameraSceneNode (0,             // ajout camera fixe
        vector3df (0,380,0),								//Position de la Camera
        vector3df (0,0,0));									// Point vers laquelle elle est diriger

	  int pos=0, framecount = 0;

		u32 start=0, delta=0;

		physicalObject Objt = physicalObject(node);	// Init Obj physique
		Objt.setSpeed(Vector3(0,0,20));							//On lui donne une vitesse initale
		Objt.setPos(Vector3(0,0,0));

		physicalObject Objt2 = physicalObject(node2);
		Objt2.setSpeed(Vector3(0,0,0));
		Objt2.setPos(Vector3(0,0,100));
		Objt2.setMass(8000);

		device->getTimer()->setSpeed(1.0f);				//Vitesse du temps virtuel

		Vector3 Gravity = Vector3(0,9,0);

		//Objt.setPos(Vector3(180,0,0));
		//Objt.setSpeed(Vector3(0,0,-50));



		Objt.addCollider(Vector3(20,20,20));
		Objt2.addCollider(20);


    while (device->run()) {                          // la boucle de rendu
				driver->beginScene(                          // demarre le rendu
            true,                                    // clear back-buffer
            true,                                    // clear z-buffer
            SColor(255,100,101,140));    						 // fond violet
				//node->setRotation(vector3df(0,pos,pos));
				//node->setPosition(vector3df(0,0,0));
				delta=device->getTimer()->getTime()-start;
				if(delta>16){												//On maj la physique tout les ~1/60 de secondes
					/*std::cout << "Vector Gravity : " ;
					Gravity.log();
					Objt.addForce( Gravity.rotate_toward( Objt.getPos(), Vector3(0,0,0)) ); //Gravité \o/ (obj de masse 1)
					*/
					if(Objt.getCol()->isCollide(*(Objt2.getCol()))){
						std::cout << "Collide !" << std::endl;
						Objt.getCol()->appliColide(*(Objt2.getCol()),1.0);
					}
					Objt.addForce(Vector3(0,0,9.8));
					Objt2.update(delta/1000.0);
					Objt.update(delta/1000.0);				// delta est en ms on passe en s
					start=device->getTimer()->getTime();
				}
				smgr->drawAll ();									//Rendu scene
				guienv->drawAll();                // Rendu Gui
        driver->endScene ();              // affiche le rendu
				if(++pos>=360) pos=0;
    }

    device->drop ();                                 // liberation de la memoire
    return 0;
}
