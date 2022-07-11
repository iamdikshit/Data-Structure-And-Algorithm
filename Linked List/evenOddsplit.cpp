#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(){
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList{
    Node *head;
    public:
    LinkedList(){
        head = NULL;
    }
    void insert(int);

    // ood even split fuction
    void oddeven();
    void PrintList();
};

void LinkedList::insert(int data){
    Node *current = head;
    Node *newnode = new Node(data);
    if(head == NULL)
    {
        head = newnode;
        return;
    }
    while(current->next!=NULL)
    {
        current = current->next;
    }
    current->next = newnode;
}

void LinkedList::PrintList()
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void LinkedList::oddeven()
{
    Node *current = head,*evenlist, *oddlist, *frontnode, *lastnode;
    if(head == NULL)
    {
        cout<<"List is empty";
        return;
    }
    while(current->next!=NULL)
    {
        if(current->data%2==0)
        {
            if(evenlist!=0 && evenlist->next!=NULL)
            {
                evenlist->next = current;
                evenlist = evenlist->next;
                lastnode = evenlist;
                current = current->next;
            }
            else{
                evenlist = current;
                head = evenlist;
                current = current->next;
            }

        }
        else{
            if(oddlist!=0 && oddlist->next!=NULL)
            {
                oddlist->next =current;
                oddlist = oddlist->next;
                current = current->next;
            }
            else{
                oddlist = current;
                frontnode = oddlist;
                current = current->next;
            }
        }
    }
    lastnode->next = frontnode;
}

int main()
{
    LinkedList list;
    
    for(int i = 1; i<=10 ; i++)
    {
        list.insert(i);
    }
    list.oddeven();
    
    list.PrintList();

    return 0;
}