/*
Friends' Party!
Given n friends, each one can remain single or can be paired up with some other friend.
 Each friend can be paired only once. Find out the total number of ways in which friends can 
 remain single or can be paired up.

Input Format

In the function an integer N is passed as parameter.

Output Format

Return an integer representing the total no. of ways



Sample Input

3
Sample Output

4
Explanation

{1}, {2}, {3} : all single
{1}, {2,3} : 2 and 3 paired but 1 is single.
{1,2}, {3} : 1 and 2 are paired but 3 is single.
{1,3}, {2} : 1 and 3 are paired but 2 is single.

Note that {1,2} and {2,1} are considered same

*/

#include <iostream>
#include <vector>

int countWays(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;

    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    std::cin >> n;
    std::cout << countWays(n) << std::endl;
    return 0;
}
/*

Explanation:
Function countWays(int n):

Base Cases: If n is 0 or 1, the function directly returns 1 because there is only one way to arrange the friends.
Dynamic Programming Array: We use a vector dp to store the number of ways to arrange friends for each count from 0 to n.
Recursive Relation: The value of dp[i] is computed using the formula:

dp[i]=dp[i−1]+(i−1)×dp[i−2]

This captures the cases where the first friend is either single or paired with one of the other i - 1 friends.
main Function:

Reads the input value n.
Calls countWays(n) to compute the result.
Outputs the result.


*/