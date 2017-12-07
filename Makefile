CC=g++
LIBS=-lIrrlicht -lGL
EXE=PoutinePhysics

all :
	$(CC) PoutinePhysics.cpp $(LIBS) -o $(EXE)

clean :
	rm $(EXE)
	rm *.o
