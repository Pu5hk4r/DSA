/*
Given a vector of pairs of a string and an integer representing names and prices of different fruits. A string is also passed as a parameter with name equals either "price", meaning you have to sort the fruits on the basis of their price or "name", which means you have to sort the fruit on the basis of their name.

Input Format

In the function an integer vector of pairs is passed.

Output Format

Return an integer vector of pairs in sorted order.



Sample Input

{ (Mango,100), (Guava,70), (Grapes,40), (Apple,60), (Banana,30) }, S = "price"


Sample Output

{ ("Banana", 30), ("Grapes", 40), ("Apple", 60), ("Guava", 70), ("Mango", 100) }


*/


#include <bits/stdc++.h>
using namespace std;

vector<pair<string, int>> sortFruits(vector<pair<string, int>> fruits, const string& sortBy) {
    if (sortBy == "price") {
        sort(fruits.begin(), fruits.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second < b.second;
        });
    } else if (sortBy == "name") {
        sort(fruits.begin(), fruits.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.first < b.first;
        });
    }
    return fruits;
}

int main() {
    vector<pair<string, int>> fruits = {{"Mango", 100}, {"Guava", 70}, {"Grapes", 40}, {"Apple", 60}, {"Banana", 30}};
    string sortBy = "price";  // You can change this to "name" to sort by names

    vector<pair<string, int>> sortedFruits = sortFruits(fruits, sortBy);

    for (const auto& fruit : sortedFruits) {
        cout << "(" << fruit.first << ", " << fruit.second << ")" << endl;
    }

    return 0;
}
