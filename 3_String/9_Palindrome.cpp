/*Given a string, write a c function to check if it is palindrome or not.

A string is said to be palindrome if reverse of the string is same as string. For example,
 “abba” is palindrome, but “abbc” is not palindrome.*/

 #include<bits/stdc++.h>
using namespace std;

bool isPalindrome(const string str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}