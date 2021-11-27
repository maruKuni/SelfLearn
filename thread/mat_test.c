#include "matrix_lib.h"
int main(){
    Matrix *tmp = initMatrix(3,3);
    randomMatrix(tmp);
    printMatrix(tmp);
    removeMatrix(tmp);
    return 0;
}