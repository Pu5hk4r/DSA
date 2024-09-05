#include<iostream>

int main()
{
    int a = 0;

    int b = 4;
    int c = 2;

    std::cout<<"~ of integer a is : "<<~a<<"\n";

    std::cout<<"~0 is diffrent: "<<~0<<"\n";

    std::cout<<" And---> "<< (b&c)<<"\n";

    std::cout<<" OR---> "<< (b|c)<<"\n";


    return 0;

}

/*

A << B === a*2^B;   5 << 2---->  5*2^2 = 20

A >> B  ==  a/ 2^B

All odd numbers has starting bit  1

all even number has starting bit 0

*/