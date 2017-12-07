#include <irrlicht/irrlicht.h>
#include <iostream>

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

		device->setWindowCaption(L"- PoutinePhysics -"); //Nom de la fenetre

    IVideoDriver* driver =
        device->getVideoDriver();                    // creation driver
    ISceneManager *smgr =
        device->getSceneManager ();                  // creation scene manager
		IGUIEnvironment* guienv =
		 		device->getGUIEnvironment();								// on prend le gui

		guienv->addStaticText(L"Cette simulation vous est offert par les Poutine au Boivin", rect<s32>(10,10,260,22), true);
		// Text, rectangle de placement

		IAnimatedMesh* mesh = smgr->getMesh("skull.stl"); // On charge le mesh
		if(!mesh){
			device->drop();  //On crash tout si le mesh n'est pas chargé
			return 1;
		}

		IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode(mesh); // Ajout du mesh à la scene
		node->addShadowVolumeSceneNode();

		if(node){
			node->setMaterialFlag(EMF_LIGHTING, true); //On déactive la lumiére dynamic
			node->setMaterialFlag(EMF_GOURAUD_SHADING, true);
		}

		ILightSceneNode *light = smgr->addLightSceneNode();

		if(light){
				light->setPosition(vector3df(40,40,40));
		}

    smgr->addCameraSceneNode (0,             // ajout camera fixe
        vector3df (0,60,-80),
        vector3df (0,0,0));

	  int pos, framecount = 0;

		u32 start;

    while (device->run()) {                          // la boucle de rendu
			  driver->beginScene(                          // demarre le rendu
            true,                                    // clear back-buffer
            true,                                    // clear z-buffer
            SColor(255,100,101,140));    						 // fond violet
				node->setRotation(vector3df(0,pos,pos));
				node->setPosition(vector3df(0,0,50));
        smgr->drawAll ();									//Rendu scene
				guienv->drawAll();                // Rendu Gui
        driver->endScene ();              // affiche le rendu
				if(++pos>=360) pos=0;
    }

    device->drop ();                                 // liberation de la memoire
    return 0;
}
