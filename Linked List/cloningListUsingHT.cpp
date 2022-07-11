// Program to clone the linked list
#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

class Node{
    public:
    int data;
    Node *random;
    Node *next;

    // default constructor
    Node(){
        data = 0;
        random = NULL;
        next = NULL;
    }

    // parameterized constructor
    Node(int data)
    {
        this->data = data;
        this->random = NULL;
        this->next = NULL;
    }

};

class LinkedList{
    Node *head;
    public:
    // constructor
    LinkedList(){
        head = NULL;
    }
    Node *cloning(){
        Node *x,*y;
        
    }
    Node *PrintList(Node);
};

int main()
{
    return 0;
}