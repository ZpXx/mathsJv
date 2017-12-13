CC=g++
LIBS=-lIrrlicht -lGL -lm
EXE=PoutinePhysics


all : clean base.o bouncingball gravity

base.o : vector3.o physicalObject.o collider.o matrix.o quaternion.o
	ld -r vector3.o collider.o matrix.o quaternion.o  physicalObject.o -o base.o

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

bouncingball : base.o PoutineBall.cpp
	$(CC) PoutineBall.cpp base.o $(LIBS) -o PoutineBall

gravity : base.o PoutineGravity.cpp
	$(CC) PoutineGravity.cpp base.o $(LIBS) -o PoutineGravity

orbit : base.o PoutineOrbit.cpp
	$(CC) PoutineOrbit.cpp base.o $(LIBS) -o PoutineOrbit
clean :
	rm  -f $(EXE)
	rm  -f *.o
