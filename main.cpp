#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<vector<vector<int>>> dataMatrices;

vector<int> matrixIO(string fileName) {
    vector<int> data = {0};
    fstream fileStream;
    fileStream.open(fileName);
    int num;
    for (int i = 0; i < 100; i++) {
        fileStream >> num;
        data.push_back(num);
    }
    fileStream.close();
    return data;
}

void makeMatrices(vector<int> data, int arraySize) {
    int matrixCount = 0;
    for (int i = 0; i < sizeof(data); i++) {
        if (data[i] != 10) {
            matrixCount++;
        }
    }
    matrixCount /= 9;
    matrixCount++;
    int dataIndex = 0;
    for (int i = 0; i < matrixCount; i++) {
        vector<vector<int>> dataMatrix;
        for (int j = 0; j < arraySize; j++) {
            vector<int> matrixRow;
            for (int k = 0; k < arraySize; k++) {
                matrixRow.push_back(data[dataIndex]);
                dataIndex++;
            }
            dataMatrix.push_back(matrixRow);
        }
        dataMatrices.push_back(dataMatrix);
    }
}

void printMatrix(vector<vector<int>> matrix, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        for (int j = 0; j < arraySize; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

vector<vector<int>> addMatrices(int arraySize) {
    vector<vector<int>> newMatrix;
    for (int i = 0; i < arraySize; i++) {
        vector<int> newMatrixRow;
        for (int j = 0; j < arraySize; j++) {
            int newMatrixInt = dataMatrices[0][i][j] + dataMatrices[1][i][j];
            newMatrixRow.push_back(newMatrixInt);
        }
        newMatrix.push_back(newMatrixRow);
    }
    return newMatrix;
}

vector<vector<int>> multiplyMatrices(int arraySize) {
    vector<vector<int>> newMatrix;
    for (int i = 0; i < arraySize; i++) {
        vector<int> newMatrixRow;
        for (int j = 0; j < arraySize; j++) {
            int newMatrixInt = 0;
            for (int l = 0; l < arraySize; l++) {
                newMatrixInt += (dataMatrices[0][i][l] * dataMatrices[1][l][j]);
            }
            newMatrixRow.push_back(newMatrixInt);
        }
        newMatrix.push_back(newMatrixRow);
    }
    return newMatrix;
}

vector<vector<int>> subtractMatrices(vector<vector<int>> matrix1, vector<vector<int>> matrix2, int arraySize) {
    vector<vector<int>> newMatrix;
    for (int i = 0; i < arraySize; i++) {
        vector<int> newMatrixRow;
        for (int j = 0; j < arraySize; j++) {
            int newMatrixInt = matrix1[i][j] - matrix2[i][j];
            newMatrixRow.push_back(newMatrixInt);
        }
        newMatrix.push_back(newMatrixRow);
    }
    return newMatrix;
}

vector<vector<int>> updateMatrix(vector<vector<int>> matrix, int row, int col, int newVal) {
    matrix[row][col] = newVal;
    return matrix;
}

int matrixMax(vector<vector<int>> matrix, int arraySize) {
    int max = 0;
    for (int i = 0; i < arraySize; i++) {
        for (int j = 0; j < arraySize; j++) {
            if (max < matrix[i][j]) {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

vector<vector<int>> transposeMatrix(vector<vector<int>> matrix, int arraySize) {
    vector<vector<int>> newMatrix;
    for (int i = 0; i < arraySize; i++) {
        vector<int> newMatrixRow;
        for (int j = 0; j < arraySize; j++) {
            int newMatrixInt = matrix[j][i];
            newMatrixRow.push_back(newMatrixInt);
        }
        newMatrix.push_back(newMatrixRow);
    }
    return newMatrix;
}

int main() {
    cout << "1. Read values from a file into a matrix:\n\n";
    string fileName = "matrix_input.txt";
    vector<int> data = matrixIO(fileName);
    data.erase(data.begin());
    int arraySize = data[0];
    data.erase(data.begin());
    makeMatrices(data, arraySize);
    cout << "2. Print a matrix:\n";
    for (int i = 0; i < 2; i++) {
        cout << "Matrix " << i+1 << ":\n";
        printMatrix(dataMatrices[i], arraySize);
        cout << "\n";
    }
    cout << "3. Add two matrices and place the result into a third matrix; print the result:\n";
    printMatrix(addMatrices(arraySize), arraySize);
    cout << "4. Multiply two matrices and place the result into a third matrix; print the result:\n";
    printMatrix(multiplyMatrices(arraySize), arraySize);
    cout << "5. Subtract the second matrix from the first matrix and place the result in a third matrix; print the result:\n";
    printMatrix(subtractMatrices(dataMatrices[0], dataMatrices[1], arraySize), arraySize);
    cout << "6. Update an element of the first matrix; print the result:\n";
    cout << "Chosen update: (0,0) in first matrix updated to 100:\n";
    dataMatrices[0] = updateMatrix(dataMatrices[0], 0, 0, 100);
    printMatrix(dataMatrices[0], arraySize);
    dataMatrices[0] = updateMatrix(dataMatrices[0], 0, 0, 1);
    cout << "7. Get the max value of the first matrix:\n";
    cout << matrixMax(dataMatrices[0], arraySize) << "\n\n";
    cout << "8. Transpose the first matrix; print the result.\n";
    printMatrix(transposeMatrix(dataMatrices[0], arraySize), arraySize);
    return 0;
}
