#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"


void debug3(Matriz *m1) {
 insertMatriz(m1, 0, 0, 1);   // x
    insertMatriz(m1, 0, 1, 1);   // y
    insertMatriz(m1, 0, 2, 1);   // z
    insertMatriz(m1, 0, 3, 6);   // resultado

    // Inserindo linha 1: 2x + y - z = 1
    insertMatriz(m1, 1, 0, 2);
    insertMatriz(m1, 1, 1, 1);
    insertMatriz(m1, 1, 2, -1);
    insertMatriz(m1, 1, 3, 1);

    // Inserindo linha 2: x + 2y + z = 8
    insertMatriz(m1, 2, 0, 1);
    insertMatriz(m1, 2, 1, 2);
    insertMatriz(m1, 2, 2, 1);
    insertMatriz(m1, 2, 3, 8);
}
void debug4(Matriz *m) {
  insertMatriz(m, 0, 0, 1.0f);
    insertMatriz(m, 0, 1, 1.0f);
    insertMatriz(m, 0, 2, 1.0f);
    insertMatriz(m, 0, 3, 1.0f);
    insertMatriz(m, 0, 4, 5.0f);

    // Eq 2: x - y + z - w = 1
    insertMatriz(m, 1, 0, 1.0f);
    insertMatriz(m, 1, 1, -1.0f);
    insertMatriz(m, 1, 2, 1.0f);
    insertMatriz(m, 1, 3, -1.0f);
    insertMatriz(m, 1, 4, 1.0f);

    // Eq 3: 2x + y - z + w = 2
    insertMatriz(m, 2, 0, 2.0f);
    insertMatriz(m, 2, 1, 1.0f);
    insertMatriz(m, 2, 2, -1.0f);
    insertMatriz(m, 2, 3, 1.0f);
    insertMatriz(m, 2, 4, 2.0f);

    // Eq 4: -x + 2y + 3z - w = 6
    insertMatriz(m, 3, 0, -1.0f);
    insertMatriz(m, 3, 1, 2.0f);
    insertMatriz(m, 3, 2, 3.0f);
    insertMatriz(m, 3, 3, -1.0f);
    insertMatriz(m, 3, 4, 6.0f);
}
/*
void debug2(Matriz *m) {
insertMatriz(m, 0, 0, 2.0f);   // coef x
    insertMatriz(m, 0, 1, 3.0f);   // coef y
    insertMatriz(m, 0, 2, 12.0f);  // resultado

    // Equação 2: x - y = 1
    insertMatriz(m, 1, 0, 1.0f);
    insertMatriz(m, 1, 1, -1.0f);
    insertMatriz(m, 1, 2, 1.0f);
}
void reduceMatriz3(Matriz *m1) {
  int m = 3; 
  combinateLines(m1, m-1, 0, -1 * ( (m1->v[m-1][0])/(m1->v[0][0])  )  );
  printMatriz(m1);
combinateLines(m1, m-2, 0, -1 * ( m1->v[m-2][0]/m1->v[0][0] )   );
   printMatriz(m1);
combinateLines(m1, m-1, 1, -1 * ( m1->v[m-1][1]/m1->v[1][1]  )   );
 printMatriz(m1);

 // reduceMatriz(m1, m-1);
}
*/
void putZeros(Matriz *m1, int matriz_size) {
  int line = getLine(m1); // caso 4x4: comeca no 0, vai ate o 3, caso 3x3: comeca no 1 e vai ate o 3, caso 2x2: comeca no 2 e vai ate o 3
  int column = getColumn(m1);
  //printf("\nLINE MARRIZ:%d\n", matriz_size);
  for (int i=line-matriz_size+1;i<line;i++) {
    //if (i==line-matriz_size) continue;
    float k = m1->v[i][line-matriz_size]/m1->v[line-matriz_size][line-matriz_size]; 
    //}
    
    //printf("");
    for (int j=line-matriz_size;j<column;j++) {
        m1->v[i][j] = m1->v[i][j] - k * m1->v[line-matriz_size][j];
   
    }

  }
  //printMatriz(m1);


  
}
void reduceMatriz(Matriz *m1, int matriz_size) {
  //int until = m-1; 
  if (matriz_size > 1) {
    //printf("REALSIZE:%d\n",matriz_size);
    putZeros(m1, matriz_size);
    //printMatriz(m1); 
    //printf("\n");

    matriz_size=matriz_size-1;
    reduceMatriz(m1, matriz_size);

  //printf("\n");
  }
  // colocar 0 em todos os primeiros elementos das linhas
  // aplicar novamente a funcao, mas pra n-1, usando a condicao de parada m >=1
  // caso 3x3: compararLInhas(0,1) e depois comparar(0,2). Depois aplicar pra 2x2, onde compara(0,1)
}
typedef struct {
  float value; 
  char letter;
} Incognite;

void solveMatriz(Matriz *m1) {
   int line = getLine(m1); // 4 
  int column = getColumn(m1); // 5
  Incognite variables[line];
  for (int i=0;i<line;i++) {
    variables[i].letter = (char)(97+i);
    variables[i].value = 1.0;
  }

  for (int i=line-1;i>=0;i--) {
 
    for (int j=0;j<column;j++) { 
      if (j != column-1) printf("%.0f%c + ", m1->v[i][j], variables[j].letter);
    }
    printf("  =  %f", m1->v[i][column-1]);
    printf("\n");

 
    float sum=0;
    char letter = variables[i].letter;
    float equal = m1->v[i][column-1];
    float coeficient = m1->v[i][i];

    for (int j=0;j<column;j++) {
      if (i==j || j == column-1) {
         continue;
      }
      //printf("  %f [%d,%d]", m1->v[i][j], i,j);
      sum = sum+(m1->v[i][j])*(variables[j].value); 
    }
    variables[i].value = (equal-sum)/coeficient;
    //printf("  SUM = %f e equal-sum:%f => %c = %f\n\n", sum, equal-sum,variables[i].letter,variables[i].value);
  }
  
  for (int i=0;i<line;i++) {
    printf("%c = %f\n", variables[i].letter, variables[i].value);    
    //variables[i].letter = (char)(97+i);
    //variables[i].value = 1.0;
  }



}

int main() { 
  //char letters[] = {'a', 'b','c','d','e','f'};
    int m = 4;
    Matriz *m1 = initializeMatriz(m,m+1);
    //debug3(m1); 
    debug4(m1);
    printMatriz(m1); 
    reduceMatriz(m1, getLine(m1));
    printf("\n");
    printMatriz(m1);
    printf("\n");
    solveMatriz(m1);
    return 0;
}

