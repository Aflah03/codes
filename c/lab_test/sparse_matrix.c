#include<stdio.h>

typedef struct{
    int row,col;
    int value;
}entry;

int convert_to_tuple(int A[][3],int r1,int c1,entry matrix1[]){
    int ind1=1;
    matrix1[0].row = r1;
    matrix1[0].col = c1;
    matrix1[0].value =0;
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            if(A[i][j]!=0){
                    matrix1[ind1].row = i; 
                    matrix1[ind1].col = j;
                    matrix1[ind1].value = A[i][j];
                    matrix1[0].value++;
                    ind1++;
            }
            
        }
    }
    return ind1;
    printf("The value of ind1 is : %d",ind1);


}
// void sum_matrix(entry matrix1[],int indx1,entry matrix2[],int indx2){
//     int num1=1;int num2=1;
//     while(num1 < indx1 && num2<indx2){
//         if((matrix1[num1].row == matrix1[num1].row ) && (matrix1[num1].col) == matrix2[num2].col){
            
//         }
//     }
// }
int main(){
    int r1,c1,r2,c2;
    printf("Enter r and c of array 1: ");
    scanf("%d %d",&r1,&c1);
    int A[][3] = {{0,0,3},
                  {4,0,0},
                  {0,5,6}
                  };
    printf("Enter r and c of array 1: ");
    scanf("%d %d",&r2,&c2);   
    int B[][3] = {{0,9,1},
                  {0,0,0},
                  {7,0,2}};
    
    
    entry matrix1[20]; 
    entry matrix2[20]; 
    
    printf("matrix2[0].value is %d\n",matrix2[0].value);
    int ind1 = convert_to_tuple(A,r1,c1,matrix1);
    int ind2 = convert_to_tuple(B,r2,c2,matrix2);

    // //sort matrix1 in column order in the tuple form
    //  for(int i=1;i<ind1;i++){
    //     for(int j=1;j<ind1-1-i;j++){
    //         if(matrix1[j].col > matrix1[j+1].col){
    //             entry temp = matrix1[j+1];
    //             matrix1[j+1] =matrix1[j];
    //             matrix1[j]=temp;
    //         }
    //     }
    // }
    printf("the value of index 1 is : %d\n",ind1);
    printf("MATRIX 1:\n");
    for(int i=0;i<ind1;i++){
        printf("(%d, %d, %d)\n",matrix1[i].row,matrix1[i].col,matrix1[i].value);
        
    }
    printf("the value of indx2 is : %d\n",ind2);
    printf("MATRIX 2:\n");
    for(int j=0;j<ind2;j++){
        printf("(%d, %d, %d)\n",matrix2[j].row,matrix2[j].col,matrix2[j].value);
        
    }

}


/* CHATGPT CODE



Your code is a good start for working with sparse matrices in tuple form. You have implemented a function to convert a 2D matrix to a sparse matrix representation and have setup for displaying these matrices. However, there are a few improvements and corrections needed to complete the functionality, especially for adding two sparse matrices.

Corrections and Improvements
Matrix Size: Make sure the matrix sizes and their dimensions are correctly input and processed. You need to ensure the input matrix dimensions are correctly handled.

Conversion Function: Your convert_to_tuple function is almost correct but needs a fix for ind1 initialization and the printf statement should be placed after the return statement.

Matrix Addition Function: Implement the sum_matrix function to handle the addition of two sparse matrices.

Fix Matrix Input: Adjust the input matrices A and B so they match the dimensions provided by the user, or dynamically allocate matrices based on input sizes.

Here’s the updated and corrected code:

c
Copy code
#include <stdio.h>

typedef struct {
    int row, col;
    int value;
} entry;

// Function to convert a dense matrix to a sparse matrix in tuple form
int convert_to_tuple(int A[][3], int r1, int c1, entry matrix1[]) {
    int ind1 = 1; // Start from index 1 since index 0 will hold dimensions
    matrix1[0].row = r1;
    matrix1[0].col = c1;
    matrix1[0].value = 0; // Count of non-zero elements

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            if (A[i][j] != 0) {
                matrix1[ind1].row = i;
                matrix1[ind1].col = j;
                matrix1[ind1].value = A[i][j];
                matrix1[0].value++;
                ind1++;
            }
        }
    }
    return ind1;
}

// Function to add two sparse matrices
void sum_matrix(entry matrix1[], int ind1, entry matrix2[], int ind2, entry result[], int* result_size) {
    int i = 1, j = 1, k = 1;
    int rows1 = matrix1[0].row;
    int cols1 = matrix1[0].col;
    int rows2 = matrix2[0].row;
    int cols2 = matrix2[0].col;

    if (rows1 != rows2 || cols1 != cols2) {
        printf("Matrix dimensions do not match for addition.\n");
        *result_size = 0;
        return;
    }

    // Adding matrices
    while (i < ind1 && j < ind2) {
        if (matrix1[i].row == matrix2[j].row && matrix1[i].col == matrix2[j].col) {
            int sum = matrix1[i].value + matrix2[j].value;
            if (sum != 0) {
                result[k].row = matrix1[i].row;
                result[k].col = matrix1[i].col;
                result[k].value = sum;
                k++;
            }
            i++
            j++;;
            j++;
        } else if (matrix1[i].row < matrix2[j].row || 
                   (matrix1[i].row == matrix2[j].row && matrix1[i].col < matrix2[j].col)) {
            result[k++] = matrix1[i++];
        } else {
            result[k++] = matrix2[j++];
        }
    }

    // Copy remaining elements
    while (i < ind1) {
        result[k++] = matrix1[i++];
    }
    while (j < ind2) {
        result[k++] = matrix2[j++];
    }

    *result_size = k;
}

// Function to print a sparse matrix
void print_sparse_matrix(entry matrix[], int size) {
    for (int i = 0; i < size; i++) {
        printf("(%d, %d, %d)\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
}

int main() {
    int r1, c1, r2, c2;
    
    printf("Enter number of rows and columns for matrix 1: ");
    scanf("%d %d", &r1, &c1);
    int A[r1][c1];
    printf("Enter elements for matrix 1:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter number of rows and columns for matrix 2: ");
    scanf("%d %d", &r2, &c2);
    int B[r2][c2];
    printf("Enter elements for matrix 2:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    
    entry matrix1[100]; // Adjust size if needed
    entry matrix2[100]; // Adjust size if needed
    entry result[200];  // Adjust size if needed

    int ind1 = convert_to_tuple(A, r1, c1, matrix1);
    int ind2 = convert_to_tuple(B, r2, c2, matrix2);

    int result_size;
    sum_matrix(matrix1, ind1, matrix2, ind2, result, &result_size);

    printf("Sparse Matrix 1:\n");
    print_sparse_matrix(matrix1, ind1);

    printf("Sparse Matrix 2:\n");
    print_sparse_matrix(matrix2, ind2);

    printf("Sum of Matrices:\n");
    print_sparse_matrix(result, result_size);

    return 0;
}
Key Points:
Dynamic Matrix Size: The example uses fixed-size arrays for simplicity. Adjust array sizes or use dynamic memory allocation for real-world scenarios with larger matrices.
Matrix Input: Now the matrices are input by the user, making the program more flexible.
Matrix Addition: The sum_matrix function merges and sums the matrices, handling different positions correctly.
Error Handling: The code checks if the dimensions match before performing the addition.
This should provide a complete example of handling sparse matrix operations in C, including conversion, addition, and display.