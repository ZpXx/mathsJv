#include "matrix.h"


// properly destroy the MATRIX
  void Matrix::Destroy(){
    int i=0;
    for (i=0;i<size;i++){
      free(data[i]);
    }
    free(data);
    return;
  }

//Addition of two MATRIXS
Matrix Matrix::operator+(Matrix m2){
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
Matrix Matrix::operator*(Matrix m2){
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

//Matrice X Vector
Vector3 Matrix::operator*(Vector3 v){
  if (size!=3){
    fprintf(stderr, "Multiplication de vecteur par une matrice de taille !=3 ! \n");
    return Vector3();
  }
  float x,y,z;
  x=v.x*data[0][0]+v.y*data[0][1]+v.z*data[0][2];
  y=v.x*data[1][0]+v.y*data[1][1]+v.z*data[1][2];
  z=v.x*data[2][0]+v.y*data[2][1]+v.z*data[2][2];
  return Vector3(x,y,z);
}

Matrix Matrix::operator*(float f){
  if (size==0){
    fprintf(stderr, "Tentaive de Multiplication d'une matrice nulle par un scalaire!\n");
    return Matrix(0);
  }
  Matrix m = Matrix(size);
  for (int i=0;i<size;i++){
    for (int j=0;j<size;j++){
      m.data[i][j]=data[i][j]*f;
    }
  }
  return m;
}

//Transpose

Matrix Matrix::Transpose(){
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


float Matrix::Det(){
  if (size==0){
    fprintf(stderr, "Calcul du determinant d'une matrice nulle!\n");
    return (0);
  }
  else if (size==1){
    return (data[0][0]);
  }
  else if (size==2){
    return (data[0][0]*data[1][1]-data[0][1]*data[1][0]);
  }
  else if (size==3){
    float a=data[0][0]*data[1][1]*data[2][2]+data[1][0]*data[2][1]*data[0][2]+data[2][0]*data[0][1]*data[1][2];
    float b=data[2][0]*data[1][1]*data[0][2]+data[0][0]*data[2][1]*data[1][2]+data[1][0]*data[0][1]*data[2][2];
    return (a-b);
  } else {
    /*Pour une Matrice |a1 a2 a3 a4|
    *                  |b1 b2 b3 b4|
    *                  |c1 c2 c3 c4|
    *                  |d1 d2 d3 d4|
    */
    float min_det[4];
    Matrix minor= Matrix (3);
    int i=0,j=0;
    for (i=1;i<4;i++){
      for (j=1;j<4;j++){
        minor.data[i-1][j-1]=data[i][j];
      }
    }
    min_det[0]=minor.Det();
    /*  mineur 1: |b2 b3 b4|
    *             |c2 c3 c4|
    *             |d2 d3 d4|
    */
    for (i=1;i<4;i++){
      minor.data[0][i-1]=data[0][i];
    }
    min_det[1]=minor.Det();
    /* mineur 2 : |b1 b3 b4|
    *             |c1 c3 c4|
    *             |d1 d3 d4|*/
    for (i=1;i<4;i++){
      minor.data[1][i-1]=data[1][i];
    }
    min_det[2]=minor.Det();
    /* mineur 3 : |b1 b2 b4|
    *             |c1 c2 c4|
    *             |d1 d2 d4|*/
    for (i=1;i<4;i++){
      minor.data[2][i-1]=data[2][i];
    }
    min_det[3]=minor.Det();
    /* mineur 4 : |b1 b2 b3|
    *             |c1 c2 c3|
    *             |d1 d2 d3|*/
    minor.Destroy();
    for (i=0;i<4;i++){
      min_det[i]*=data[i][0];
    }
    return (min_det[1]+min_det[3]-min_det[0]-min_det[2]);
  }
}
