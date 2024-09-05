#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        next = NULL;
    }
};

// Function to reverse the linked list
node* reverseLinkedList(node* head) {
    node* prev = NULL;
    node* curr = head;
    node* next = NULL;

    while (curr != NULL) {
        // Store the next node
        next = curr->next;
        // Reverse the current node's pointer
        curr->next = prev;
        // Move prev and curr one step forward
        prev = curr;
        curr = next;
    }

    // Update the head to the new front of the list
    head = prev;

    return head;
}

// Utility function to print the linked list
void printList(node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> NULL
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);

    cout << "Original list:" << endl;
    printList(head);

    head = reverseLinkedList(head);

    cout << "Reversed list:" << endl;
    printList(head);

    // Clean up memory
    while (head != NULL) {
        node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
