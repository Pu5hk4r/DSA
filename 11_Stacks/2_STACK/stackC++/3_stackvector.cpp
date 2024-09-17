#include <iostream>
#include <vector>

class Stack {
    std::vector<int> vec;  // Vector to store stack elements

public:
    // Stack operations
    void push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

// Function to add an element to the stack
void Stack::push(int x) {
    vec.push_back(x);  // Add element to the end of the vector
    std::cout << x << " pushed into stack" << std::endl;
}

// Function to remove an element from the stack
int Stack::pop() {
    if (isEmpty()) {
        std::cout << "Stack Underflow" << std::endl;
        return -1;  // Use -1 to indicate an error
    } else {
        int x = vec.back();  // Get the top element
        vec.pop_back();  // Remove the top element
        return x;
    }
}

// Function to get the top element of the stack
int Stack::peek() {
    if (isEmpty()) {
        std::cout << "Stack is Empty" << std::endl;
        return -1;  // Use -1 to indicate an error
    } else {
        return vec.back();  // Return the top element
    }
}

// Function to check if the stack is empty
bool Stack::isEmpty() {
    return vec.empty();
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
