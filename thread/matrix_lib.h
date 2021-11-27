#ifndef _MATRIX_LIB_H
#define _MATRIX_LIB_H
#include <pthread.h>

/** 行列*/
typedef struct Matrix{
    double *entry;
    int row;
    int column;
}Matrix;
/** 指定したサイズの行列を返す. 0で初期化 */
Matrix *initMatrix(int , int );
/** 行列を削除(free)するだけ */
void removeMatrix(Matrix *);
/** 渡された行列にランダムな値をセット */
void randomMatrix(Matrix *);
/** 行列表示用．これいる？ */
void printMatrix(Matrix *);
/** 行列のi-j成分の値を取得 */
double getEntry(Matrix *, int, int);
/** 行列のi-j成分に値を設定 */
void setEntry(Matrix *, int , int , double );
#endif