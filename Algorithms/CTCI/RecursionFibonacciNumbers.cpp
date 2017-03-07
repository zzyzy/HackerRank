/*
 * HackerRank CTCI Challenges
 * Recursion: Fibonacci Numbers
 * https://www.hackerrank.com/challenges/ctci-fibonacci-numbers
 *
 * Written by Zhen Zhi Lee in C++11
 * Last modified 07/03/2017
 */

#include <iostream>

int fibonacci(int n) {
    if (n <= 0) return 0;
    else if (n == 1) return 1;
    else return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    std::cin >> n;
    std::cout << fibonacci(n) << std::endl;
    return 0;
}
