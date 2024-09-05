#include<bits/stdc++.h>
using namespace std;

string vowel(string S) {
    // your code goes here
    string result = "";
    for (auto i = 0; i < S.size(); i++) {
        if (S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u') {
            result += S[i];
        }
    }
    return result;
}