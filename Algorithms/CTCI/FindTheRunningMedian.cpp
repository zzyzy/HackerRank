/*
 * HackerRank CTCI Challenges
 * Heaps: Find the Running Median
 * https://www.hackerrank.com/challenges/ctci-find-the-running-median
 *
 * Written by Zhen Zhi Lee in C++11
 * Last modified 02/02/2017
 *
 * References:
 * 1. http://www.geeksforgeeks.org/median-of-stream-of-integers-running-integers/
 */

#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

vector<float> getRunningMedian(vector<int> arr) {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    float m = 0.0f;
    vector<float> medians;

    for (auto num : arr) {
        if (left.size() > right.size()) {
            if (num < m) {
                right.push(left.top());
                left.pop();

                left.push(num);
            } else {
                right.push(num);
            }

            m = (left.top() + right.top()) / 2.0f;
        } else if (left.size() == right.size()) {
            if (num < m) {
                left.push(num);
                m = left.top();
            } else {
                right.push(num);
                m = right.top();
            }
        } else if (left.size() < right.size()) {
            if (num < m) {
                left.push(num);
            } else {
                left.push(right.top());
                right.pop();

                right.push(num);
            }

            m = (left.top() + right.top()) / 2.0f;
        }

        medians.push_back(m);
    }

    return medians;
}

int main() {
    size_t n;
    cin >> n;

    vector<int> arr(n);

    for (auto i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    auto medians = getRunningMedian(arr);

    cout << fixed << setprecision(1);

    for (auto m : medians) {
        cout << m << endl;
    }

    return 0;
}