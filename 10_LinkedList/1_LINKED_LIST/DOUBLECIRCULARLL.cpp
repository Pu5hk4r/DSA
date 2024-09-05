#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyEndedCircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyEndedCircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void addToEmpty(int data) {
        if (head != nullptr) return;

        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = newNode;
        newNode->prev = newNode;
        head = tail = newNode;
    }

    void addToFront(int data) {
        if (head == nullptr) {
            addToEmpty(data);
            return;
        }

        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }

    void addToEnd(int data) {
        if (head == nullptr) {
            addToEmpty(data);
            return;
        }

        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }

    void displayForward() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void displayBackward() {
        if (tail == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = tail;
        do {
            cout << temp->data << " ";
            temp = temp->prev;
        } while (temp != tail);
        cout << endl;
    }

    ~DoublyEndedCircularLinkedList() {
        if (head == nullptr) return;

        Node* current = head;
        Node* nextNode;

        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
    }
};

int main() {
    DoublyEndedCircularLinkedList decll;
    decll.addToEnd(10);
    decll.addToEnd(20);
    decll.addToFront(5);
    decll.addToEnd(30);

    decll.displayForward();  // Output: 5 10 20 30
    decll.displayBackward(); // Output: 30 20 10 5

    return 0;
}
