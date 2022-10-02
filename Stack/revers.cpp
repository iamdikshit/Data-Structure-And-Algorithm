// C++ code to reverse a
// stack using recursion
#include <bits/stdc++.h>
#include<stack>
using namespace std;
 
// Below is a recursive function
// that inserts an element
// at the bottom of a stack.
void insert_at_bottom(stack<int> st, int x)
{
 
    if (st.size() == 0) {
        st.push(x);
    }
    else {
 
        // All items are held in Function Call
        // Stack until we reach end of the stack
        // When the stack becomes empty, the
        // st.size() becomes 0, the above if
        // part is executed and the item is
        // inserted at the bottom
 
        int a = st.top();
        st.pop();
        insert_at_bottom(st, x);
 
        // push allthe items held in
        // Function Call Stack
        // once the item is inserted
        // at the bottom
        st.push(a);
    }
}
 
// Below is the function that
// reverses the given stack using
// insert_at_bottom()
void reverse(stack<int> st)
{
    if (st.size() > 0) {
 
        // Hold all items in Function
        // Call Stack until we
        // reach end of the stack
        int x = st.top();
        st.pop();
        reverse(st);
 
        // Insert all the items held
        // in Function Call Stack
        // one by one from the bottom
        // to top. Every item is
        // inserted at the bottom
        insert_at_bottom(st, x);
    }
    return;
}
 
// Driver Code
int main()
{
    stack<int> st;
    // push elements into
    // the stack
    cout << "Original Stack" << endl;
    for (int i = 1; i <= 4; i++) {
        cout << i << " ";
        st.push(i);
    }
    cout << endl;
    // function to reverse
    // the stack
    reverse(st);
    cout << "Reversed Stack" << endl;
    // printing the stack after reversal
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
