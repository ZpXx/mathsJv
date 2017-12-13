CC=g++
LIBS=-lIrrlicht -lGL -lm
EXE=PoutinePhysics


all : clean base.o bouncingball

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

bouncingball : base.o PoutinePhysics.cpp
	$(CC) PoutinePhysics.cpp base.o $(LIBS) -o bouncingball

clean :
	rm  -f $(EXE)
	rm  -f *.o
