#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/*
void printMatrix(int size1, int size2, vector<vector<int>> matrix){
    for (int i = 0; i < size1; i++) {
        cout << matrix[i] << '\n';
    }
}
*/

int main() {
    fstream file("matrix_input.txt", ios::in);
    char data[100];
    file.read(data, sizeof(data));
    file.close();
    int arraySize = data[0] - '0';
    vector<vector<vector<int>>> dataMatrices;
    int dataIndex = 1;
    bool makingArrays = true;
    while (makingArrays == true) {
        vector<vector<int>> dataMatrix = {
            {0,0,0},
            {0,0,0},
            {0,0,0}
        };
        for (int i = 0; i < arraySize; i++) {
            for (int j = 0; j < arraySize; i++) {
                bool numAdded = false;
                while (numAdded == false) {
                    if (data[dataIndex] != ' ' && data[dataIndex] != '\n') {
                        // if so, checks if subsequent index is also an actual number (to account for 2-digit numbers)
                        if (data[dataIndex+1] != ' ' && data[dataIndex+1] != '\n'){
                            // if so, concatenates current and subsequent indices to a string, then converts that string to an int and adds it to the dataMatrix array
                            string tempStr = to_string(data[dataIndex] - '0') + to_string(data[dataIndex+1] - '0');
                            dataMatrix[i][j] = stoi(tempStr);
                            // increments index within data array by 2 instead of 1, as we already evaluated the subsequent character
                            dataIndex += 2;
                        } else {
                            // if not, just adds the int form of the current index to the dataMatrix array
                            dataMatrix[i][j] = data[dataIndex] - '0';
                            // increments index within data aray
                            dataIndex++;
                        }
                        numAdded = true;
                    } else {
                        // if not, just increments index within data array and does nothing else
                        dataIndex++;
                    }
                }
            }
            dataMatrices.push_back(dataMatrix);
            makingArrays = false;
            int tempIndex = dataIndex;
            while (tempIndex < sizeof(data)) {
                if (data[tempIndex] != ' ' && data[tempIndex] != '\n') {
                    makingArrays = true;
                }
            }
        }
    }
    /*
    // nested for loops to add numbers to 2D dataMatrix array corresponding to length of rows/columns
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            //uses a bool + a while loop to ensure that loop does not move to next index until number has been placed in current one
            bool numAdded = false;
            while (numAdded == false) {
                // checks if current index in data array is actually a number and not a space or a newline
                if (data[charIndex] != ' ' && data[charIndex] != '\n') {
                    // if so, checks if subsequent index is also an actual number (to account for 2-digit numbers)
                    if (data[charIndex+1] != ' ' && data[charIndex+1] != '\n'){
                        // if so, concatenates current and subsequent indices to a string, then converts that string to an int and adds it to the dataMatrix array
                        string tempStr = to_string(data[charIndex] - '0') + to_string(data[charIndex+1] - '0');
                        dataMatrix[i][j] = stoi(tempStr);
                        // increments index within data array by 2 instead of 1, as we already evaluated the subsequent character
                        charIndex += 2;
                    } else {
                        // if not, just adds the int form of the current index to the dataMatrix array
                        dataMatrix[i][j] = data[charIndex] - '0';
                        // increments index within data aray
                        charIndex++;
                    }
                    numAdded = true;
                } else {
                    // if not, just increments index within data array and does nothing else
                    charIndex++;
                }
            }
        }
    }
    */
    // nested for loops to print the dataMatrix
    //printMatrix(6,3,dataMatrix);
    for (int i = 0; i < sizeof(dataMatrices); i++) {
        for (int j = 0; j < sizeof(dataMatrices[i]); j++) {
            for (int k = 0; k < sizeof(dataMatrices[i][j]); k++) {
                for (int l = 0; l < sizeof(dataMatrices[i][j][k]); l++) {
                    cout << l;
                }
                cout << '\n';
            }
        }
    }
    return 0;
}