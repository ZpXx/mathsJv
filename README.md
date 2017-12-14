# Projet 8INF935

Groupe : BOURDELAS Pablo (BOUP07029506) - RUGGERIO Nicolas (RUGN) - RYCKAERT Guillame (RYCG)

---

### Compilation et usage


### Compilation

Le compilateur utiliser pour le projet est g++.
La compilation du code à était testé dans ça version 7.2.1 sous ArchLinux et Manjaro.

Un Makefile est mis à disposition pour la compilation du projet.

* "make all" construit toute les démo
* "make nom_de_la_demo" construit une demo spécifique. Les démo bouncingball, gravity, orbit, test, et control sont disponible.

#### Usage

 Une fois build chaque démo est disponible sous la forme d'un exécutable avec un nom de la forme : Poutine[nom_de_la_demo]

#### Dépendance

Pour le rendu graphique le projet utilise Irrlicht.

Le moteur peut être trouver ici : [irrlicht](irrlicht.sourceforge.net/?page_id=10)

Le moteur dispose d'un guide d'installation officiel (Linux, Windows, Mac OS X) ici : [guide officiel](http://www.irrlicht3d.org/wiki/index.php?n=Main.InstallingIrrlicht)

Note : le moteur est disponible sous forme de paquet pour Archlinux et dérivé (Manjaro, etc) dans le repository community sous le nom "irrlicht". Irrlicht est aussi disponible sous Mac OS avec brew sous le nom "irrlicht".

#### Description des Demo :

  * Bouncingball, montre une balle de masse 1 rebondissant sur une balle de masse 8000. Un vecteur de force vers la gauche est appliquer à la balle de masse 1.

  * Orbit, montre des sphéres décrivant des orbites.

  * Control, permet de controlé une balle. Deux autre balle sont présente dans l'espace.

  * Test, prensente une accélération angulaire constante.

  * Gravity, reprend la configuration de bouncingball mais en ajoutant une force vers le point (0,0,0).

### Description des fichiers

Pour ceux projet nous avons implémenter plusieurs structure mathématique et principe physique.
Voici une description courte du contenu des fichiers:

 * Les vecteurs dans vector3.h et vector3.cpp

 * Les Matrices dans matrix.h et matrix.cpp

 * Les octree dans octnode.h et octnode.cpp

 * La résolution de collision dans collider.h et collider.cpp

 * Les quaternion dans quaternion.h et quaternion.cpp

* physicalObject.h et physicalObject.cpp contient la classe permetant de décrire un objet sur le quel s'applique la physique. (dont la boucle de mise à jour d'un objet)

* les fichiers Poutine[Ball|Control|Orbit|Physics].cpp contient le code des differente démo présentées. (on y trouve les boucles principale de mise à jour)  

* Les fichier \*.stl contient des models 3D
