CC=g++
LIBS=-lIrrlicht -lGL -lm
EXE=PoutinePhysics



all : clean base.o bouncingball gravity orbit control test

base.o : vector3.o physicalObject.o collider.o matrix.o quaternion.o input.o
	ld -r vector3.o collider.o matrix.o quaternion.o  physicalObject.o input.o -o base.o

vector3.o :
	$(CC) -c vector3.cpp

matrix.o :
	$(CC) -c matrix.cpp

physicalObject.o :
	$(CC) -c physicalObject.cpp

collider.o :
	$(CC) -c collider.cpp

quaternion.o :
	$(CC) -c quaternion.cpp

input.o :
	$(CC) -c input.cpp

bouncingball : base.o PoutineBall.cpp
	$(CC) PoutineBall.cpp base.o $(LIBS) -o PoutineBall

gravity : base.o PoutineGravity.cpp
	$(CC) PoutineGravity.cpp base.o $(LIBS) -o PoutineGravity

orbit : base.o PoutineOrbit.cpp
	$(CC) PoutineOrbit.cpp base.o $(LIBS) -o PoutineOrbit


test : base.o PoutinePhysics.cpp
	$(CC) PoutinePhysics.cpp base.o $(LIBS) -o PoutineTest

control : base.o PoutineControl.cpp
	$(CC) PoutineControl.cpp base.o $(LIBS) -o PoutineControl

clean :
	rm  -f PoutineControl
	rm  -f PoutineOrbit
	rm  -f PoutineBall
	rm  -f PoutineGravity
	rm  -f *.o
