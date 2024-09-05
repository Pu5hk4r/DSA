#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Check if the queue is empty
    bool isEmpty() {
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

    // Get the front element
    int getFront() {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }
        return front->data;
    }

    // Destructor to clean up remaining nodes
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue q;

    // Add elements to the queue
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    // Display the front element
    std::cout << "Front element: " << q.getFront() << std::endl; // Output: 1

    // Remove the front element
    q.dequeue();

    // Display the new front element
    std::cout << "Front element after dequeue: " << q.getFront() << std::endl; // Output: 2

    return 0;
}
