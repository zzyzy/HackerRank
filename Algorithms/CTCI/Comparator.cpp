/*
 * HackerRank CTCI Challenges
 * Sorting: Comparator
 * https://www.hackerrank.com/challenges/ctci-comparator-sorting
 *
 * Written by Zhen Zhi Lee in C++11
 * Last modified 14/02/2017
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <functional>

using namespace std;

struct Player {
    string name;
    int score;

    bool operator<(const Player &player) {
        if (this->score == player.score) {
            return this->name > player.name;
        }
        return this->score < player.score;
    }

    bool operator>(const Player &player) {
        if (this->score == player.score) {
            return this->name < player.name;
        }
        return this->score > player.score;
    }
};

// Hoare partition scheme
size_t partition(vector<Player> &arr, size_t lo, size_t hi, function<bool(Player, Player)> comp) {
    random_device rd;
    mt19937 gen(rd());
    // something wrong with closed interval in mingw64, hi must be hi - 1
    uniform_int_distribution<size_t> dist(lo, hi - 1);

    auto pivotIndex = dist(gen);
    auto pivot = arr[pivotIndex];
    auto i = lo - 1;
    auto j = hi + 1;

    while (true) {
        do { ++i; } while (comp(arr[i], pivot));
        do { --j; } while (comp(pivot, arr[j]));
        if (i >= j) return j;
        swap(arr[i], arr[j]);
    }
}

void quickSort(vector<Player> &arr, size_t lo, size_t hi, function<bool(Player, Player)> comp) {
    if (lo < hi) {
        auto p = partition(arr, lo, hi, comp);
        quickSort(arr, lo, p, comp);
        quickSort(arr, p + 1, hi, comp);
    }
}

void quickSort(vector<Player> &arr, function<bool(Player, Player)> comp) {
    quickSort(arr, 0, arr.size() - 1, comp);
}

int main() {
    size_t n;

    ifstream infile;
    infile.open("Comparator.txt");
    if (!infile.is_open()) cerr << "Input file not found" << endl;
    istream &input = infile.is_open() ? infile : cin;

    input >> n;

    vector<Player> players(n);

    for (auto i = 0; i < n; ++i) {
        Player player;
        input >> player.name >> player.score;
        players[i] = player;
    }

    if (infile.is_open()) infile.close();

//    for (auto player : players) {
//        cout << player.name << " " << player.score << endl;
//    }

    quickSort(players, [](Player a, Player b) { return a > b; });

//    cout << "After sort: " << endl;
    for (auto player : players) {
        cout << player.name << " " << player.score << endl;
    }

    return 0;
}