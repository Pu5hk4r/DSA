/*
Sorting with Comparator
Given an integer vector and a bool variable flag, your task is to sort the vector in accordance to the boolean value. If the bool value passed is true then sort it in non-decreasing order or vice versa.
You can use any sorting technique of your choice.

Input Format

In the function an integer vector and a boolean is passed.



Output Format

Return an integer vector.



Sample Input

{111, 33, 5, 7, 29}, flag = 1



Sample Output

{5, 7, 29, 33, 111}


*/

#include<bits/stdc++.h>
using namespace std;

vector<int> sortingWithComparator(vector<int> vec, bool flag){
    // your code  goes here
    if(flag==true and flag ==1) {
        sort(vec.begin(),vec.end());
    }
    else if(flag == false and flag ==0) {
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());
    }
    
    return vec;
}