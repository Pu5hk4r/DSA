#include <iostream>
#include <vector>
using namespace std;

// Helper method
void merge(vector<int> &array, int s, int e) {
    int i = s;
    int m = (s + e) / 2;
    int j = m + 1;

    vector<int> temp;

    while (i <= m && j <= e) {
        if (array[i] < array[j]) {
            temp.push_back(array[i]);
            i++;
        } else {
            temp.push_back(array[j]);
            j++;
        }
    }

    // Copy remaining elements from first half
    while (i <= m) {
        temp.push_back(array[i++]);
    }

    // Copy remaining elements from second half
    while (j <= e) {
        temp.push_back(array[j++]);
    }

    // Copy back the elements from temp to original array
    int k = 0;
    for (int idx = s; idx <= e; idx++) {
        array[idx] = temp[k++];
    }
}

// Sorting method
void mergesort(vector<int> &arr, int s, int e) {
    // Base case
    if (s >= e) {
        return;
    }
    // Recursive case
    int mid = (s + e) / 2;
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);
    merge(arr, s, e); // Call merge function here combine them here
    
}

int main() {
    vector<int> arr{10, 5, 2, 0, 7, 6, 4};

    int s = 0;
    int e = arr.size() - 1;
    mergesort(arr, s, e);
    for (int x : arr) {
        cout << x << ",";
    }
    cout << endl;
    return 0;
}
