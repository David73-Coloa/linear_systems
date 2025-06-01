#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"



Matriz *initializeMatriz(int m, int n) {
     //printf("BLABLA");
    Matriz* mat = malloc(sizeof(Matriz));
    mat->m = m;
    mat->n = n;
    mat->v  = malloc(sizeof(float*) *m);
    for (int i=0;i<m;i++) {
        mat->v[i] = malloc(n*sizeof(float));
    }

    return mat;
}

void insertMatriz(Matriz *mat, int m, int n, float value) {
    mat->v[m][n] = value;
}
void printMatriz(Matriz* mat) {
    for (int i=0;i<mat->m;i++) {
            printf("|");
        for (int j=0;j<mat->n;j++) {
            printf(" %f ", mat->v[i][j]);
            //printf("Elemento da linha %d coluna:%d:%f\n",i,j, mat->v[i][j]);
        }
     printf("|");
        printf("\n");
    }
}
void multiplyLine(Matriz *mat, int i, float k) {
  for (int j=0;j<getColumn(mat);j++) {
    mat->v[i][j] = k *  mat->v[i][j];
  }
}
void multiplyColumn(Matriz *mat, int j, float k) {
  for (int i=0;i<getLine(mat);i++) {
    mat->v[i][j] = k *  mat->v[i][j];
  }
}

void combinateLines(Matriz *mat, int i, int j,float q) {
  printf("\n=====  SOMANDO A LINHA %i A LINHA %d * %f  =====\n", i, j, q);
  for (int k=0;k<getColumn(mat);k++) {
    mat->v[i][k] = mat->v[i][k] + q * mat->v[j][k];
  }
}


int getLine(Matriz *mat) {
    return mat->m;
}

int getColumn(Matriz *mat) {
    return mat->n;
}



