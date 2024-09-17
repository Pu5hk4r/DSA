#include <iostream>
#include <stack>

template<typename T>

T reversedNumber(T num)
{
   
   std::stack<T> stk;

   T reverse_num = 0;

   while(num > 0){

   	  T digit = num % 10;

   	  stk.push(digit);

   	  num /= 10;
   }

 T multiplier = 1;

 while(! stk.empty())
 {
 	reverse_num += stk.top() * multiplier;

 	stk.pop();

 	multiplier *=10;
 }

 return reverse_num;


}

int main()
{
   long num1 = 123456789;

   std::cout<<"reversedNumber "<<reversedNumber(num1)<<std::endl;

   return 0;
}

/*
Why do we need extra code to build the reversed number?
Yes, the stack does reverse the order of digits, but the stack only holds the digits. After reversing the 
digits using the stack, you need to form a valid number out of those digits. This is the purpose of the extra code.

When you push digits into the stack, they are stored in reverse order (as per the LIFO behavior of a stack).
 However, when you pop these digits, you need to reassemble them back into a number. To do this, you 
 multiply the digits by the corresponding place value (units, tens, hundreds, etc.).


reversed_num = 0 + 6 * 1 = 6

reversed_num = 6 + 5 * 10 = 6 + 50 = 56

reversed_num = 56 + 4 * 100 = 56 + 400 = 456


*/