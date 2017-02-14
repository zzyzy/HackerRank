/*
 * HackerRank Rookie Rank 2
 * Minimum Absolute Difference in an Array
 * https://www.hackerrank.com/contests/rookierank-2/challenges/minimum-absolute-difference-in-an-array
 *
 * Written by Zhen Zhi Lee in C++11
 * Last modified 11/02/2017
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    size_t n;

    cin >> n;

    vector<int> a(n);

    // Sort the list O(n log n)
    // Then get the minimum adjacent (a[i + 1] - a[i]) difference O(n)
    // Time complexity O(n log n + n)
    for (auto i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int minDiff = INT_MAX;

    for (auto i = 0; i < n - 1; ++i) {
        if (a[i + 1] - a[i] < minDiff) {
            minDiff = a[i + 1] - a[i];
        }
    }

    cout << minDiff << endl;

    return 0;
}
