#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class List{
public:
    Node* Head;
    List(){
        Head = NULL;
    }

    //Used to create node in other function
    Node* getNewnode(int element){
        Node* newNode = new Node();
        newNode->data=element;
        newNode->next=NULL;
        return newNode;
    }

    void insertAtBegin(int element){
        Node* newNode = getNewnode(element);
        newNode->next = Head;
        Head = newNode;
    }
    void insertAtEnd(int element){
        Node* newNode = getNewnode(element);
        Node* temp = Head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void insert(int index, int element){
        if(index == 1) {
            insertAtBegin(element);
            return;
        }

        Node* newNode = getNewnode(element);
        Node* temp = Head;

        for(int i=1; i<index-1; i++){
            temp = temp->next;
        }
        Node* temp2 = temp->next;//Save another nodes data for newNode's next pointer
        temp->next = newNode;//Use pointer to point new node
        newNode->next = temp2;//Connect new pointer of newNode to next Node
    }
    void print(){
        Node* temp = Head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

int main(){
    List l;
    l.insertAtBegin(3);
    l.insertAtBegin(2);
    l.insertAtBegin(1);
    l.insertAtEnd(4);
    l.insertAtEnd(5);
    l.insertAtEnd(6);
    l.insertAtEnd(7);
    l.print();
    // l.eraseData(5);
    // l.eraseData(1);
    // l.eraseData(7);
}
