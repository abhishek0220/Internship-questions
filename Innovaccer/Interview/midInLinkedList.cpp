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
};

int midInLinkedList(LinkedList l){
    Node *slow, *fast;
    slow = fast = l.head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main(){
    LinkedList l1;
    l1.push(5);
    l1.push(6);
    l1.push(7);
    l1.push(8);
    l1.push(9);
    l1.push(10);
    l1.push(11);
    l1.print();
    cout<<"mid of linked list is "<<midInLinkedList(l1)<<"\n";
    return 0;
}