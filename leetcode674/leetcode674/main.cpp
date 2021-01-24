//
//  main.cpp
//  leetcode674
//
//  Created by ly on 2021/1/24.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int result=0;
        int left=0;
        int n=int(nums.size());
        for(int i=1;i<n;++i)
        {
            if(nums[i]>nums[i-1])
                continue;
            if(i-left>result)
                result=i-left;
            left=i;
        }
        if(n-left>result)
            result=n-left;
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
