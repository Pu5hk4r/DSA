#include <iostream>
#include <queue>
#include <vector>

int main() {
    // Create a priority queue of integers
    std::priority_queue<int> pq;

    // Insert elements into the priority queue
    pq.push(10);
    pq.push(5);
    pq.push(30);
    pq.push(15);

    // Output elements in priority order (largest element first)
    std::cout << "Priority Queue elements: ";
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
