#ifndef MATRIX
#define MATRIX

#include <cmath>

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
  void Destroy(){
    int i=0;
    for (i=0;i<size;i++){
      free(data[i]);
    }
    free(data);
  }

//Addition of two MATRIXS
Matrix operator+(Matrix m2){
    if (size!=m2.Get_size() || size==0 ||m2.Get_size()==0 ){
    fprintf(stderr,"Addition de deux matrices de tailles differentes! Ou de deux matrices de taille 0!\n");
    Matrix r=Matrix(0);
    return r;
  }
  Matrix m = Matrix(size);
  for (int i=0;i<size;i++){
    for (int j=0;j<size;j++){
      m.data[i][j]=data[i][j]+m2.data[i][j];
    }
  }
  return m;
}

//Matricial Product
Matrix operator*(Matrix m2){
  if (size!=m2.Get_size() || size==0 || m2.Get_size()==0){
    fprintf(stderr, "Multiplication de deux matrices de tailles differentes ou de taille 0!\n");
    return Matrix (0);
  }
  Matrix m =Matrix(size);
  int i=0,j=0,k=0;
  for (i=0;i<size;i++){
    for (j=0;j<size;j++){
      for (k=0;k<size;k++){
        m.data[i][j]+=data[i][k]*m2.data[k][j];
      }
    }
  }
  return m;
}

//Transpose

Matrix Transpose(){
  if (size==0){
    fprintf(stderr, "Trasnsposition d'une matrices de taille 0!\n");
    return Matrix(0);
  } else {
    Matrix res = Matrix(size);
    int i=0,j=0;
    for (i=0;i<size;i++){
      for (j=0;j<size;j++){
        res.data[i][j]=data[j][i];
      }
    }
    return res;
  }
}

// GETTER

  int Get_size(){
    return size;
  }
};

#endif
