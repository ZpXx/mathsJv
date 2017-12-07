CC=g++
LIBS=-lIrrlicht -lGL -lm
EXE=PoutinePhysics


all : vector3.o
	$(CC) PoutinePhysics.cpp $(LIBS) -o $(EXE)

vector3.o :
	$(CC) -c vector3.h

clean :
	rm $(EXE)
	rm *.o
