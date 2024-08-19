//Write a C program to read a 2D array (with most of the elements as 0s) and then represent the same array as Sparse Metrics. 
#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Structure to represent a non-zero element in a sparse matrix
typedef struct {
    int row;
    int col;
    int value;
} SparseElement;

int main() {
    int rows, cols;
    int matrix[MAX_ROWS][MAX_COLS];
    SparseElement sparseMatrix[MAX_ROWS * MAX_COLS];
    int count = 0;

    // Read matrix dimensions
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Read the matrix elements
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Convert to sparse matrix representation
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix[count].row = i;
                sparseMatrix[count].col = j;
                sparseMatrix[count].value = matrix[i][j];
                count++;
            }
        }
    }

    // Print the sparse matrix representation
    printf("Sparse matrix representation (row, column, value):\n");
    for (int i = 0; i < count; i++) {
        printf("%d %d %d\n", sparseMatrix[i].row, sparseMatrix[i].col, sparseMatrix[i].value);
    }

    return 0;
}
