#include <iostream>
#include <string>
using namespace std;

void permute(string &s, int l, int r) {
    if (l == r) {
        cout << s << endl;
    } else {
        for (int i = l; i <= r; i++) {
            // Swap the characters at indices l and i
            swap(s[l], s[i]);

            // Recursively call permute on the remaining string
            permute(s, l + 1, r);

            // Backtrack: undo the swap
            swap(s[l], s[i]);
        }
    }
}

int main() {
    string str = "ABC";
    int n = str.size();
    permute(str, 0, n - 1);
    return 0;
}
