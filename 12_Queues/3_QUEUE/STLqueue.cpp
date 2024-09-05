#include <iostream>
#include <queue>

int main() {
    // Create a queue of integers
    std::queue<int> q;

    // Add elements to the queue
    q.push(1);
    q.push(2);
    q.push(3);

    // Display the front element
    std::cout << "Front element: " << q.front() << std::endl; // Output: 1

    // Remove the front element
    q.pop();

    // Display the new front element
    std::cout << "Front element after pop: " << q.front() << std::endl; // Output: 2

    // Check if the queue is empty
    if (q.empty()) {
        std::cout << "Queue is empty" << std::endl;
    } else {
        std::cout << "Queue size: " << q.size() << std::endl; // Output: 2
    }

    return 0;
}
