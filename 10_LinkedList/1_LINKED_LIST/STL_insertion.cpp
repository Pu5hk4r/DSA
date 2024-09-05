
#include <iostream>
#include <list>
using namespace std;

class LinkedList {
private:
    list<int> l;

public:
    // Function to insert at the beginning
    void insertAtBeginning(int data) {
        l.push_front(data);
    }

    // Function to insert at the end
    void insertAtEnd(int data) {
        l.push_back(data);
    }

    // Function to insert after a given element
    void insertAfterElement(int data, int key) {
        auto it = find(l.begin(), l.end(), key);
        if (it != l.end()) {
            l.insert(++it, data);
        } else {
            cout << "Element " << key << " not found." << endl;
        }
    }

    // Function to insert before a given element
    void insertBeforeElement(int data, int key) {
        auto it = find(l.begin(), l.end(), key);
        if (it != l.end()) {
            l.insert(it, data);
        } else {
            cout << "Element " << key << " not found." << endl;
        }
    }

    // Function to insert at a specific position (1-based index)
    void insertAtPosition(int data, int position) {
        if (position <= 0) {
            cout << "Position should be >= 1." << endl;
            return;
        }
        auto it = l.begin();
        advance(it, position - 1);
        if (it != l.end() || position == 1) {
            l.insert(it, data);
        } else {
            cout << "Position out of bounds." << endl;
        }
    }

    // Function to display the list
    void display() {
        for (int x : l) {
            cout << x << " -> ";
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAfterElement(25, 20);
    list.insertBeforeElement(15, 20);
    list.insertAtPosition(5, 1);
    list.insertAtPosition(35, 7);

    list.display();

    return 0;
}
