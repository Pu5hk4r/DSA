#include<bits/stdc++.h>

using namespace std;

void helper(vector<int> &vec,int n,int i)
{
    if(i>n) return ;

    vec.push_back(i);

    helper(vec,n,i+1);

    return;

}

vector<int> print(int N)
{
    vector<int> vec;

    helper(vec,N,0);

    return vec;
}