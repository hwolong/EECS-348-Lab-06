#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

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


vector<vector<vector<int>>> makeArray(int arraySize, vector<int> data) {
    vector<vector<vector<int>>> matrixList;
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
            vector<int> matrixLine;
            for (int k = 0; k < arraySize; k++) {
                matrixLine.push_back(data[dataIndex]);
                dataIndex++;
            }
            dataMatrix.push_back(matrixLine);
        }
        matrixList.push_back(dataMatrix);
    }
    return matrixList;
}

int main() {
    string fileName = "matrix_input.txt";
    vector<int> data = matrixIO(fileName);
    data.erase(data.begin());
    int arraySize = data[0];
    data.erase(data.begin());
    for (int i = 0; i < 98; i++) {
        cout << data[i] << " ";
    }
    cout << "\n";
    vector<vector<vector<int>>> matrixList = makeArray(arraySize, data);
    for (int i = 0; i < sizeof(matrixList); i++) {
        for (int j = 0; j < sizeof(matrixList[i]); j++) {
            for (int k = 0; k < sizeof(matrixList[i][j]); k++) {
                cout << k << " ";
            }
            cout << "\n";
        }
    }
}