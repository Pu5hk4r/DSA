#include <bits/stdc++.h>
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

node* alternateMerge(node *root1, node* root2) {
    // Check if either list is empty
    if (!root1) return root2; // If the first list is empty, return the second list
    if (!root2) return root1; // If the second list is empty, return the first list

    node* ptr1 = root1;
    node* ptr2 = root2;

    // Loop through both lists
    while (ptr1 != NULL && ptr2 != NULL) {
        // Save the next nodes
        node* temp1 = ptr1->next;
        node* temp2 = ptr2->next;

        // Insert node from second list into the first list
        ptr1->next = ptr2;
        ptr2->next = temp1;

        // Move the pointers forward
        ptr1 = temp1;
        ptr2 = temp2;
    }

    // If there are remaining nodes in the second list, append them to the end
    if (ptr2 != NULL) {
        ptr1->next = ptr2;
    }

    return root1;
}

// Helper function to print the list
void printList(node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL) {
            cout << "->";
        }
        head = head->next;
    }
    cout << endl;
}

// Helper function to delete the list
void deleteList(node* head) {
    while (head != NULL) {
        node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Create first list: 5 -> 7 -> 17 -> 13 -> 11
    node* head1 = new node(5);
    head1->next = new node(7);
    head1->next->next = new node(17);
    head1->next->next->next = new node(13);
    head1->next->next->next->next = new node(11);

    // Create second list: 12 -> 10 -> 2 -> 4 -> 6
    node* head2 = new node(12);
    head2->next = new node(10);
    head2->next->next = new node(2);
    head2->next->next->next = new node(4);
    head2->next->next->next->next = new node(6);

    // Merge the lists
    node* mergedHead = alternateMerge(head1, head2);

    // Print the merged list
    printList(mergedHead);

    // Clean up the list
    deleteList(mergedHead);

    return 0;
}
