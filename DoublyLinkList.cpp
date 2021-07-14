//doubly link list
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* pre;
};

class List{
public: 
    Node* Head;
    List(){
        Head = NULL;
    }

    Node* getNewNode(int element){
        Node* newNode = new Node();
        newNode->data=element;
        newNode->next=NULL;
        newNode->pre=NULL;
        return newNode;
    }

    int Size(){
        int listSize=0;
        Node* temp = Head;
        while(temp!=NULL){
            listSize++;
            temp = temp->next;
        }
        return listSize;
    }

    void insertAtBegin(int element){
        Node* newNode = getNewNode(element);
        if(Head==NULL) {Head = newNode; return;}
        newNode->next = Head;
        Head->pre = newNode;
        Head = newNode;
    }

    void insertAtEnd(int element){
        Node* newNode = getNewNode(element);
        Node* temp = Head;
        if(Head == NULL){
            Head = newNode;
            return;
        }
        while(temp->next=NULL){
            temp = temp->next;
        }
        newNode->pre = temp;
        temp->next = newNode;
    }

    void insertAt(int index, int element){
        if(index==1) {insertAtBegin(element); return;}

        Node* newNode = getNewNode(element);
        Node* temp = Head;

        while(temp->next != NULL){
            temp = temp->next;
        }
        newNode->pre = temp;
        temp->next = newNode;
    }

    void deleteAtEnd(){
        if(Head == NULL){
            cout<<"Your list is already EMPTY!\n";
            return;
        }
        Node* temp = Head;
        while( temp->next !=NULL) temp = temp->next;

        if(temp->pre == NULL){
            delete temp;
            Head = NULL;
            return;
        }

        temp->pre->next = NULL;
        delete temp;
    }

    void deleteAtBegin(){
        if(Head == NULL){
            cout<<"Your list is already EMPTY!\n";
            return;
        }

        Node* temp = Head;
        if(temp->next == NULL){
            delete temp;
            Head = NULL;
            return;
        }
        Head = temp->next;
        Head->pre = NULL;
        delete temp;
    }

    void deleteAt(int position){
        if(Head == NULL){
            cout<<"Your list is already EMPTY!\n";
            return;
        }
        if(position == 1) deleteAtBegin();
        else if(position == Size()) deleteAtEnd();
        else{
            Node* temp = Head;
            for(int i=1; i<position-1; i++){
                temp = temp->next;
            }
            Node* temp2 = temp->next;
            Node* temp3 = temp2->next;

            temp->next = temp3;
            temp3->pre = temp;
            delete temp2;
        }
    }

    void print(){
        Node* temp=Head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }
};

int main(){
    List l;
    l.insertAtBegin(3);
    l.insertAtEnd(5);
    l.insertAtEnd(6);
    l.insertAtEnd(7);
    //l.deleteAtEnd();
    l.print();
    cout<<l.Size()<<endl;
}