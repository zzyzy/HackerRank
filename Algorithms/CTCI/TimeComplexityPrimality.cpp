/*
 * HackerRank CTCI Challenges
 * Time Complexity: Primality
 * https://www.hackerrank.com/challenges/ctci-big-o
 *
 * Written by Zhen Zhi Lee in C++11
 * Last modified 07/03/2017
 */

#include <iostream>

// https://en.wikipedia.org/wiki/Primality_test
bool isPrime(int n) {
    if (n <= 1) return false; // 1 is not a prime number
    else if (n <= 3) return true; // 2 is the only even number that is a prime number
    else if (n % 2 == 0 || n % 3 == 0) return false;

    // don't have to test divisors greater than sqroot of n
    for (auto i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

int main() {
    int p;

    std::cin >> p;

    for (auto i = 0; i < p; ++i) {
        int n;
        std::cin >> n;

        std::cout << (isPrime(n) ? "Prime" : "Not prime") << std::endl;
    }

    return 0;
}