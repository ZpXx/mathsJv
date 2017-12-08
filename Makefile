CC=g++
LIBS=-lIrrlicht -lGL -lm
EXE=PoutinePhysics


all : vector3.o physicalObject.o matrix.o
	$(CC) PoutinePhysics.cpp physicalObject.o vector3.o $(LIBS) -o $(EXE)

vector3.o :
	$(CC) -c vector3.cpp

matrix.o :
	$(CC) -c matrix.h

physicalObject.o :
	$(CC) -c physicalObject.cpp

clean :
	rm $(EXE)
	rm *.o
	rm *.gch
