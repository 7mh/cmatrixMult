#ifndef UTILIT_H
#define UTILIT_H



void multiply(double** mat1, double** mat2, double ** res, int m,int n,int  p);

void multiplyTransp(double** mat1, double** mat2, double ** res, int m,   int n, int p);

void transpose(double ** mat, int dim);
void free_lst(double ** mat, int m, int n);

void matprint(double ** mat,int n, int p);


#endif
