#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

long long int factorial(long long int num)
{
    if(num ==0)
    {
        return 1;
    }

    return num*factorial(num-1);
}


int main()
{
   long long int numb {0};

   std::cout<<"enter the number: \n";
   std::cin>>numb;

   long long int F = factorial(numb);

   std::cout<<"Factorial of "<<numb<<"! is = "<<F<<"\n";

    return 0;
}