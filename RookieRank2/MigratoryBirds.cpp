/*
 * HackerRank Rookie Rank 2
 * Migratory Birds
 * https://www.hackerrank.com/contests/rookierank-2/challenges/migratory-birds
 *
 * Written by Zhen Zhi Lee in C++11
 * Last modified 11/02/2017
 */

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;

    cin >> n;

    unordered_map<int, int> counts;

    for (auto i = 0; i < n; ++i) {
        int id;
        cin >> id;
        ++counts[id];
    }

    int maxId = 0;

    for (auto &e : counts) {
        if (e.second > counts[maxId]) {
            maxId = e.first;
        }
    }

    cout << maxId << endl;

    return 0;
}
