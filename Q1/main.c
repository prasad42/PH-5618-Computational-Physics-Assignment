#include "header.h"

int main(){
  ////////
  //Input
  ///////
  float Matrix[3][3]
  = {
    {1, 2, 3},
    {3, 2, 1},
    {2, 1, 3}
  };
  //Print Matrix
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      printf("Matrix[%d][%d]=%f\n", i, j, Matrix[i][j]);
    }
  }
  //Find trace
  float tr = 1;
  for (int i = 0; i < 3; i++){
    tr = tr * Matrix[i][i];
  }
  printf("\nTrace of above matrix: %f\n", tr);
  //Find determinant
  float det = 0;
  float r1[3], r2[3], r3[3];
  for (int i = 0; i < 3; i++){
    r1[i] = Matrix[0][i];
  }
  for (int i = 0; i < 3; i++){
    r2[i] = Matrix[1][i];
  }
  for (int i = 0; i < 3; i++){
    r3[i] = Matrix[2][i];
  }
  for (int i = 0; i < 3; i++){
    det += r1[i] * (r2[(i+1)%3] * r3[(i+2)%3] - r2[(i+2)%3] * r3[(i+1)%3]);  
  }
  printf("Determinant of above matrix: %f\n\n", det);
  //Find inverse
  //Cofactor Matrix
  float cMatrix[3][3];
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      cMatrix[i][j] = (Matrix[(i+1)%3][(j+1)%3] * Matrix[(i+2)%3][(j+2)%3] - Matrix[(i+1)%3][(j+2)%3] * Matrix[(i+2)%3][(j+1)%3]);
    }
  }
  //Print Cofactor Matrix
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      printf("Cofactor Matrix[%d][%d]=%f\n", i, j, cMatrix[i][j]);
    }
  }
  printf("\n");
  //Inverse Matrix
  float iMatrix[3][3];
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      iMatrix[i][j] = cMatrix[j][i]/det;
    }
  }
  //Print Inverse Matrix
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      printf("Inverse Matrix[%d][%d]=%f\n", i, j, iMatrix[i][j]);
    }
  }
  printf("\n");
  //Check if matrix and its inverse gives identity
  float id[3][3];
  for (int i = 0; i < 3; i++){
   for (int j = 0; j < 3; j++){
     for (int k = 0; k < 3; k++){
       id[i][j] += iMatrix[i][k] * Matrix[k][j];
     }
   }
  }
  //Print Identity Matrix
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      printf("Matrix*Inverse[%d][%d]=%f\n", i, j, id[i][j]);
    }
  }
}
