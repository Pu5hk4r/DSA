#include <iostream>
#include <list>
using namespace std;

int kthLastElement(const list<int>& lst, int k) {
    if (k <= 0 || k > lst.size()) {
        return -1; // or handle the error as appropriate
    }
    
    auto it = lst.begin();
    auto kth_last_it = lst.begin();
    
    // Advance the iterator k positions ahead
    for (int i = 0; i < k; ++i) {
        ++it;
    }
    
    // Move both iterators until the end is reached
    while (it != lst.end()) {
        ++it;
        ++kth_last_it;
    }
    
    // kth_last_it now points to the Kth last element
    return *kth_last_it;
}

int main() {
    // Create and populate the list
    list<int> lst = {1, 2, 3, 4, 5, 6, 7};
    
    int k = 3;
    int result = kthLastElement(lst, k);
    if (result != -1) {
        cout << "The " << k << "rd last element is: " << result << endl;
    } else {
        cout << "The list has fewer than " << k << " elements." << endl;
    }
    
    return 0;
}
