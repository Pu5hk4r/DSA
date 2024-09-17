/*

Stock Span Problem
Write a class StockSpanner which collects daily price quotes for some stock, and returns the span of 
that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days
 (starting from today and going backwards) for which the price of the stock was less than or equal 
 to today's price.
                                                                 1    2   3   4   5  6    7
For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85], 
then the stock spans would be                                   [1,   1,  1,  2,  1,  4,  6].



The span for a given day is the count of consecutive days (starting from that day and going backwards) 
for which the price of the stock is less than or equal to the price of the stock on the current day.
Example
Let’s use the example [100, 80, 60, 70, 60, 75, 85]:

Day 1 (Price = 100): The price is 100, and there are no previous days with a price less than 
or equal to 100. So, the span is 1 (just the current day itself).

Day 2 (Price = 80): The price is 80. The price on Day 1 was 100, which is more than 80. So, the span is 1.

Day 3 (Price = 60): The price is 60. The price on Day 1 was 100, and the price on Day 2 was 80, 
both are more than 60. So, the span is 1.

Day 4 (Price = 70): The price is 70. The prices on Day 1, Day 2, and Day 3 are higher than 70, but 
the price on Day 4 (70) is greater than the price on Day 3 (60). So, the span is 2 (Day 4 and Day 3).

Day 5 (Price = 60): The price is 60. The prices on Day 1, Day 2, and Day 3 are more than 60, 
but Day 4 has a price of 70. So, the span is 1.

Day 6 (Price = 75): The price is 75. The prices on Day 1, Day 2, and Day 3 are more than 75,
but the prices on Day 4 (70) and Day 5 (60) are less than 75. So, the span is 4 (Days 6, 5, 4, and 3).

Day 7 (Price = 85): The price is 85. All previous prices are less than 85. So, 
the span is 6 (Days 7, 6, 5, 4, 3, and 2).



*/

#include <iostream>
#include <stack>
#include <vector>

std::vector<int> stockspanner(std::vector<int> &stocks)
{
   int n = stocks.size();

   std::vector<int> span(n); // store span of each price

   std::stack<int> stk;// store indices of the stock prices

   for(int i {0} ; i<n;++i)
   {
   	  while(! stk.empty() and stocks[stk.top()] <= stocks[i])
   	  {
   	  	stk.pop();
   	  }

   	  if(stk.empty())
   	  {
   	  	span[i] = i+1;
   	  }
   	  else
   	  {
   	  	span[i] = i- stk.top();
   	  }


   	  stk.push(i);
   }


	return span;
}


int main()
{
	std::vector<int> prices = {100,80,60,70,60,75,85};

	std::vector<int> resulṭ = stockspanner(prices);

	for(const auto &span : resulṭ)
	{
		std::cout<<span<<" ";
	}

	std::cout<<"\n";

	return 0;
}