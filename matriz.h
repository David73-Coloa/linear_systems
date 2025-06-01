struct matriz {
    int m;
    int n;
    float **v;
};
typedef struct matriz Matriz ;

Matriz *initializeMatriz(int m, int n);
void insertMatriz(Matriz *mat, int m, int n, float value);
void printMatriz(Matriz* mat);
int getLine(Matriz *mat);
int getColumn(Matriz *mat);

void multiplyLine(Matriz *mat, int i, float k);
void multiplyColumn(Matriz *mat, int j, float k);
void sumLines(Matriz *mat, int i, int j);
//void subtractLines(Matriz *mat, int i, int j);
void combinateLines(Matriz *mat, int i, int j,float q); 
