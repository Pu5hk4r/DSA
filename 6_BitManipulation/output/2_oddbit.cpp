#include<iostream>

using namespace std;


int main()
{
    std::cout<<"enter the number: \n";
    int num;
    std::cin>>num;

    if(num & 1 ){

        std::cout<<"ODD\n";
    } else {
        std::cout<<"Even";
    }

    return 0;
}