/*

All Occurence!
You are given an integer array of size N. Your aim is to find all the occurrences (indices) of a given element.



Input format:

Vector V and integer k (to find) are passed as parameters.



Output parameter:

Return a vector of integers containing all the indices in sorted manner.



Sample Input:

3

1 2 5 3 1 2 3 8 6 3 6 7 9

Sample Output:

3 6 9



*/

#include<iostream>
#include <vector>

void helper(int k,std::vector<int> &v,int i,std::vector<int> &result)
{

    if(v.size()==0) return;

    if(v[i]==k) result.push_back(i);

    helper(k,v,i+1,result);

}

std::vector<int> findallOcuurences(int k,std::vector<int> v)
{
    std::vector<int> result ;

    helper(k,v,0,result);

    return result;
}