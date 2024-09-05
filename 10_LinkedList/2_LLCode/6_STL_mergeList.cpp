#include <iostream>
#include <list>
using namespace std;

list<int> alternateMerge(list<int>& list1, list<int>& list2) {
    list<int> mergedList;
    auto it1 = list1.begin();
    auto it2 = list2.begin();

    // Alternate merge process
    while (it1 != list1.end() && it2 != list2.end()) {
        mergedList.push_back(*it1);
        mergedList.push_back(*it2);
        ++it1;
        ++it2;
    }

    // If list1 has remaining elements
    while (it1 != list1.end()) {
        mergedList.push_back(*it1);
        ++it1;
    }

    // If list2 has remaining elements
    while (it2 != list2.end()) {
        mergedList.push_back(*it2);
        ++it2;
    }

    return mergedList;
}

// Helper function to print the list
void printList(const list<int>& lst) {
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        cout << *it;
        if (next(it) != lst.end()) {
            cout << "->";
        }
    }
    cout << endl;
}

int main() {
    // Create first list: 5 -> 7 -> 17 -> 13 -> 11
    list<int> list1 = {5, 7, 17, 13, 11};

    // Create second list: 12 -> 10 -> 2 -> 4 -> 6
    list<int> list2 = {12, 10, 2, 4, 6};

    // Merge the lists
    list<int> mergedList = alternateMerge(list1, list2);

    // Print the merged list
    printList(mergedList);

    return 0;
}
