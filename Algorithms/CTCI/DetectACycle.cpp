/*
 * HackerRank CTCI Challenges
 * Linked Lists: Detect a Cycle
 * https://www.hackerrank.com/challenges/ctci-linked-list-cycle
 *
 * Written by Zhen Zhi Lee in C++11
 * Last modified 27/01/2017
 *
 * Better solution:
 * https://en.wikipedia.org/wiki/Cycle_detection#Tortoise_and_hare
 */

#include <iostream>
#include <unordered_set>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

Node *addNode(Node *node, int data) {
    if (!node) {
        node = new Node();
        node->data = data;
        node->next = nullptr;
        return node;
    } else {
        node->next = new Node();
        node->next->data = data;
        node->next->next = nullptr;
        return node->next;
    }
}

void clearList(Node *head) {
    if (!head) return;
    unordered_set<Node *> references;

    Node *current = head;
    Node *next;
    while (current != nullptr) {
        if (references.find(current) != references.end()) {
            break;
        } else {
            references.insert(current);
        }
        next = current->next;
        delete current;
        current = next;
    }
}

// Better solution use tortoise and hare algorithm
// Add visited node to hash table
// If a node is already in the hash table, then there is a cycle
bool hasCycle(Node *head) {
    if (!head) return false;
    unordered_set<Node *> references;

    Node *ptr = head;
    while (ptr != nullptr) {
        if (references.find(ptr) != references.end()) {
            return true;
        } else {
            references.insert(ptr);
        }
        ptr = ptr->next;
    }

    return false;
}

int main() {
    auto head = addNode(nullptr, 1);
    auto node2 = addNode(head, 2);
    auto node3 = addNode(node2, 3);
    node3->next = node2;

    cout << hasCycle(head) << endl;

    clearList(head);

    return 0;
}