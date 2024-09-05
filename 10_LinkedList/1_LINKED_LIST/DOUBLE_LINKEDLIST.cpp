#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() : head(nullptr) {}

    // Insertion at the beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insertion at the end
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Insertion after a given node
    void insertAfter(Node* prevNode, int data) {
        if (prevNode == nullptr) {
            std::cout << "Previous node cannot be null." << std::endl;
            return;
        }

        Node* newNode = new Node(data);
        newNode->next = prevNode->next;
        newNode->prev = prevNode;

        if (prevNode->next != nullptr) {
            prevNode->next->prev = newNode;
        }

        prevNode->next = newNode;
    }

    // Insertion before a given node
    void insertBefore(Node* nextNode, int data) {
        if (nextNode == nullptr) {
            std::cout << "Next node cannot be null." << std::endl;
            return;
        }

        Node* newNode = new Node(data);
        newNode->prev = nextNode->prev;
        newNode->next = nextNode;

        if (nextNode->prev != nullptr) {
            nextNode->prev->next = newNode;
        } else {
            head = newNode; // If inserting before the first node, update the head
        }

        nextNode->prev = newNode;
    }

    // Print the list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertAtBeginning(10);  // List: 10
    dll.insertAtEnd(20);        // List: 10 <-> 20
    dll.insertAtEnd(30);        // List: 10 <-> 20 <-> 30

    dll.insertAfter(dll.head->next, 25); // List: 10 <-> 20 <-> 25 <-> 30
    dll.insertBefore(dll.head, 5);       // List: 5 <-> 10 <-> 20 <-> 25 <-> 30

    dll.printList();  // Output: 5 10 20 25 30

    return 0;
}
