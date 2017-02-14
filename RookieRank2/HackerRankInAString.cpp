/*
 * HackerRank Rookie Rank 2
 * HackerRank in a String!
 * https://www.hackerrank.com/contests/rookierank-2/challenges/hackerrank-in-a-string
 *
 * Written by Zhen Zhi Lee in C++11
 * Last modified 12/02/2017
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int q;

    cin >> q;

    for (auto i = 0; i < q; i++) {
        string s;
        cin >> s;

        string pattern = "hackerrank";
        vector<size_t> positions(pattern.length());
        size_t currentPos = 0; // Start index to search from

        // First get the positions of all the characters in the string
        for (auto j = 0; j < pattern.length(); ++j) {
            positions[j] = s.find_first_of(pattern[j], currentPos);
            currentPos = positions[j] + 1 == s.length() ? s.length() - 1 : positions[j] + 1;
        }

        bool cond = true;

        for (auto j = 1; j < pattern.length(); ++j) {
            if (positions[j - 1] == string::npos ||
                positions[j] == string::npos ||
                positions[j - 1] > positions[j]) {
                cond = false;
                break;
            }
        }

        cout << (cond ? "YES" : "NO") << endl;
    }

    return 0;
}
