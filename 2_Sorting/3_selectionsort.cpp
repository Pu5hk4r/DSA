#include <iostream>
using namespace std;

// Sort the elements in increasing order 
void selection_sort(int a[], int n) {
    for (int pos = 0; pos <= n - 2; pos++) {
        int min_position = pos;
        // Find out the element
        for (int j = pos + 1; j < n; j++) {
            if (a[j] < a[min_position]) {
                min_position = j;
            }
        }
        // Swap outside the loop
        swap(a[min_position], a[pos]);
    }
}

int main() {
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);
    selection_sort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}
