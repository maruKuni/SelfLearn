#ifndef MYTHREAD_H
#define MYTHREAD_H
#include "matrix_lib.h"
#include <pthread.h>

/** スレッドに渡す計算用データ */
typedef struct order_operate{
    Matrix *left;// 計算用行列，左側
    Matrix *right;// 計算用行列，右側
    int row;//計算する成分の行
    int column;//計算する成分の列
}order_operate;
/** 計算結果を直接格納する */
typedef struct order_with_result{
    Matrix *left;
    Matrix *right;
    Matrix *result;
    int row;
    int column;
}order_with_result;
/** スレッドが返す結果データ */
typedef struct result_prodct{
    int row;
    int column;
    double value;
}result_prodct;
/** スレッドIDのスタック．スレッドを作成するたびにスタックに積んで，合流地点で順次呼び出してpthread_join */
typedef struct thread_stack{
    pthread_t tid;
    struct thread_stack *prev;
}thread_stack;
/** 結果データを初期化 */
void initResult(result_prodct *, order_operate * );
/** スタックの先頭*/
thread_stack *HEAD_T_STACK ;
/** スレッドスタックをpush */
void push_thread(pthread_t);
/** スレッドスタックをpop */
pthread_t pop_thread();
/** スレッドに渡す関数 */
void calcProdMatrix(order_operate *);
/** 計算結果を直接渡すバージョン*/
void calcProdDirect(order_with_result *);
/** スレッドが返した構造体を親スレッドが計算結果用の行列に適用する */
void applyResult(result_prodct *, Matrix *);
#endif