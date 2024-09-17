
#include <iostream>
#include <forward_list>

int main() {
    std::forward_list<int> myList;

    // Insert elements at the front
    myList.push_front(10);  // {10}
    myList.push_front(20);  // {20, 10}
    myList.push_front(30);  // {30, 20, 10}

    // Access the first element
    std::cout << "First element: " << myList.front() << std::endl;

    // Insert element after the first element
    auto it = myList.begin();
    myList.insert_after(it, 15);  // {30, 15, 20, 10}

    // Print all elements
    std::cout << "List elements: ";
    for (int val : myList) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Erase element after the first element
    it = myList.begin();
    myList.erase_after(it);  // {30, 20, 10}

    // Print all elements after erase
    std::cout << "List elements after erase: ";
    for (int val : myList) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Sort the list
    myList.sort();  // {10, 20, 30}
    std::cout << "Sorted list: ";
    for (int val : myList) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Reverse the list
    myList.reverse();  // {30, 20, 10}
    std::cout << "Reversed list: ";
    for (int val : myList) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Remove an element by value
    myList.remove(20);  // {30, 10}
    std::cout << "List after removing 20: ";
    for (int val : myList) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Clear the list
    myList.clear();
    std::cout << "List size after clearing: " << (myList.empty() ? 0 : 1) << std::endl;

    return 0;
}
