#include <iostream>

int** input(int row, int col) {
    int** matrix = new int*[row];
    std::cout << "Fill matrix: " << "\n";
    for (int i = 0; i < row; i++) {
        matrix[i] = new int[col];
        for (int j = 0; j < col; j++) {
            std::cin >> matrix[i][j];
        }
    }
    return matrix;
}

void output(int** matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void change(int** matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 1; j < col; j+=2) {
            int temp = matrix[i][j - 1];
            matrix[i][j - 1] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }
}

int main() {
    int row, col;
    std::cout << "Input matrix row length:";
    std::cin >> row;
    std::cout << "Input matrix col length:";
    std::cin >> col;
    int** matrix = input(row, col);
    change(matrix, row, col);
    std::cout << "----------------\n";
    output(matrix, row, col);
}
