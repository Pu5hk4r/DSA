#include <iostream>

// Node structure for the linked list
struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}  // Node constructor
};

// Stack class using a linked list
class Stack {
    Node* top;

public:
    Stack() : top(nullptr) {}  // Constructor initializes top to nullptr

    // Stack operations
    void push(int x);
    int pop();
    int peek();
    bool isEmpty();
    ~Stack();  // Destructor to free up the allocated memory
};

// Function to add an element to the stack
void Stack::push(int x) {
    Node* newNode = new Node(x);  // Create a new node
    newNode->next = top;  // Point new node to the current top
    top = newNode;  // Update top to the new node
    std::cout << x << " pushed into stack" << std::endl;
}

// Function to remove an element from the stack
int Stack::pop() {
    if (isEmpty()) {
        std::cout << "Stack Underflow" << std::endl;
        return -1;  // Return an invalid value to indicate underflow
    } else {
        Node* temp = top;  // Temporary pointer to the top node
        int poppedValue = top->data;  // Store the data of the top node
        top = top->next;  // Update top to the next node
        delete temp;  // Free the memory of the old top node
        return poppedValue;
    }
}

// Function to get the top element of the stack
int Stack::peek() {
    if (isEmpty()) {
        std::cout << "Stack is Empty" << std::endl;
        return -1;  // Return an invalid value to indicate empty stack
    } else {
        return top->data;  // Return the data of the top node
    }
}

// Function to check if the stack is empty
bool Stack::isEmpty() {
    return top == nullptr;
}

// Destructor to free up the allocated memory
Stack::~Stack() {
    while (!isEmpty()) {
        pop();  // Pop all elements to free memory
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

    return 0;
}
