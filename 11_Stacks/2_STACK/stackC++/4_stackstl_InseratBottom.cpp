#include <iostream>
#include <stack>

void insertATbottom(std::stack<int> &s , int data)
{
    if(s.empty())
    {
        s.push(data);

        return;
    }

    //recursive case

    int temp = s.top();


    s.pop();
    insertATbottom(s,data);

    s.push(temp);
}

int main() {
    std::stack<int> myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Stack size: " << myStack.size() << std::endl;  // Size of the stack

    // Access the top element
    std::cout << "Top element: " << myStack.top() << std::endl;

    // Pop elements from the stack
    myStack.pop();
    std::cout << "Top element after pop: " << myStack.top() << std::endl;

    // Check if the stack is empty
    if (myStack.empty()) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        std::cout << "Stack is not empty" << std::endl;
    }

    std::cout<<"--------------insertatbottom--------------------------------------\n";

    insertATbottom(myStack,100);

    while(!myStack .empty()){

        std::cout<<myStack.top()<<"\n"; 

        myStack.pop(); 
    }

    return 0;
}
