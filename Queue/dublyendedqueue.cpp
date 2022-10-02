#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

class Node{
	public:
		Node* prev;
		int data;
		Node* next;
		
	Node()
	{
		prev = NULL;
		data = 0;
		next = NULL;
	}
	//parameter constructor
	Node(int data){
		this->prev = NULL;
		this->data = data;
		this->next = NULL;	
	}
};

class LinkedList{
	Node *head;
	public:
		//Default constructor
		LinkedList(){
			head = NULL;
		}
		
		// Push Data from Back side of Deq
		void pushBackDeq( int data)
		{
			Node *newnode = new Node(data);
			if(head==NULL)
			{
				head = newnode;
				head->next = head;
				head->prev = head;
			}
			else{
				newnode->prev=head->prev;
				newnode->next=head;
				head->prev->next = newnode;
				head->prev = newnode;
			}
		}
		
		// Push Data from front side of Deq
		void pushFrontDeq(int data)
		{
			pushBackDeq(data);
			head = head->prev;
		}
		
		int popBackDeq(){
			int data;
			if(head->prev==head)
			{
				data = head->data;
				free(head);
				head=NULL;
			}
			else{
				Node* newtail = head->prev->prev;
				data = head->prev->data;
				newtail->next = head;
				free(head->prev);
				head->prev = newtail;
			}
			return data;
		}
		int popFrontDeq()
		{
			head = head->next;
			int data =popBackDeq();
			return data;
		}
		
		void display(){
			Node *temp = head;
			if(temp==NULL)
			{
				cout<<"Empty Queue";
				return;
			}
			
			if(temp->next == head)
			{
				cout<<temp->data<<" ";
				return;
			}
			
			while(temp->next!=head)
			{
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<temp->data<<" ";
		}
};



int main()
{
	LinkedList list;
	list.pushBackDeq(9);
	list.pushBackDeq(8);
	list.pushFrontDeq(10);
	list.pushBackDeq(7);
	list.display();
	cout<<"\nPOPED from Back:"<<list.popBackDeq()<<"\n";
	list.pushBackDeq(5);
	cout<<"\nPOPED from front:"<<list.popFrontDeq()<<"\n";
	list.display();
	return 0;
}
