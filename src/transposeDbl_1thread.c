#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 4 
#include "utilit.h"
  
// This function multiplies mat1[][] and mat2[][], 
// and stores the result in res[][]




  
int main(int argc, char * argv[]) {
    // 4096 25 s
    
    int sqDim = 3;
    int m,n,p;
    int max = 10;

    if ((argc > 1) && (argv[1] != NULL)){
        sqDim = atoi(argv[1]);
    }
    m = sqDim;
    n = sqDim;
    p = sqDim;

    srand(2);   //seed to 2
    
    double ** mat1 = (double **)  malloc(sizeof(double *) * m);
    for (int i =0; i < m; i++){
        mat1[i] = (double *) malloc(sizeof( double )*n);
    }

    double ** mat2 = (double **)  malloc(sizeof(double *) * n);
    for (int i =0; i < n; i++){
        mat2[i] =  (double *) malloc(sizeof( double )*p);
    }

    for (int i = 0; i< m; i++){
        for (int j= 0; j < n; j++){
            mat1[i][j] = ((double) rand()/(double)(RAND_MAX) ) * max;
        }
    }
    for (int i = 0; i< n; i++){
        for (int j= 0; j < p; j++){
            mat2[i][j] = ((double) rand()/(double)(RAND_MAX) ) * max;
        }
    }
    
    printf("printing mat 1 !!!!!!!!\n");
    
    for (int i = 0; i< m; i++){
        for (int j= 0; j < n; j++){
            printf("%f, ", mat1[i][j]);
        }
        printf("\n");
    }
    
    printf("printing mat 2 !!!!!!!!\n");
    
    for (int i = 0; i< m; i++){
        for (int j= 0; j < n; j++){
            printf("%f, ", mat2[i][j]);
        }
        printf("\n");
    }


//    double  mat1[4][4] = { {1, 1, 1, 1}, 
//                            {2, 2.5, 2, 2}, 
//                            {3, 3, 3, 3}, 
//                            {4, 4, 4, 4}}; 
//  
//    double  mat2[4][4] = { {1, 1, 1, 1}, 
//                            {2, 2.5, 2, 2}, 
//                            {3, 3, 3, 3}, 
//                            {4, 4, 4, 4}}; 


    //double res[m][p]; // To store result 
    
    double ** res = (double **)  malloc(sizeof(double *) * m);
    for (int i =0; i < m; i++){
        res[i] = (double *) malloc(sizeof( double )*p);
    }
    int i, j;
    clock_t start, end;
    double time_used;
    

    
    /*multiply(mat1, mat2, res, m,n, p); 
    printf( "\nPrinting RES \n" );
    matprint(res, sqDim, sqDim);
    */
    

    //printf("\n\nMAT 1 !!!!!!!!!!!\n");
    //matprint(mat1, sqDim, sqDim);
    //printf("\n\nTaking transpose !!!!!!!!!!!!!!!!!\n");
    //matprint(mat2, sqDim, sqDim);
    
    start = clock();            //Time begin
    transpose(mat2,sqDim );
    //res[0][0] = 0.0;

    //printf("Printing after doing transpose\n");
    //matprint(mat2, sqDim, sqDim);
    
    multiplyTransp(mat1, mat2, res, m,n, p); 
    printf("PRINTING ANSWER after transpose !!!!!!!");
    end = clock();                  //Time END
    matprint(res, sqDim, sqDim);
 


/*    printf("\nResult matrix is \n"); 
    for (i = 0; i < m; i++) { 
        for (j = 0; j < p; j++) 
           printf("%f ", res[i][j]); 
        printf("\n"); 
    } 
*/
    
    printf("Time taken = %lf",((double) end -start) / CLOCKS_PER_SEC );
    //free(mat1[0]);

    free_lst(mat1, m,n);
    free_lst(mat2,n,p);
    free(mat1);
    free(mat2);
    return 0; 
} 
