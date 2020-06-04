#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 4 

#include "utilit.h"


void multiply(double** mat1, double** mat2, double ** res, int m,int n,   int p)
 {
     int i, j, k;
 
     for (i = 0; i < m; i++)
     {
         for (j = 0; j < p; j++)
         {
             res[i][j] = 0;  
             for (k = 0; k < n; k++) 
                 res[i][j] += mat1[i][k]*mat2[k][j];
         }
     }
 }
 
void multiplyTransp(double** mat1, double** mat2, double ** res, int m,   int n, int p)
 {
     int i, j, k;
 
     for (i = 0; i < m; i++)
     {
         for (j = 0; j < p; j++)
         {
             res[i][j] = 0;  
             for (k = 0; k < n; k++) 
                 res[i][j] += mat1[i][k]*mat2[j][k];
         }
     }
 }
 
void transpose(double ** mat, int dim){
     double tmp = 0;
     int count = 0;
     for (int i =0; i< dim; i++ ){
         for(int j = i+1; j < dim ; j++){    //swap value after digonal 
             tmp = mat[i][j];
             mat[i][j] = mat[j][i];
             mat[j][i] = tmp;
             count ++;
             //printf("%d, %d\n", i,j);
         }
     }
 }

void free_lst(double ** mat, int m, int n){
     for(int i = 0; i < m;++i){
         free(mat[i]);
     }
     //free(mat);
 }
 
void matprint(double ** mat,int n, int p){
 
     printf("printing mat  !!!!!!!!\n");
 
     for (int i = 0; i< n; i++){
         for (int j= 0; j < p; j++){
             printf("%f, ", mat[i][j]);
         }
         printf("\n");
     }
 
     printf("\n");
 }

