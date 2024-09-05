#include <iostream>
#include <queue>

class StackUsingQueues {
private:
    std::queue<int> q1, q2;

public:
    // Push element onto stack
    void push(int x) {
        if (!q1.empty()) {
            q1.push(x);
        } else {
            q2.push(x);
        }
    }

    // Removes the element on top of the stack
    void pop() {
        if (q1.empty() && q2.empty()) {
            std::cout << "Stack is empty\n";
            return;
        }

        if (!q1.empty()) {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
        } else {
            while (q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }
            q2.pop();
        }
    }

    // Get the top element
    int top() {
        if (q1.empty() && q2.empty()) {
            std::cout << "Stack is empty\n";
            return -1; // or throw an exception
        }

        int topElement;
        if (!q1.empty()) {
            while (!q1.empty()) {
                topElement = q1.front();
                q2.push(topElement);
                q1.pop();
            }
        } else {
            while (!q2.empty()) {
                topElement = q2.front();
                q1.push(topElement);
                q2.pop();
            }
        }

        return topElement;
    }

    // Check if the stack is empty
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

int main() {
    StackUsingQueues stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.top() << std::endl; // 30
    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << std::endl; // 20

    return 0;
}
