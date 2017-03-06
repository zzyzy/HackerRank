/*
 * HackerRank CTCI Challenges
 * Binary Search: Ice Cream Parlor
 * https://www.hackerrank.com/challenges/ctci-ice-cream-parlor
 *
 * Written by Zhen Zhi Lee in C++11
 * Last modified 06/03/2017
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

struct IceCream {
    IceCream() = default;

    IceCream(int index, int cost) : index(index), cost(cost) {
    }

    bool operator<(const IceCream &b) {
        return cost < b.cost;
    }

    int index;
    int cost;
};

int binarySearch(std::vector<IceCream> arr, int lo, int hi, int target) {
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2; // (hi - lo) to prevent overflow
        // http://www.geeksforgeeks.org/problem-binary-search-implementations/

        if (arr[mid].cost < target) {
            lo = mid + 1; // ignore left half
        } else if (arr[mid].cost == target) {
            return arr[mid].index; // found target
        } else {
            hi = mid - 1; // ignore right half
        }
    }

    return -1;
}

int main() {
    std::ifstream infile;
    infile.open("IceCreamParlor.txt");
    if (!infile.is_open()) std::cerr << "Input file not found" << std::endl;
    std::istream &input = infile.is_open() ? infile : std::cin;

    int t{}; // number of trips

    input >> t;

    for (auto i = 0; i < t; ++i) {
        int m{}; // pooled money
        int n{}; // number of flavors

        input >> m;
        input >> n;

        std::vector<IceCream> c; // cost per flavor
        c.reserve(static_cast<size_t>(n));

        for (auto j = 0; j < n; ++j) {
            IceCream iceCream;

            input >> iceCream.cost;
            iceCream.index = j + 1;

            c.push_back(iceCream);
        }

        std::sort(c.begin(), c.end());

        int targetCost{}, a{}, b{};

        for (auto j = 0; j < n; ++j) {
            a = c[j].index;
            targetCost = m - c[j].cost;

            // avoid negative
            if (targetCost >= 0) {
                b = binarySearch(c, j + 1, static_cast<int>(c.size()) - 1, targetCost);

                if (b != -1) {
                    std::cout << std::min(a, b) << " " << std::max(a, b) << std::endl;
                    break;
                }
            }
        }
    }

    return 0;
}