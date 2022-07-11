#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;

class Node{
    // access identifier
    public:
    int data;
    Node *next;

    // default cunstrutor
    Node()
    {
        data = 0;
        next = NULL;
    }
    // parameterized cunstructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// linked list class 
class LinkedList{
    Node *head;

    public:
        // default constructor
        LinkedList(){
            head = NULL;
        }
        
        // function to insert the node at the end of linked list
        void insertNode(int);

        // function to print the list
        void PrintList();

        // function to delete the node
        void deletelist(int);
};

// function to insert the node 
void LinkedList::insertNode(int data)
{
    //create a node 
    Node *newnode = new Node(data);
    // Assign to head
    if (head == NULL) {
        head = newnode;
        return;
    }
    Node *temp = head;

    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

// function to print the list
void LinkedList::PrintList()
{
    Node *temp = head;
    if(temp == NULL)
    {
        cout<<"Empty List";
        return;
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Function to delete the list
void LinkedList::deletelist(int nodeoffset)
{
    Node *temp1 = head,*temp2 = NULL;
    int count = 0;
    if(head == NULL)
    {
        cout<<"List is empty.."<<endl;
        return;
    }

    //find the length of linked list
    while(temp1!=NULL)
    {
        temp1 = temp1->next;
        count++;
    }

    // check wether pos is greater than length of list
    if(count<nodeoffset)
    {
        cout<<"Index out of the range."<<endl;
        return;
    }

    temp1 = head;
    // deleting the head node 
    if(nodeoffset == 1)
    {
        
        head = head->next;
        free(temp1);
        return;
    }
    while(nodeoffset-- > 1)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = temp1->next;
    free(temp1);

}


// main section
int main()
{ 
    LinkedList list;
   
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);
    list.insertNode(2);
    cout << "Elements of the list are: ";
  
    // Print the list
    list.PrintList();
    cout << endl;
    //delete element
    int pos;
    cout<<"Enter Position : ";
    cin>>pos;
    list.deletelist(pos);
    cout << "Elements of the list are: ";
  
    // Print the list
    list.PrintList();
    cout << endl;

    return 0;
}