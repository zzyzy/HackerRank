/*
 * HackerRank CTCI Challenges
 * Stacks: Balanced Brackets
 * https://www.hackerrank.com/challenges/ctci-balanced-brackets
 *
 * Written by Zhen Zhi Lee in C++11
 * Last modified 27/01/2017
 */

#include <iostream>
#include <stack>

using namespace std;

bool isBalanced(string expression) {
    stack<char> checker;

    for (auto c : expression) {
        if (c == '{' || c == '(' || c == '[') {
            checker.push(c);
            continue;
        }

        if (checker.empty()) return false;

        auto bracket = checker.top();

        if (bracket == '{' && c == '}' ||
            bracket == '(' && c == ')' ||
            bracket == '[' && c == ']') {
            checker.pop();
        } else {
            return false;
        }
    }

    return checker.empty();
}

int main() {
    int numberOfExpressions;

    cin >> numberOfExpressions;

    for (auto i = 0; i < numberOfExpressions; ++i) {
        string expression;
        cin >> expression;
        cout << (isBalanced(expression) ? "YES" : "NO") << endl;
    }

    return 0;
}