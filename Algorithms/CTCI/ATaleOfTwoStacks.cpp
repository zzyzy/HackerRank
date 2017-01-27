/*
 * HackerRank CTCI Challenges
 * Queues: A Tale of Two Stacks
 * https://www.hackerrank.com/challenges/ctci-queue-using-two-stacks
 *
 * Written by Zhen Zhi Lee in C++11
 * Last modified 27/01/2017
 */

#include <iostream>
#include <stack>

using namespace std;

class Queue {
public:
    void push(int value) {
        backStack.push(value);
    }

    void pop() {
        rearrangeStacks();
        frontStack.pop();
    }

    int front() {
        rearrangeStacks();
        return frontStack.top();
    }

private:
    // Queue allows insertion at the back
    // and deletion at the front where as
    // Stack only allows insertion and deletion
    // at the top (or back)
    //
    //              frontStack||backStack
    //                ________ ________
    // front (queue) |_|_|_|_||_|_|_|_| back (queue)
    //          top (stack)         top (stack)
    //
    // Any insertion will be handled by the backStack
    // Any deletion (or peek/access) will be handled by the frontStack
    // However, before any deletion (or peek/access), we must
    // first rearrange both stacks
    stack<int> frontStack, backStack;

    // Only rearrange the stacks when the frontStack is empty
    // Basically it pops the backStack and inserts the popped value
    // to the frontStack until the backStack is empty
    void rearrangeStacks() {
        if (!frontStack.empty()) return;
        while (!backStack.empty()) {
            auto value = backStack.top();
            frontStack.push(value);
            backStack.pop();
        }
    }
};

int main() {
    Queue myQueue;
    int numberOfQueries;

    cin >> numberOfQueries;

    for (auto i = 0; i < numberOfQueries; ++i) {
        int type;
        cin >> type;
        switch (type) {
            case 1: {
                int value;
                cin >> value;
                myQueue.push(value);
                break;
            }
            case 2:
                myQueue.pop();
                break;
            case 3:
                cout << myQueue.front() << endl;
                break;
            default:
                break;
        }
    }

    return 0;
}