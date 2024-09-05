
#include <bits/stdc++.h>
using namespace std;

bool arePermutation(string A, string B)
{
    // Check if lengths of both strings are the same
    if (A.size() != B.size()) {
        return false;
    }

    // Sort both strings
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Compare sorted strings
    return A == B;
}
