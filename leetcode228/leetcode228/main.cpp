//
//  main.cpp
//  leetcode228
//
//  Created by ly` on 2021/1/10.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    if(nums.empty())
        return {};
    int n=int(nums.size());
    int left=nums[0];
    vector<string> result;
    
    for(int i=1;i<n;i++)
    {
        if(nums[i]!=nums[i-1]+1)
        {
            if(left==nums[i-1])
            {
                result.emplace_back(to_string(left));
            }
            else
            {
                result.emplace_back(to_string(left)+"->"+to_string(nums[i-1]));
            }
            left=nums[i];
        }
    }
    if(left==nums[n-1])
    {
        result.emplace_back(to_string(left));
    }
    else
    {
        result.emplace_back(to_string(left)+"->"+to_string(nums[n-1]));
    }
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
