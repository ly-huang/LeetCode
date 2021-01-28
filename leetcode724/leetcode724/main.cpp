//
//  main.cpp
//  leetcode724
//
//  Created by ly on 2021/1/28.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(const auto &i:nums)
            sum+=i;
        int n=int(nums.size());
        int cur=0;
        for(int i=0;i<n;i++)
        {
            if(cur*2+nums[i]==sum)
            {
                return i;
            }
            cur+=nums[i];
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
