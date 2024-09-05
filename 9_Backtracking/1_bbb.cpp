#include <iostream>
#include <vector>

using namespace std;

void printArray(int *arr, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";


    }

    cout<<endl;
}

void fillarray(int *arr,int i,int n,int val)// i= current index ,n= totak number of elements to fill in the array
{
    if(i==n)  //basecase    // val the value to be placed at current index i
    {
        printArray(arr,n);
        return;
    }

    arr[i] = val;           //rec case

    fillarray(arr,i+1,n,val+1);

    arr[i] = -1*arr[i];

    
}


int main()
{


    int arr[100] = {0};

    int n;

    cin>>n;

    fillarray(arr,0,n,1);

    printArray(arr,n);


    return 0;
}