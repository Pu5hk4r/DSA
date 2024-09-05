#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* last;

public:
    CircularLinkedList() {
        last = nullptr;
    }

    void addToEmpty(int data) {
        if (last != nullptr) return;

        Node* newNode = new Node;
        newNode->data = data;
        last = newNode;
        last->next = last; // Link to itself
    }

    void addToEnd(int data) {
        if (last == nullptr) {
            addToEmpty(data);
            return;
        }

        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = last->next; // New node points to the first node
        last->next = newNode; // Old last node points to new node
        last = newNode; // Update last to the new node
    }

    void display() {
        if (last == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = last->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }

    ~CircularLinkedList() {
        if (last == nullptr) return;

        Node* current = last->next;
        Node* nextNode;

        while (current != last) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        delete last; // Delete the last node
    }
};

int main() {
    CircularLinkedList cll;
    cll.addToEnd(10);
    cll.addToEnd(20);
    cll.addToEnd(30);
    cll.addToEnd(40);

    cll.display(); // Output: 10 20 30 40

    return 0;
}
