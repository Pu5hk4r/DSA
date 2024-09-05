#include<iostream>
#include <algorithm>
using namespace std;
	

int SubarraySum(int *arr,int n){

    int largest_sum = 0;

    for(auto i =0;i<n;i++)
    {
        for(auto j =1;j<n;j++)
        {
            int subarray_sum =0;

            for(auto k=i;k<j;k++)
            {
               subarray_sum += arr[k];
            }

            largest_sum = std::max(largest_sum,subarray_sum);
        }

    }

    
        return largest_sum;

}


int main(){

	int arr[] = {10,15,12,9,6,4,3,10,8};
	int n = sizeof(arr)/sizeof(int);

	int sum = SubarraySum(arr,n);
	if(sum!=-1){
		cout<<" The sum is using bruteforce "<< sum <<endl;
	}
	else{
		cout<<" Sum is NOT Found!" <<endl;
	}


	return 0;
}