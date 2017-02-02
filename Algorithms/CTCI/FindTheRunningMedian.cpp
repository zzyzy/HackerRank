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

using namespace std;

int main() {
    int n;
    cin >> n;

    float median = 0.0f;
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    for (auto i = 0; i < n; ++i) {
        int num;
        cin >> num;

        if (left.size() > right.size()) {
            if (num < median) {
                right.push(left.top());
                left.pop();

                left.push(num);
            } else {
                right.push(num);
            }

            median = (left.top() + right.top()) / 2.0f;
        } else if (left.size() == right.size()) {
            if (num < median) {
                left.push(num);
                median = left.top();
            } else {
                right.push(num);
                median = right.top();
            }
        } else if (left.size() < right.size()) {
            if (num < median) {
                left.push(num);
            } else {
                left.push(right.top());
                right.pop();

                right.push(num);
            }

            median = (left.top() + right.top()) / 2.0f;
        }

        cout << median << endl;
    }

    return 0;
}