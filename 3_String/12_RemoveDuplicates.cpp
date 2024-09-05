#include <bits/stdc++.h>
using namespace std;

string removeDuplicate(string s) {
    // Create a set to store unique characters
    set<char> unique_chars(s.begin(), s.end());

    // Convert the set back to a string
    string result(unique_chars.begin(), unique_chars.end());

    // Sort the resulting string (though set already sorts the characters)
    sort(result.begin(), result.end());

    return result;
}


