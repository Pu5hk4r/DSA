#include <iostream>
#include <stdexcept>

class Deque {
private:
    int* data;
    int front;
    int rear;
    int capacity;
    int size;

public:
    Deque(int cap) : capacity(cap), front(0), rear(cap - 1), size(0) {
        data = new int[capacity];
    }

    ~Deque() {
        delete[] data;
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }

    void addFront(int item) {
        if (isFull()) {
            throw std::overflow_error("Deque is full");
        }
        front = (front - 1 + capacity) % capacity;
        data[front] = item;
        ++size;
    }

    void addRear(int item) {
        if (isFull()) {
            throw std::overflow_error("Deque is full");
        }
        rear = (rear + 1) % capacity;
        data[rear] = item;
        ++size;
    }

    int removeFront() {
        if (isEmpty()) {
            throw std::underflow_error("Deque is empty");
        }
        int item = data[front];
        front = (front + 1) % capacity;
        --size;
        return item;
    }

    int removeRear() {
        if (isEmpty()) {
            throw std::underflow_error("Deque is empty");
        }
        int item = data[rear];
        rear = (rear - 1 + capacity) % capacity;
        --size;
        return item;
    }

    int getSize() const {
        return size;
    }

    void print() const {
        int count = size;
        int idx = front;
        while (count--) {
            std::cout << data[idx] << " ";
            idx = (idx + 1) % capacity;
        }
        std::cout << std::endl;
    }
};

int main() {
    Deque dq(5);

    dq.addRear(1);
    dq.addRear(2);
    dq.addFront(0);
    dq.print();  // Output: 0 1 2

    std::cout << "Removed from front: " << dq.removeFront() << std::endl;  // Output: 0
    std::cout << "Removed from rear: " << dq.removeRear() << std::endl;    // Output: 2

    dq.print();  // Output: 1

    return 0;
}
