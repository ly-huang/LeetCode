//
//  main.cpp
//  leetcode485
//
//  Created by ly on 2021/2/15.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=int(nums.size());
        int left=0;
        int right=0;
        int result=0;
        while(right<n)
        {
            while(left<n&&!nums[left])
                ++left;
            if(left==n)
                break;
            right=left+1;
            while(right<n&&nums[right])
                ++right;
            if(right-left>result)
                result=right-left;
            left=right+1;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
