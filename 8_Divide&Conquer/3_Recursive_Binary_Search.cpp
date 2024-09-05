#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sortvector(vector <int> &v)
{
    sort(v.begin(),v.end());
}
int binarysearch(const vector<int> &v,int s,int e,int x)
 
{
    if(s > e) return - 1;

    int mid = s+(e-s) /2;

    if(v[mid] == x)  return mid;

    else if(v[mid] > x)  return binarysearch(v,s,mid-1,x);


    else  return binarysearch(v,mid+1,e,x);


}

int main()
{
     vector<int> v = {8, 3, 5, 1, 9, 4, 7, 2, 6};
    int x = 4;
    
    // Sort the vector if it's unsorted
    sortvector(v);

    int result = binarysearch(v, 0, v.size() - 1, x);
    
    if(result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}