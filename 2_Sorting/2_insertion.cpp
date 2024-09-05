#include <iostream>
using namespace std;

// Sort the elements in increasing order 
void insertion_sort(int a[], int n) {
    for (int i = 1; i <= n - 1; i++) {
        int current = a[i];
        int prev = i - 1; 
        // Loop to find the right index where the element current should be inserted
        while (prev >= 0 && a[prev] > current) {
            a[prev + 1] = a[prev];
            prev = prev - 1;
        }
        a[prev + 1] = current; 
    }
}

int main() {
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);
    insertion_sort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}
