#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    double X[3][4];
    double Y[12];
    int i, j, ct = 0;

    
    srand(time(NULL));

    
    printf("2-dimensional array X is:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            X[i][j] = (double)rand() / RAND_MAX * 100.0; 
            printf("%.2f\t", X[i][j]);
            Y[ct++] = X[i][j]; 
        }
        printf("\n");
    }

    
    printf("\n1-dimensional array Y row-wise is:\n");
    for (i = 0; i < 12; i++) {
        printf("%.2f ", Y[i]);
    }
    printf("\n");

    return 0;
}
