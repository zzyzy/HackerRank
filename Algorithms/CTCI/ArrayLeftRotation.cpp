#include <iostream>
#include <vector>

using namespace std;

// To handle negative number using remainder operator
// Ref: http://stackoverflow.com/questions/12276675/modulus-with-negative-numbers-in-c
// Use: (a % b + b) % b
vector<int> arrayLeftRotation(const vector<int> &inputArray, int arraySize, int numberOfRotations) {
    vector<int> outputArray(arraySize);

    for (auto i = 0; i < arraySize; ++i) {
        auto rotatedIndex = (i + numberOfRotations) % arraySize;
        outputArray[i] = inputArray[rotatedIndex];
    }

    return outputArray;
}

int main() {
    int arraySize, numberOfRotations;

    cin >> arraySize >> numberOfRotations;

    vector<int> inputArray(arraySize);
    for (auto i = 0; i < arraySize; ++i) {
        cin >> inputArray[i];
    }

    vector<int> outputArray = arrayLeftRotation(inputArray, arraySize, numberOfRotations);
    for (auto i = 0; i < arraySize; i++) {
        cout << outputArray[i] << " ";
    }

    cout << endl;

    return 0;
}