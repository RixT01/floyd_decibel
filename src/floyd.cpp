#include "floyd.hpp"

using namespace std;
    double** createMatrix(unsigned int n) {
        double** array2D = 0;
        array2D = new double*[n];

        for (int h = 0; h < n; h++) {
            array2D[h] = new double[n];

            for (int w = 0; w < n; w++) {

                if (w == h){
                    array2D[h][w] = 0;
                }
                else{
                    array2D[h][w] = numeric_limits<double>::infinity();
                }
                
            }
        }

        return array2D;
    }

    void printMatrix(double** myMatrix, unsigned int size){
        for (int h = 0; h < size; h++) {
            for (int w = 0; w < size; w++) {
                printf("%f,", myMatrix[h][w]);
            }
            printf("\n");
        }
    }

    void floyd_algorithm(double** matrix, unsigned int limit){
        for (unsigned int k = 0; k < limit; k++){
            for (unsigned int i = 0; i < limit; i++){
                for (unsigned int j = 0; j <= i; j++){
                    double highest = max(matrix[i][k], matrix[k][j]);
                    if (isinf(highest)){
                        continue;
                    }
                    else{
                        if (matrix[i][j] > highest){
                            matrix[i][j] = highest;
                            matrix[j][i] = highest;
                        }
                    }
                    
                }
            }
        }
        //printMatrix(matrix, limit);  
    }
