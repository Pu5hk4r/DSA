#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> myList;  // Using STL list instead of a custom linked list

    int numnodes, data;

    cout << "Enter the number of nodes: " << "\n";
    cin >> numnodes;

    for (int i = 0; i < numnodes; i++) {
        cout << "Enter value of node " << (i + 1) << ": ";
        cin >> data;
        myList.push_back(data);  // Inserting at the end of the list
    }

    cout << "List elements are: [";
    for (const int &value : myList) {
        cout << value << " ";  // Traversing the list
    }
    cout << "]\n";

    // No need to manually delete the list; it is automatically managed by the STL container

    return 0;
}
