#include <iostream>
#include <stdexcept>

template<typename T>
class CircularQueue {
public:
    CircularQueue(size_t size) : size(size), front(0), rear(0), count(0) {
        queue = new T[size];
    }

    ~CircularQueue() {
        delete[] queue;
    }

    void enqueue(const T& item) {
        if (is_full()) {
            throw std::runtime_error("Queue is full");
        }
        queue[rear] = item;
        rear = (rear + 1) % size;
        ++count;
    }

    T dequeue() {
        if (is_empty()) {
            throw std::runtime_error("Queue is empty");
        }
        T item = queue[front];
        front = (front + 1) % size;
        --count;
        return item;
    }

    bool is_empty() const {
        return count == 0;
    }

    bool is_full() const {
        return count == size;
    }

    size_t get_size() const {
        return count;
    }

private:
    T* queue;
    size_t size;
    size_t front;
    size_t rear;
    size_t count;
};

int main() {
    CircularQueue<int> cq(5);

    // Enqueue elements
    for (int i = 1; i <= 5; ++i) {
        cq.enqueue(i);
    }

    // Display queue size
    std::cout << "Queue size after enqueuing 5 elements: " << cq.get_size() << std::endl;

    // Dequeue elements and display
    while (!cq.is_empty()) {
        std::cout << "Dequeued: " << cq.dequeue() << std::endl;
    }

    // Display queue size
    std::cout << "Queue size after dequeuing all elements: " << cq.get_size() << std::endl;

    return 0;
}
