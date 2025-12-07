#include<iostream>
using namespace std;

int size = 0 ;
 int MAX = 4 ;


struct Node{
    int info;
    Node *next;
};

Node *front = nullptr;
Node *rare = nullptr;

void enque(int d){

    if(size == MAX) {
        cout << "FULL" << endl;
        return;
    }

    Node  *newnode = new Node{d,NULL};

    if(front == NULL){

        front = rare = newnode ;
    }
    else {

        rare -> next = newnode;
        rare = newnode;
    }

    size++;

}

void deque(){

    if(front == NULL){

        cout << "EMPTY" << endl;
    }
    
    Node *temp = front ;
    front = front -> next ;

    if(front == NULL){
        rare = NULL;
    }
    delete temp;
    size--;


    
}
void show(){
    Node *ptr = front;
    if(ptr == nullptr){
        cout << "Empty List\n";
        return;
    }
    while(ptr != nullptr){
        cout << ptr->info;
        if(ptr->next != nullptr)
            cout << "->";
        ptr = ptr->next;
    }
    cout << endl;
}
main()
{
    enque(5);
    show();
    enque(5);
    enque(5);
    enque(5);
    enque(5);
    show();
    deque();
    show();

}
