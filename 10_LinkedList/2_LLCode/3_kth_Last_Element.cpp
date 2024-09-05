/*
Kth Last Element
Implement a function that returns the Kth last of element from the linked list, in a single pass. 
You can assume K will be less than / equal to length of linked list.

(Hint : Use two pointers similar to Runner Technique)

Input

You will get head of the linked list.

1 -> 2 -> 3 -> 4 -> 5 ->6 ->7

K = 3

Output

5



Explanation:

Third last element is 5.




*/

#include<bits/stdc++.h>
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

int kthLastElement(node *head, int k) {
    node* first = head;
    node* second = head;

    // Move the first pointer k steps ahead
    for (int i = 0; i < k; i++) {
        if (first == NULL) {
            // If k is greater than the number of elements in the list
            return -1; // or handle the error as appropriate
        }
        first = first->next;
    }

    // Move both pointers until the first pointer reaches the end
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    // The second pointer is now at the Kth last element
    return second->data;
}

int main() {
    // Create the linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = new node(6);
    head->next->next->next->next->next->next = new node(7);

    int k = 3;
    cout << "The " << k << "rd last element is: " << kthLastElement(head, k) << endl;

    // Clean up the linked list
    while (head != NULL) {
        node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

//***************************************************************************************************************

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

int kthLastElement(node *head, int k) {
    if (head == NULL || k <= 0) {
        return -1; // or handle the error as appropriate
    }
    
    node *fast = head;
    node *slow = head;

    // Move fast pointer k steps ahead
    int cnt = 0;
    while (cnt < k) {
        if (fast == NULL) {
            // If k is greater than the number of elements in the list
            return -1; // or handle the error as appropriate
        }
        fast = fast->next;
        cnt++;
    }

    // Move both pointers until fast reaches the end
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    // The slow pointer is now at the Kth last element
    return slow->data;
}

int main() {
    // Create the linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = new node(6);
    head->next->next->next->next->next->next = new node(7);

    int k = 3;
    int result = kthLastElement(head, k);
    if (result != -1) {
        cout << "The " << k << "rd last element is: " << result << endl;
    } else {
        cout << "The list has fewer than " << k << " elements." << endl;
    }

    // Clean up the linked list
    while (head != NULL) {
        node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

