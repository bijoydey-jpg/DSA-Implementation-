#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};
Node *top = nullptr;
void push(int item){
    Node *New = new Node{item, nullptr};
    New->next = top;
    top = New;
}
void pop(){
    if(top == nullptr){
        cout << "Underflow\n";
        return;
    }
    Node *temp = top;
    top = top->next;
    delete temp;
}

void show(){
    Node *ptr = top;
    if(ptr == nullptr){
        cout << "Empty List\n";
        return;
    }
    while(ptr != nullptr){
        cout << ptr->data;
        if(ptr->next != nullptr)
            cout << "->";
        ptr = ptr->next;
    }
    cout << endl;
}

main()
{
    pop();
    push(5);
    show();
    pop();
    show();
    push(6);
    show();
    push(7);
    show();
    push(8);
    show();
    pop();
    show();
    pop();
    show();
    pop();
    show();
    pop();
    show();
}
