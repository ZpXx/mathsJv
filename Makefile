CC=g++
LIBS=-lIrrlicht -lGL -lm
EXE=PoutinePhysics


all : vector3.o matrix.o physicalObject.o
	$(CC) PoutinePhysics.cpp physicalObject.o $(LIBS) -o $(EXE)

vector3.o :
	$(CC) -c vector3.h

matrix.o :
	$(CC) -c matrix.h

physicalObject.o :
	$(CC) -c physicalObject.cpp

clean :
	rm $(EXE)
	rm *.o
