// CPP program to reverse a Queue
#include <bits/stdc++.h>
#include<queue>
using namespace std;
 
// Utility function to print the queue
void Print(queue<int>& Queue)
{
	queue<int> q2 = Queue;
    while (!q2.empty()) {
        cout << q2.front() << " ";
        q2.pop();
    }
    cout<<"\n";
}
 
// Function to reverse the queue
void reverseQueue(queue<int>& q)
{
    // base case
    if (q.size() == 0)
        return;
    // storing front(first element) of queue
    int fr = q.front();
 
    // removing front
    q.pop();
 
    // asking recursion to reverse the
    // leftover queue
    reverseQueue(q);
 
    // placing first element
    // at its correct position
    q.push(fr);
}
 
// Driver code
int main()
{
    queue<int> Queue;
    Queue.push(10);
    Queue.push(20);
    Queue.push(30);
    Queue.push(40);
    Queue.push(50);
    Queue.push(60);
    Queue.push(70);
    Queue.push(80);
    Queue.push(90);
    Queue.push(100);
 	Print(Queue);
    reverseQueue(Queue);
    Print(Queue);
}
