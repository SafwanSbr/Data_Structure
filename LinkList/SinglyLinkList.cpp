#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

class List{
public:
    Node* Head;
    List(){ Head = NULL; }

    Node* GetNewnode(int element){
        Node* newNode = new Node();
        newNode->data=element;
        newNode->next=NULL;
        return newNode;
    }

    void insertAtBegin(int element){
        Node* newNode = GetNewnode(element);
        newNode->next = Head;
        Head = newNode;
    }
    void insertAtEnd(int element){
        Node* newNode = GetNewnode(element);
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
        Node* newNode = GetNewnode(element);
        Node* temp = Head;

        for(int i=1; i<index-1; i++){
            temp = temp->next;
        }
        Node* temp2 = temp->next;//Save another nodes data for newNode's next pointer
        temp->next = newNode;//Use pointer to point new node
        newNode->next = temp2;//Connect new pointer of newNode to next Node
    }
    void popAt(int n){
        if(Head == NULL){
            cout<<"Your list is EMPTY!\n";
            return;
        }

        Node* temp = Head;
        if(n==1){
            Head = temp->next;
            delete temp;
            return;
        }/* i */
        for(int i=1; i<n-1; i++) { 
            temp = temp->next;
        }
        Node* temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
        return;
    }
    void popAtBegin(){
        Node* temp = Head;
        if(Head == NULL){
            cout<<"Your List is EMPTY!\n";
            return;
        }
        if(Head->next == NULL){
            delete temp;
            Head = NULL;
            return;
        }
        Head = temp->next;
        delete temp;

    }
    void popAtEnd(){
        Node* temp = Head;
        if(Head == NULL){
            cout<<"Your List is EMPTY!\n";
            return;
        }
        if(temp->next == NULL){
            delete temp;
            Head = NULL;
            return;
        }
        while(temp->next->next != NULL) temp=temp->next;
        temp->next = NULL;
        delete temp->next;
    }

    void print(){//Traverse
        Node* temp = Head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    void Search(int element){
        Node* temp = Head;
        while(temp != NULL){
            if(temp->data == element){
                cout<<"\nFound\n";
                return;
            }
        }
        cout<<"\nNot Found!\n";
    }
};

int main(){
    List l;
    l.insertAtBegin(10);
    l.insertAtBegin(85);
    l.insertAtBegin(25);
    l.insertAtBegin(45);
    l.insertAtBegin(15);

    l.print();cout<<"\n";
    
    l.popAtBegin();
    l.print();cout<<"\n";
    
    l.popAtEnd();
    l.print();cout<<"\n";

    l.popAt(3);
    l.print();cout<<"\n";

    //l.popAt(3);
    //l.print();
}
