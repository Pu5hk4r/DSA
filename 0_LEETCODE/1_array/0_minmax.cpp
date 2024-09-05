#include <iostream>
#include <climits>
#include <algorithm>
#include <utility>

struct Pair
{
	int min;
	int max;
};


Pair getminmax(int *arr,size_t n){

	Pair minmax;

	std::sort(arr,arr+n);

	minmax.min =arr[0];

	minmax.max = arr[n-1];


	return minmax;
}


int setmini(int *arr, size_t n){

	int mini = INT_MAX;

	for(auto i=0;i<n;i++){

		if(arr[i] < mini){

			mini = arr[i];
		}
	}

	return mini;
}


int setmaxi(int *arr, size_t n){

	int maxi = INT_MIN;

	for(auto i=0;i<n;i++){

		if(arr[i] > maxi){

			maxi = arr[i];
		}
	}

	return maxi;
}




 int main()
{
	int arr[] = {12,78,98,100,5,1,789};

	size_t n = sizeof(arr)/sizeof(int);

	Pair minmax = getminmax(arr,n);

	std::cout<<"============ method 1 O(n) ===================================="<<"\n";

	std::cout<<"minimum elements using INT_MAX "<<setmini(arr,n)<<"\n";
	std::cout<<"maximum elements INT_MIN "<<setmaxi(arr,n)<<std::endl<<"\n\n";

	std::cout<<"============Sorting-Pair method O(nlogn)===================================="<<"\n";

	std::cout << "Minimum element is " << minmax.min << std::endl;
    std::cout << "Maximum element is " << minmax.max <<std::endl;
	return 0;
}