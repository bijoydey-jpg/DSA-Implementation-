#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *frontPtr = nullptr;
Node *rearPtr = nullptr;

int sizeCount = 0;
const int MAX = 10;

// Insert element at rear of queue
void enqueue(int item) {
    if (sizeCount == MAX) {
        cout << "Overflow (Queue is full)\n";
        return;
    }

    Node *New = new Node{item, nullptr};

    if (frontPtr == nullptr) {
        // First element
        frontPtr = rearPtr = New;
    } else {
        rearPtr->next = New;
        rearPtr = New;
    }

    sizeCount++;
}

// Remove element from front of queue
void dequeue() {
    if (frontPtr == nullptr) {
        cout << "Underflow (Queue is empty)\n";
        return;
    }

    Node *temp = frontPtr;
    frontPtr = frontPtr->next;

    // If queue becomes empty
    if (frontPtr == nullptr)
        rearPtr = nullptr;

    delete temp;
    sizeCount--;
}

// Display queue
void show() {
    if (frontPtr == nullptr) {
        cout << "Queue is empty\n";
        return;
    }

    Node *ptr = frontPtr;
    cout << "Queue: ";

    while (ptr != nullptr) {
        cout << ptr->data;
        if (ptr->next != nullptr)
            cout << " -> ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {
    dequeue();
    enqueue(5);
    show();
    dequeue();
    show();
    enqueue(6);
    show();
    enqueue(7);
    show();
    enqueue(8);
    show();
    dequeue();
    show();
    dequeue();
    show();
    dequeue();
    show();
    dequeue();
    show();

    return 0;
}
