#include <iostream>
#include <stack>

void insertATbottom(std::stack<int> &s, int data)
{
    if (s.empty())
    {
        s.push(data);
        return;
    }

    // Recursive case
    int temp = s.top();
    s.pop();
    insertATbottom(s, data);
    s.push(temp);
}

void reverse_stack(std::stack<int> &stk)
{
    if (stk.empty())
    {
        return;
    }

    // Hold all items in Function Call Stack
    int t = stk.top();
    stk.pop();

    // Reverse the remaining stack
    reverse_stack(stk);

    // Insert at the bottom
    insertATbottom(stk, t);
}

int main()
{
    std::stack<int> myStack;

    // Pushing elements into the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    // Reversing the stack
    reverse_stack(myStack);

    // Printing reversed stack
    while (!myStack.empty())
    {
        std::cout << myStack.top() << "\n";
        myStack.pop();
    }

    return 0;
}
