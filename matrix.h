#ifndef MATRIX
#define MATRIX

#include <cmath>

class Matrix{
  float** data;
  int size;
public:

  //Creates a new MATRIX of sizeXsize
  Matrix(const int s){
    size=s;
    int i=0;
    data=(float**)malloc(s*sizeof(float*));
    for (i=0;i<s;i++){
      data[i]=(float*)malloc(s*sizeof(float));
    }
  }

// properly destroy the MATRIX
  void Destroy(){
    int i=0;
    for (i=0;i<size;i++){
      free(data[i]);
    }
    free(data);
  }

//Addition of two MATRIXS
Matrix operator+(Matrix m2){
  Matrix m= new Matrix(size);
  for (int i=0;i<size;i++){
    for (int j=0;j<size;j++){
      m.data[i][j]=data[i][j]+m2.data[i][j];
    }
  }
  return m;
}


};

#endif
