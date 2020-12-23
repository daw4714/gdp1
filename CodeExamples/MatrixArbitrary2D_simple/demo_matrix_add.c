// Matrixaddition
//
// 2 Matrizen
// einlesen
// addieren
//

#include <stdio.h>   // printf etc.
#include <stdlib.h> // Makros(EXIT_...), malloc, free
#include <stdbool.h>

enum matop_rescodes {
  MATOP_OK,
  MATOP_ERROR,
};

void free_matrix(double** mat, int rows, int cols){
if(mat == NULL){ return;}
for(int r = 0;r < rows; r++){
if(mat[r] == NULL){break;}
free(mat[r]);
}
// free pointer vector
free(mat);
}


double** malloc_double_matrix(int rows, int cols){
  double** mat = NULL;

  // Allocate array of row vectors
  mat = calloc(rows, sizeof(double*));
  if(mat == NULL){
  printf("unable to allocate memory for matrix\n");
  return NULL;
  }
  // Allocate row vektors
  for(int r = 0; r < rows; r++){
 mat[r] = malloc(cols * sizeof(double));
  if( mat[r] == NULL){
    //cleanup
    free_matrix(mat, rows, cols);
    return NULL;
  }
  }  
  return mat;
}

enum matop_rescodes read_double_matrix_from_file(char *fname, double** mat1, int rows, int cols){
return MATOP_ERROR;
}



void matrix_add(double** mat1, double** mat2, double** mat3, int rows, int cols){
for(int r = 0; r < rows; r++){
  for(int c = 0; c < cols; c++){
  mat3[r][c] = mat1[r][c] + mat2[r][c];
  }

}

}

void matrix_print(double** mat, int rows, int cols){
for(int r = 0; r < rows; r++){
  for(int c = 0; c < cols; c++){
  printf("%20.10lf", mat[r][c]);
  }
  printf("\n");
}
}



int main(void){
  char *fname1 = "mat1.txt";   //Signalisiert, dass fname1 eine Konstante ist
  char *fname2 = "mat2.txt";
 
  int rows = 3;
  int cols = 4;

  double** mat1 = NULL;
  double** mat2 = NULL;
  double** mat3 = NULL;

  enum matop_rescodes  matop_res;
  matop_res = MATOP_OK;
do{
  // allocate memory for matrix 1
  mat1 = malloc_double_matrix(rows, cols);   // mat1 = Pointer auf APA-Struktur
  if(mat1 == NULL){
    printf("unable to allocate memory for the first matrix\n");
   matop_res = MATOP_ERROR;
    break;
  }

  // read double values from file into APA structure pointed to by mat1
  matop_res = read_double_matrix_from_file(fname1, mat1, rows, cols);
  if(matop_res != MATOP_OK){
    printf("unable to read from file of  first matrix%s\n", fname1);
    break;
  };
  // allocate memory for matrix 2
  mat2 = malloc_double_matrix(rows, cols);   // mat1 = Pointer auf APA-Struktur
  if(mat2 == NULL){
    printf("unable to allocate memory for the second  matrix\n");
matop_res = MATOP_ERROR;
    break;
  }
  // read double values from file into APA structure pointed to by mat1
  matop_res = read_double_matrix_from_file(fname2, mat2, rows, cols);
  if(matop_res != MATOP_OK){
    printf("unable to read from file of  second matrix%s\n", fname2);
matop_res = MATOP_ERROR;

  };

    mat3 = malloc_double_matrix(rows, cols);   // mat1 = Pointer auf APA-Struktur
  if(mat3 == NULL){
    printf("unable to allocate memory for the result  matrix\n");
    matop_res = MATOP_ERROR;
    break;
  }

matrix_add(mat1, mat2, mat3, rows, cols);
printf("\n");
printf("Matrix 1 read from file: %s\n", fname1);
matrix_print(mat1, rows, cols);
printf("\n");
printf("Matrix 1 read from file: %s\n", fname1);
matrix_print(mat2, rows, cols);
printf("\n");
printf("The addition of these matrices yields:\n");
matrix_print(mat3, rows, cols);
printf("\n");


}while(false); //ein Schleifendurchlauf -> Aus Block wird bei Fehler herausgesprungen
//exit(25); // beende im Unterprogramm das ganze Programm
//abort(); // breche ganzes Programm ab    => beides ohne Speicherfreigabe
    //...

    // Cleanup
  printf("Running cleanup Code\n"); 
  free_matrix(mat2, rows, cols);
  free_matrix(mat1, rows, cols);
  free_matrix(mat3, rows, cols);
  return MATOP_ERROR;
}




