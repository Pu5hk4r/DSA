#include <iostream>
#include <stdexcept> // For std::runtime_error

// Node class for the linked list
class Node {
public:
    int data;   // Value stored in the node
    Node* next; // Pointer to the next node in the list

    // Constructor to initialize a node with a given value
    Node(int data) : data(data), next(nullptr) {}
};

// Queue class implemented using a linked list
class Queue {
private:
    Node* front; // Pointer to the front node of the queue
    Node* rear;  // Pointer to the rear node of the queue

public:
    // Constructor to initialize an empty queue
    Queue() : front(nullptr), rear(nullptr) {}

    // Destructor to clean up the linked list
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return front == nullptr;
    }

    // Add an element to the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Remove an element from the queue
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty, cannot dequeue" << std::endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    // Get the front element of the queue
    int getFront() const {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }
        return front->data;
    }

    // Print the elements in the queue
    void print() const {
        Node* temp = front;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue q;

    // Add elements to the queue
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    // Print the queue
    std::cout << "Queue contents: ";
    q.print(); // Output: 1 2 3 

    // Display the front element
    std::cout << "Front element: " << q.getFront() << std::endl; // Output: 1

    // Remove the front element
    q.dequeue();

    // Print the queue after dequeue
    std::cout << "Queue contents after dequeue: ";
    q.print(); // Output: 2 3

    // Display the new front element
    std::cout << "Front element after dequeue: " << q.getFront() << std::endl; // Output: 2

    return 0;
}
