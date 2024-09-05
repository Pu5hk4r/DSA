#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

long long int fib(long long int num)
{
    if(num ==0 or num==1)
    {
        return num;
    }

    return fib(num-1)+fib(num-2);
}


int main()
{
   long long int numb {0};

   std::cout<<"enter the number: \n";
   std::cin>>numb;

   long long int F = fib(numb);

   std::cout<<"Fibonacci number is "<<numb<<"! is = "<<F<<"\n";

    return 0;
}