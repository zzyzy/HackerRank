#include <iostream>
#include <vector>

using namespace std;

vector<int> arrayRightRotation(const vector<int> &inputArray, int arraySize, int numberOfRotations) {
    vector<int> outputArray(arraySize);

    for (auto i = 0; i < arraySize; ++i) {
        auto rotatedIndex = ((i - numberOfRotations) % arraySize + arraySize) % arraySize;
        outputArray[i] = inputArray[rotatedIndex];
    }

    return outputArray;
}

int main() {
    int arraySize, numberOfRotations, numberOfQueries;

    cin >> arraySize >> numberOfRotations >> numberOfQueries;

    vector<int> inputArray(arraySize);
    for (auto i = 0; i < arraySize; ++i) {
        cin >> inputArray[i];
    }

    vector<int> outputArray = arrayRightRotation(inputArray, arraySize, numberOfRotations);
    for (auto i = 0; i < numberOfQueries; ++i) {
        int m;
        cin >> m;
        cout << outputArray[m] << endl;
    }

    return 0;
}