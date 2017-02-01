/*
 * HackerRank CTCI Challenges
 * Trees: Is This a Binary Search Tree?
 * https://www.hackerrank.com/challenges/ctci-is-binary-search-tree
 *
 * Written by Zhen Zhi Lee in C++11
 * Last modified 01/02/2017
 *
 * Notes to self:
 * - C++ static variables initializes once and only once
 */

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
};

bool checkBSTHelper(Node *root, Node *&prev) {
    if (root) {
        if (!checkBSTHelper(root->left, prev))
            return false;

        if (prev && root->data <= prev->data)
            return false;

        prev = root;

        return checkBSTHelper(root->right, prev);
    }

    return true;
}

bool checkBST(Node *root) {
    Node *prev = nullptr;
    return checkBSTHelper(root, prev);
}

Node *newNode(int value) {
    Node *node = new Node();
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node *arrayToBST(int arr[], int start, int end) {
    if (start > end)
        return nullptr;

    int mid = (start + end) / 2;
    Node *node = new Node();

    node->data = arr[mid];
    node->left = arrayToBST(arr, start, mid - 1);
    node->right = arrayToBST(arr, mid + 1, end);

    return node;
}

void inOrderTraverse(Node *root) {
    if (root) {
        inOrderTraverse(root->left);
        cout << root->data << " ";
        inOrderTraverse(root->right);
    }
}

int main() {
    const int SIZE = 15;
    int data[SIZE] = {1, 2, 3, 4, 5, 6, 7, 11, 9, 10, 8, 12, 13, 14, 15};
    Node *root = arrayToBST(data, 0, SIZE - 1);

    inOrderTraverse(root);
    cout << endl;

    cout << (checkBST(root) ? "Yes" : "No") << endl;

    return 0;
}