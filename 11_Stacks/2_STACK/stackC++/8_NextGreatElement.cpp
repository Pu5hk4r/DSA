/*

Next Greater Element
Given an array, return the Next Greater Element for every element. The Next greater Element 
for an element x is the first greater element on the right side of x in the array. 
Elements for which no greater element exist, consider the next greater element as -1.

Input Format

In the function an integer vector is passed

Output Format

Return an integer vector containing the next greater element for each element



Sample Input

v = { 4, 5, 2, 25 }
Sample Output

{ 5, 25, 25, -1 }




*/

#include <iostream>
#include <vector>
#include <stack>

std::vector<int> nextGreaterElement(std::vector<int> v)
{
	size_t n = v.size();

	std::vector<int> vec (n,-1);

	std::stack<int> stk;

	for(size_t i=0;i<n ; ++i)
	{
		while(!stk.empty() and v[i] > v[stk.top()])
		{
			vec[stk.top()] = v[i];

			stk.pop();
		}

		stk.push(i);
	}

	return vec;


}

int main()
{
	std::vector<int> v = {4, 5, 2, 25};
    std::vector<int> result = nextGreaterElement(v);

    for (const auto &x : result) {
        std::cout << x << " ";
    }

    return 0;
}
