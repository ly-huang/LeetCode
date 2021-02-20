//
//  main.cpp
//  leetcode697
//
//  Created by ly on 2021/2/20.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> data;
        unordered_map<int, int> left;
        unordered_map<int, int> right;
        int n=int(nums.size());
        for(int i=0;i<n;++i)
        {
            ++data[nums[i]];
            if(left.find(nums[i])==left.end())
                left[nums[i]]=i;
            right[nums[i]]=i;
        }
        int result=0;
        int mark=0;
        for(const auto &d:data)
        {
            if(d.second>mark)
            {
                mark=d.second;
                result=right[d.first]-left[d.first];
            }
            else if(d.second==mark)
            {
                result=min(result,right[d.first]-left[d.first]);
            }
        }
        return result+1;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums={1,2,2,3,1};
    cout<<Solution().findShortestSubArray(nums)<<endl;
    return 0;
}
