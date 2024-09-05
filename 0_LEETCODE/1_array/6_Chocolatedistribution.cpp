/*Problem Statement:
You have an array of N integers, where each integer represents the number of chocolates in a packet. 
There are m students, and you need to distribute the packets such that:
Each student gets exactly one packet.
The difference between the maximum and minimum number of chocolates in the packets distributed 
to the students is minimized*/

/*

Example:
Suppose you have N = 7 packets of chocolates: [12, 4, 7, 9, 2, 23, 25] and m = 3 students.

Sort the Array: [2, 4, 7, 9, 12, 23, 25]
Possible Subsets of 3 Packets:
[2, 4, 7] → difference = 7 - 2 = 5
[4, 7, 9] → difference = 9 - 4 = 5
[7, 9, 12] → difference = 12 - 7 = 5
[9, 12, 23] → difference = 23 - 9 = 14
[12, 23, 25] → difference = 25 - 12 = 13
Minimum Difference: The smallest difference is 5, so that is the optimal distribution.
Final Thoughts:
The key idea is to minimize the difference by leveraging the sorted nature of the array, 
ensuring you pick the most tightly packed group of m packets. This approach is efficient and ensures the 
difference is as small as possible.


*/
#include <bits/stdc++.h>

using namespace std;

int findMinDiff(int *arr,int n, int m) // arr[0....n-1] = size of packets m = no of students
{
  //no choclates or no students 

	if(m ==0 or n == 0)  return 0;


	std::sort(arr, arr+n);


	if(n < m) return -1; // no_students cant bemor than that of n_packets


	int min_diff = INT_MAX;


	for(int i = 0; i+m-1 < n; i++)
	{
		int diff = arr[i+m-1] - arr[i];

		if(diff < min_diff)
		{
			min_diff = diff;

		}
	}


	return min_diff;

}

int main()
{
    int arr[] = { 12, 4,  7,  9,  2,  23, 25, 41, 30,
                  40, 28, 42, 30, 44, 48, 43, 50 };
    int m = 7; // Number of students
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum difference is "
         << findMinDiff(arr, n, m);
    return 0;
}