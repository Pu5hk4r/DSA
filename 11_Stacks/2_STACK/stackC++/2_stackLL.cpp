#include <iostream>

// Node class for linked list
class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

// Stack class using linked list
class Stack {
    Node* top;

public:
    Stack() : top(nullptr) {}  // Constructor initializes top to nullptr

    // Stack operations
    void push(int x);
    int pop();
    int peek();
    bool isEmpty();
    ~Stack();  // Destructor to clean up the memory
};

// Function to add an element to the stack
void Stack::push(int x) {
    Node* newNode = new Node(x);
    newNode->next = top;
    top = newNode;
    std::cout << x << " pushed into stack" << std::endl;
}

// Function to remove an element from the stack
int Stack::pop() {
    if (isEmpty()) {
        std::cout << "Stack Underflow" << std::endl;
        return -1;  // Use -1 to indicate an error
    } else {
        Node* temp = top;
        int x = temp->data;
        top = top->next;
        delete temp;
        return x;
    }
}

// Function to get the top element of the stack
int Stack::peek() {
    if (isEmpty()) {
        std::cout << "Stack is Empty" << std::endl;
        return -1;  // Use -1 to indicate an error
    } else {
        return top->data;
    }
}

// Function to check if the stack is empty
bool Stack::isEmpty() {
    return (top == nullptr);
}

// Destructor to clean up the memory
Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
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
