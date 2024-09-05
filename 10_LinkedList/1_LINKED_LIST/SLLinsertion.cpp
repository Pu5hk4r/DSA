#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to insert at the beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    // Function to insert at the end
    void insertAtEnd(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to insert after a given node
    void insertAfterNode(int data, int key) {
        Node* temp = head;
        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Node with data " << key << " not found." << endl;
            return;
        }
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to insert before a given node
    void insertBeforeNode(int data, int key) {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        if (head->data == key) {
            insertAtBeginning(data);
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != key) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Node with data " << key << " not found." << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to insert at a specific position
    void insertAtPosition(int data, int position) {
        if (position == 1) {
            insertAtBeginning(data);
            return;
        }

        Node* temp = head;
        for (int i = 1; temp != nullptr && i < position - 1; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of bounds." << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAfterNode(25, 20);
    list.insertBeforeNode(15, 20);
    list.insertAtPosition(5, 1);
    list.insertAtPosition(35, 7);

    list.display();

    return 0;
}
