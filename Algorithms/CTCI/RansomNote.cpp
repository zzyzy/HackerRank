/*
 * HackerRank CTCI Challenges
 * Hash Tables: Ransom Note
 * https://www.hackerrank.com/challenges/ctci-ransom-note
 *
 * Written by Zhen Zhi Lee in C++11
 * Last modified 26/01/2017
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool ransomNote(unordered_map<string, int> &magazine, const vector<string> &note) {
    for (auto word : note) {
        if (magazine.find(word) != magazine.end()) {
            if (magazine[word] >= 1) {
                --magazine[word];
                if (magazine[word] == 0) {
                    magazine.erase(word);
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    int magazineWords, noteWords;

    cin >> magazineWords >> noteWords;

    unordered_map<string, int> magazine;
    for (auto i = 0; i < magazineWords; ++i) {
        string temp;
        cin >> temp;
        if (magazine.find(temp) != magazine.end()) {
            ++magazine[temp];
        } else {
            magazine.insert({temp, 1});
        }
    }

    vector<string> note(noteWords);
    for (auto i = 0; i < noteWords; ++i) {
        cin >> note[i];
    }

    cout << (ransomNote(magazine, note) ? "Yes" : "No") << endl;

    return 0;
}