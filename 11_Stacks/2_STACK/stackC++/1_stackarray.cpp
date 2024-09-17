#include <iostream>
#define MAX 1000  // Define the maximum size of the stack

class Stack {
    int top;

public:
    int arr[MAX];  // Stack array

    Stack() { top = -1; }  // Constructor initializes top to -1

    // Stack operations
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

// Function to add an element to the stack
bool Stack::push(int x) {
    if (top >= (MAX - 1)) {
        std::cout << "Stack Overflow" << std::endl;
        return false;
    } else {
        arr[++top] = x;
        std::cout << x << " pushed into stack" << std::endl;
        return true;
    }
}

// Function to remove an element from the stack
int Stack::pop() {
    if (top < 0) {
        std::cout << "Stack Underflow" << std::endl;
        return -1;  // Use -1 to indicate an error
    } else {
        int x = arr[top--];
        return x;
    }
}

// Function to get the top element of the stack
int Stack::peek() {
    if (top < 0) {
        std::cout << "Stack is Empty" << std::endl;
        return -1;  // Use -1 to indicate an error
    } else {
        int x = arr[top];
        return x;
    }
}

// Function to check if the stack is empty
bool Stack::isEmpty() {
    return (top < 0);
}

// Main function to test the stack operations
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    std::cout << s.pop() << " popped from stack" << std::endl;
    std::cout << "Top element is " << s.peek() << std::endl;
    std::cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << std::endl;

    // Test edge case: pop from empty stack
    s.pop();  // Should pop 20
    s.pop();  // Should pop 10
    std::cout << s.pop() << " popped from empty stack" << std::endl;  // Should display error

    return 0;
}
