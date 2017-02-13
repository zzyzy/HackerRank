/*
 * HackerRank CTCI Challenges
 * Sorting: Bubble Sort
 * https://www.hackerrank.com/challenges/ctci-bubble-sort
 *
 * Written by Zhen Zhi Lee in C++11
 * Last modified 14/02/2017
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int bubbleSort(vector<int> &arr) {
    int totalNumberOfSwaps = 0;

    for (auto i = 0; i < arr.size(); ++i) {
        int numberOfSwaps = 0;

        for (auto j = 0; j < arr.size() - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                ++numberOfSwaps;
            }
        }

        if (numberOfSwaps == 0) {
            break;
        } else {
            totalNumberOfSwaps += numberOfSwaps;
        }
    }

    return totalNumberOfSwaps;
}

int main() {
    int n;

    cin >> n;

    vector<int> arr(n);

    for (auto i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Array is sorted in " << bubbleSort(arr) << " swaps." << endl;
    cout << "First Element: " << arr[0] << endl;
    cout << "Last Element: " << arr[arr.size() - 1] << endl;

    return 0;
}