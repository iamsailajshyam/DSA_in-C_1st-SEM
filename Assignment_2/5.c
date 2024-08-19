#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Function to print a matrix
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a matrix is symmetric
bool isSymmetric(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int size;

    // Read the size of the matrix
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &size);

    // Ensure the matrix is square
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid matrix size.\n");
        return 1;
    }

    // Read the matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print the matrix
    printf("Matrix:\n");
    printMatrix(matrix, size, size);

    // Check if the matrix is symmetric
    if (isSymmetric(matrix, size)) {
        printf("The matrix is symmetric.\n");
    } else {
        printf("The matrix is not symmetric.\n");
    }

    return 0;
}
