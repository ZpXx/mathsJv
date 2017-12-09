#ifndef MATRIX
#define MATRIX

#include <cmath>
#include <iostream>
#include "vector3.h"

class Matrix{
    int size;

public:
  float** data;

  //Creates a new MATRIX of sizeXsize
  Matrix(const int s){
    if (s!=0){
    size=s;
    int i=0,j=0;
    data=(float**)malloc(s*sizeof(float*));
    for (i=0;i<s;i++){
      data[i]=(float*)malloc(s*sizeof(float));
      for (j=0;j<s;j++){
        data[i][j]=0;
      }
    }
  }
  else{
    size=0;
    data=NULL;
  }
}
// properly destroy the MATRIX
void Destroy();
Matrix operator+(Matrix m2);
Matrix operator*(Matrix m2);
Vector3 operator*(Vector3 v);
Matrix operator*(float f);
Matrix Transpose();
Matrix Invert();
Matrix Minor(int x, int y);
float Det();
int Get_size(){
  return size;
}

};

#endif
