//doubly link list
#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* prev;
	Node* next;
};
class List{
public:
	Node* Head;
	List(){Head=NULL;}

	Node* GetNewNode(int element){
	   Node* NewNode = new Node();

	   NewNode->data = element;
	   NewNode->next = NULL;
	   NewNode->prev = NULL;
	   return NewNode;
        }

	void insertAtBegin(int element){
		Node* newNode = GetNewNode(element);

		if(Head == NULL){
			Head = newNode;
			return;
		}
		newNode->next = Head;
		Head->prev = newNode;
		Head = newNode;
	}
	void insertAtEnd(int element){
		Node* newNode = GetNewNode(element);
		Node* temp = Head;
		
		if(Head == NULL){
			Head = newNode;
			return;
		}
		while(temp->next != NULL) temp=temp->next;
		temp->next = newNode;
		newNode->prev = temp;
	}

	void insertAt(int position, int element){
		Node* newNode = GetNewNode(element);
		Node* temp = Head;

		if(position == 1){
			newNode->next = Head;
			Head->prev = newNode;
			Head = newNode;
			return;
		}
		for(int i=1; i<position-1; i++) temp = temp->next;
		newNode->prev = temp; 
		newNode->next = temp->next;
		temp->next = newNode;
	}
	void popAtBegin(){
		Node* temp = Head;

		if(Head == NULL){
			cout<<"Your list is EMPTY!\n";
			return;
		}
		temp->next->prev = NULL;
		Head = temp->next;
		delete temp;
	}
	void popAtEnd(){
		Node* temp = Head;
		
		if(Head == NULL){
			cout<<"Your List is EMPTY!\n";
			return;
		}
		while(temp->next != NULL) temp = temp->next;
		temp->prev->next = NULL; //Making 2nd last nodes' next NULL
		delete temp;
	}

	void popAt(int position){
		Node* temp = Head;
		if(position == 1){
			Head = temp->next;
			Head->prev = NULL;
			delete temp;
			return;
		}
		for(int i=1; i<position-1; i++){
			temp = temp->next;
		}
		Node* temp2 = temp->next;
		temp->next = temp2->next;
		temp2->next->prev = temp;
		delete temp2;
	}
	void print(){
		Node* temp = Head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<"\n";
	}
	void Reverse(){
		Node* temp = Head;
		if(Head == NULL){
			cout<<"The List is EMPTY!\n";
			return;
		}
		while(temp->next != NULL) temp = temp->next;
		while(temp != NULL){
			cout<<temp->data<<" ";
			temp = temp->prev;
		}
		cout<<"\n";
	}
};

int main()
{
	List l;
	l.insertAtEnd(40);
	l.insertAtEnd(50);
	l.insertAtEnd(60);
	l.insertAtBegin(30);
	l.insertAtBegin(20);
	l.print();
	l.insertAt(3, 10);
	cout<<"After adding in 3nd position: ";
	l.print();

	l.popAtBegin();
	l.popAtEnd();
	l.popAt(3);
	cout<<"After deleting node: ";
	l.print();

	cout<<"After reversing: ";
	l.Reverse();
}
