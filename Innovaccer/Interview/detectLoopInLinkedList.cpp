#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    Node* next;
};

class LinkedList{
    public:
    Node *head;
    LinkedList(){
        head = NULL;
    }
    void push(int data){
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
    void print(){
        Node *ptr = head;
        cout<<"Printing Linked list\n";
        while(ptr != NULL){
            cout<<ptr->data<<"\t";
            ptr = ptr->next;
        }
        cout<<"\n";
    }
    void createLoop(){
        Node *ptr = head;
        if(ptr == NULL) return;
        while(ptr->next != NULL) ptr = ptr->next;
        ptr->next = head;
    }
};

bool detectLoopUsingHash(LinkedList l){
    map<Node*, bool> dic;
    Node *ptr = l.head;
    while(ptr != NULL){
        if(dic.find(ptr) != dic.end()) return true;
        dic[ptr] = true;
        ptr = ptr->next;
    }
    return false;
}

bool detectLoopFloydCycle(LinkedList l){
    Node *slow, *fast;
    slow = fast = l.head;
    while(slow != NULL && fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}

int main(){
    LinkedList l1;
    l1.push(5);
    l1.push(6);
    l1.push(7);
    l1.print();
    l1.createLoop();
    cout<<"is loop "<<detectLoopUsingHash(l1)<<"\n";
    cout<<"is loop "<<detectLoopFloydCycle(l1)<<"\n";
    return 0;
}