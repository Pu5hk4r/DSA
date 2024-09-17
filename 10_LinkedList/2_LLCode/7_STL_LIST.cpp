#include <iostream>
#include <list> // double linked list

int main() {
    std::list<int> myList;

    // Insert elements at the back and front
    myList.push_back(10);  // {10}
    myList.push_front(20); // {20, 10}
    myList.push_back(30);  // {20, 10, 30}

    // Access the first and last element
    std::cout << "First element: " << myList.front() << std::endl;
    std::cout << "Last element: " << myList.back() << std::endl;

    // Insert at a specific position (second position)
    auto it = myList.begin();
    std::advance(it, 1); // Move iterator to second position
    myList.insert(it, 15); // {20, 15, 10, 30}

    // Print list elements
    std::cout << "List elements: ";
    for (int val : myList) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Erase an element at the second position
    it = myList.begin();
    std::advance(it, 1); // Move iterator to second position
    myList.erase(it);    // {20, 10, 30}

    // Size of the list
    std::cout << "List size: " << myList.size() << std::endl;

    // Reverse the list
    myList.reverse(); // {30, 10, 20}
    std::cout << "Reversed list: ";
    for (int val : myList) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Sort the list
    myList.sort(); // {10, 20, 30}
    std::cout << "Sorted list: ";
    for (int val : myList) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Remove an element by value
    myList.remove(20); // {10, 30}
    std::cout << "List after removing 20: ";
    for (int val : myList) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Clear the list
    myList.clear();
    std::cout << "List size after clearing: " << myList.size() << std::endl;

    return 0;
}
