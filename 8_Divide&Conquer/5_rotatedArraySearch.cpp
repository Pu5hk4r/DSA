/*
a sorted array(ascending order) is rotated about pivot point which is unknown to us

we have to search given element in rotated array and return the index

original array[10,20,30,40,50] and rotated array [30,40,50,10,20] here 50 is pivot point

HOW TO RECOGNISE PIVOT POINT---> pivot point is the only element presnt in sorted array which 
defies the ascending order here in 50 is the only element in which its next element is 

smaller

no use linear search only use binary search
*/

#include<iostream>
#include<vector>
using namespace std;

int rotated_search(vector<int> a,int key) {
    int n = a.size();

    // Logic
    int s = 0;
    int e = n - 1;

    while(s <= e) {
        int mid = (s + e) / 2;

        if(a[mid] == key) {
            return mid;
        }

        // 2 cases
        if(a[s] <= a[mid]) {
            // Left half is sorted
            if(key >= a[s] && key <= a[mid]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        } else {
            // Right half is sorted
            if(key >= a[mid] && key <= a[e]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> a{4,5,6,7,0,1,2,3};
    int key;
    cin >> key;
    cout << rotated_search(a,key) << endl;
    return 0;
}
