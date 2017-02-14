/*
 * HackerRank CTCI Challenges
 * Strings: Making Anagrams
 * https://www.hackerrank.com/challenges/ctci-making-anagrams
 *
 * Written by Zhen Zhi Lee in C++11
 * Last modified 26/01/2017
 */

#include <iostream>

using namespace std;

// Compare a with b
// Remove any character not found in a from b
// Return sum of length of a and b
int numberNeeded(string a, string b) {
    for (auto it = a.begin(); it != a.end();) {
        if (b.find_first_of(*it) != string::npos) {
            b.erase(b.find_first_of(*it), 1);
            it = a.erase(it);
        } else {
            ++it;
        }
    }

    return a.length() + b.length();
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << numberNeeded(a, b);
    return 0;
}
