CC=g++
LIBS=-lIrrlicht -lGL -lm
EXE=PoutinePhysics


all : vector3.o physicalObject.o collider.o
	$(CC) PoutinePhysics.cpp physicalObject.o vector3.o collider.o $(LIBS) -o $(EXE)

vector3.o :
	$(CC) -c vector3.cpp

matrix.o :
	$(CC) -c matrix.cpp

physicalObject.o :
	$(CC) -c physicalObject.cpp

collider.o :
	$(CC) -c collider.cpp

clean :
	rm $(EXE)
	rm *.o
	rm *.gch
