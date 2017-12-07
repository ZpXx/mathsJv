CC=g++
LIBS=-lIrrlicht -lGL -lm
EXE=PoutinePhysics


all : vector3.o matrix.o
	$(CC) PoutinePhysics.cpp $(LIBS) -o $(EXE)

vector3.o :
	$(CC) -c vector3.h

matrix.o :
	$(CC) -c matrix.h

clean :
	rm $(EXE)
	rm *.o
