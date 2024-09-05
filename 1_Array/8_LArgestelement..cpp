//Expected Time Complexity: O(N)

#include <iostream>
#include <vector>
#include <algorithm>

int largestElement(std::vector<int> &A) {
    
     return *std::max_element(A.begin(),A.end());
}

int main() {
    
    std::vector<int> vec {-3,4,1,2,3};
    
    std::cout<<largestElement(vec);
    
    
    return 0;
}