#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    // defaulter constructor
    Node(){
        data = 0;
        next = NULL;
    }

    // parameterized constructor
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
    void jose();
    
};

void LinkedList::jose(){
    Node *p,*q;
    int m,n;
    cout<<"Enter N (number of player )::";
    cin>>n;
    cout<<"Enter M (M-th player gets eliminated)::";
    cin>>m;
    // creating linked list
    p = q = (Node*)malloc(sizeof(Node));
    p->data = 1;
    for(int i = 2; i<=n; ++i)
    {
        p->next = (Node*)malloc(sizeof(Node));
        p = p->next;
        p->data = i;
    }

    // close the circular linked list by having the last node point to the 
    // first node
    p->next = q;
    // Eleminate every M-th player as long as more than one player remains
    for(int count = n; count>1; --count)
    {
        for(int i = 0; i<m-1; i++)
        {
            p = p->next;
        }
        p->next = p->next->next;// removing the eleminated player
    }
    cout<<"Last player left standing :"<<p->data;

}

int main()
{
    LinkedList list;
    list.jose();

    return 0;
}