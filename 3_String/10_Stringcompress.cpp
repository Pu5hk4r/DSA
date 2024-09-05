/*
Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3*/

#include <bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars) {
    int n = chars.size();
    if (n == 0) return 0; // Handle empty vector

    int index = 0; // Index to write the compressed characters
    int i = 0;

    while (i < n) {
        char currentChar = chars[i];
        int count = 0;

        // Count the occurrences of the current character
        while (i < n && chars[i] == currentChar) {
            ++i;
            ++count;
        }

        // Write the current character to the array
        chars[index++] = currentChar;

        // Write the count to the array if greater than 1
        if (count > 1) {
            stringstream ss;
            ss << count;
            string countStr = ss.str();
            for (char c : countStr) {
                chars[index++] = c;
            }
        }
    }

    return index; // Return the new length of the compressed array
}
