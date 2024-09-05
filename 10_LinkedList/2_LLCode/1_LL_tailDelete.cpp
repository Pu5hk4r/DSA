/*


Delete Tail
Given a pointer to the root of the linklist, your task is to delete the tail of the linklist and return 
the head of the updated list.

Input

1->2->3->4->5->6->7->8

Output

1->2->3->4->5->6->7

*/

#include<bits/stdc++.h>
using namespace std;


class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

node* deleteTail(node* head) {
    // If the list is empty, return NULL
    if (head == NULL) {
        return NULL;
    }
    
    // If the list contains only one node, delete that node and return NULL
    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    // Traverse to the second-last node
    node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // At this point, temp is the second-to-last node
    delete temp->next; // Delete the last node
    temp->next = NULL; // Update the second-to-last node's next pointer

    return head;
}


