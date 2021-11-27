CC := clang
CFLAGS := -Wall -Wextra 
LDLIBS := -lpthread
mat_test: Matrix.o mat_test.o
T_Matrix:Matrix.o Matrix_thread.o T_Matrix.o
simpleMatrix:Matrix.o simpleMatrix.o
T_Matrix_proved:Matrix.o Matrix_thread.o T_Matrix_proved.o
Matrix.o Matrix_thread.o  mat_test.o : matrix_lib.h

clean:
	rm *.o