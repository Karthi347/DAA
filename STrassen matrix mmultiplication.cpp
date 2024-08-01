#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void printMatrix(int **matrix, int size);
void allocateMatrix(int ***matrix, int size);
void freeMatrix(int **matrix, int size);
void addMatrix(int **A, int **B, int **Result, int size);
void subtractMatrix(int **A, int **B, int **Result, int size);
void combineMatrix(int **C, int **C11, int **C12, int **C21, int **C22, int size);
void divideMatrix(int **M, int ***M11, int ***M12, int ***M21, int ***M22, int size);
void strassenMultiply(int **A, int **B, int **C, int size);

int main() {
    int size = 4; // Example size, should be power of 2 for Strassen's algorithm

    int **A, **B, **C;
    
    // Allocate matrices
    allocateMatrix(&A, size);
    allocateMatrix(&B, size);
    allocateMatrix(&C, size);

    // Initialize matrices with example values
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            A[i][j] = i + j;
            B[i][j] = i - j;
        }
    }

    printf("Matrix A:\n");
    printMatrix(A, size);
    
    printf("Matrix B:\n");
    printMatrix(B, size);
    
    // Perform Strassen's matrix multiplication
    strassenMultiply(A, B, C, size);
    
    printf("Result Matrix C:\n");
    printMatrix(C, size);
    
    // Free allocated memory
    freeMatrix(A, size);
    freeMatrix(B, size);
    freeMatrix(C, size);
    
    return 0;
}

// Function to allocate matrix memory
void allocateMatrix(int ***matrix, int size) {
    *matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        (*matrix)[i] = (int *)malloc(size * sizeof(int));
    }
}

// Function to free matrix memory
void freeMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to print matrix
void printMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add matrices
void addMatrix(int **A, int **B, int **Result, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            Result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract matrices
void subtractMatrix(int **A, int **B, int **Result, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            Result[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to combine submatrices into one matrix
void combineMatrix(int **C, int **C11, int **C12, int **C21, int **C22, int size) {
    int newSize = size / 2;
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

// Function to divide a matrix into 4 submatrices
void divideMatrix(int **M, int ***M11, int ***M12, int ***M21, int ***M22, int size) {
    int newSize = size / 2;
    
    allocateMatrix(M11, newSize);
    allocateMatrix(M12, newSize);
    allocateMatrix(M21, newSize);
    allocateMatrix(M22, newSize);
    
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            (*M11)[i][j] = M[i][j];
            (*M12)[i][j] = M[i][j + newSize];
            (*M21)[i][j] = M[i + newSize][j];
            (*M22)[i][j] = M[i + newSize][j + newSize];
        }
    }
}

// Strassen's matrix multiplication
void strassenMultiply(int **A, int **B, int **C, int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = size / 2;
    int **A11, **A12, **A21, **A22;
    int **B11, **B12, **B21, **B22;
    int **M1, **M2, **M3, **M4, **M5, **M6, **M7;
    int **C11, **C12, **C21, **C22;
    int **temp1, **temp2;
    
    divideMatrix(A, &A11, &A12, &A21, &A22, size);
    divideMatrix(B, &B11, &B12, &B21, &B22, size);
    
    allocateMatrix(&M1, newSize);
    allocateMatrix(&M2, newSize);
    allocateMatrix(&M3, newSize);
    allocateMatrix(&M4, newSize);
    allocateMatrix(&M5, newSize);
    allocateMatrix(&M6, newSize);
    allocateMatrix(&M7, newSize);
    
    // Compute M1 to M7
    temp1 = (int **)malloc(newSize * sizeof(int *));
    temp2 = (int **)malloc(newSize * sizeof(int *));
    for (int i = 0; i < newSize; i++) {
        temp1[i] = (int *)malloc(newSize * sizeof(int));
        temp2[i] = (int *)malloc(newSize * sizeof(int));
    }

    addMatrix(A11, A22, temp1, newSize);
    addMatrix(B11, B22, temp2, newSize);
    strassenMultiply(temp1, temp2, M1, newSize);
    
    addMatrix(A21, A22, temp1, newSize);
    strassenMultiply(temp1, B11, M2, newSize);
    
    subtractMatrix(B12, B22, temp2, newSize);
    strassenMultiply(A11, temp2, M3, newSize);
    
    subtractMatrix(B21, B11, temp2, newSize);
    strassenMultiply(A22, temp2, M4, newSize);
    
    addMatrix(A11, A12, temp1, newSize);
    strassenMultiply(temp1, B22, M5, newSize);
    
    subtractMatrix(A21, A11, temp1, newSize);
    addMatrix(B11, B12, temp2, newSize);
    strassenMultiply(temp1, temp2, M6, newSize);
    
    subtractMatrix(A12, A22, temp1, newSize);
    addMatrix(B21, B22, temp2, newSize);
    strassenMultiply(temp1, temp2, M7, newSize);
    
    // Compute C11, C12, C21, C22
    allocateMatrix(&C11, newSize);
    allocateMatrix(&C12, newSize);
    allocateMatrix(&C21, newSize);
    allocateMatrix(&C22, newSize);
    
    addMatrix(M1, M4, temp1, newSize);
    subtractMatrix(temp1, M5, temp2, newSize);
    addMatrix(temp2, M7, C11, newSize);
    
    addMatrix(M3, M5, C12, newSize);
    
    addMatrix(M2, M4, C21, newSize);
    
    addMatrix(M1, M3, temp1, newSize);
    subtractMatrix(temp1, M2, temp2, newSize);
    addMatrix(temp2, M6, C22, newSize);
    
    // Combine submatrices into result matrix
    combineMatrix(C, C11, C12, C21, C22, size);
    
    // Free temporary matrices
    for (int i = 0; i < newSize; i++) {
        free(temp1[i]);
        free(temp2[i]);
    }
    free(temp1);
    free(temp2);
    freeMatrix(A11, newSize);
    freeMatrix(A12, newSize);
    freeMatrix(A21, newSize);
    freeMatrix(A22, newSize);
    freeMatrix(B11, newSize);
    freeMatrix(B12, newSize);
    freeMatrix(B21, newSize);
    freeMatrix(B22, newSize);
    freeMatrix(M1, newSize);
    freeMatrix(M2, newSize);
    freeMatrix(M3, newSize);
    freeMatrix(M4, newSize);
    freeMatrix(M5, newSize);
    freeMatrix(M6, newSize);
    freeMatrix(M7, newSize);
    freeMatrix(C11, newSize);
    freeMatrix(C12, newSize);
    freeMatrix(C21, newSize);
    freeMatrix(C22, newSize);
}

