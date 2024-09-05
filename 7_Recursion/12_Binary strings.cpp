/*
Binary Strings!
You are given an integer N. Your task is to print all binary strings of 
size N without consecutive ones.

Constraints:

N<=12

Input Format

In the given function an integer N is passed as parameter.

Output Format

Return a vector of strings, with all possible strings in a sorted order.



Sample Input

3
Sample Output

000
001
010
100
101


*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generateStrings(int n, string current, vector<string>& result) {
    if (n == 0) {
        result.push_back(current);
        return;
    }

    // Add '0' and recurse
    generateStrings(n - 1, current + '0', result);

    // Add '1' and recurse, but only if the last character isn't '1'
    if (current.empty() || current.back() != '1') {
        generateStrings(n - 1, current + '1', result);
    }
}

vector<string> generateBinaryStrings(int n) {
    vector<string> result;
    generateStrings(n, "", result);
    return result;
}

int main() {
    int N;
    cin >> N;

    vector<string> binaryStrings = generateBinaryStrings(N);

    for (const string& s : binaryStrings) {
        cout << s << endl;
    }

    return 0;
}
