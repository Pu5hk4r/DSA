#include <iostream>
using namespace std;

// Run Length Encoding for String Compression
// If the compressed string is bigger than the original, return the original string
// Input: aaabbccddee
// Output: a3b2c2d2e2

// Input: abcd
// Output: abcd 

string compressString(const string& str) {
    int n = str.length();
    if (n == 0) return str; // Handle empty string

    string output;
    output.reserve(n); // Reserve space to avoid multiple reallocations

    for (int i = 0; i < n; ++i) {
        int count = 1;

        while (i < n - 1 && str[i + 1] == str[i]) {//this loop continues till the value str[i+1] != str[i]
            ++count;
            ++i;
        }
        output += str[i];
        output += to_string(count);
    }

    // Return original string if compressed string is not shorter
    return output.length() >= str.length() ? str : output;
}

int main() {
    string s1 = "aaabbccddee";
    cout << compressString(s1) << endl;

    string s2 = "abcd";
    cout << compressString(s2) << endl;

    return 0;
}
