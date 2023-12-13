#include <iostream>
#include <vector>

// Function to perform matrix multiplication
std::vector<std::vector<int>> matrixMultiply(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int rowsB = B.size();
    int colsB = B[0].size();

    // Check if matrix multiplication is possible
    if (colsA != rowsB) {
        std::cerr << "Error: Matrix multiplication not possible. Columns of A must be equal to rows of B." << std::endl;
        return {};
    }

    // Initialize the result matrix with zeros
    std::vector<std::vector<int>> result(rowsA, std::vector<int>(colsB, 0));

    // Perform matrix multiplication
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

// Function to display a matrix
void displayMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    // Example matrices
    std::vector<std::vector<int>> matrixA = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<int>> matrixB = {{7, 8}, {9, 10}, {11, 12}};

    // Perform matrix multiplication
    std::vector<std::vector<int>> result = matrixMultiply(matrixA, matrixB);

    // Display the original matrices and the result
    std::cout << "Matrix A:" << std::endl;
    displayMatrix(matrixA);

    std::cout << "\nMatrix B:" << std::endl;
    displayMatrix(matrixB);

    std::cout << "\nResultant Matrix:" << std::endl;
    displayMatrix(result);

    return 0;
}
