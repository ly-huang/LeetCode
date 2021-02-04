//
//  main.cpp
//  leetcode643
//
//  Created by ly on 2021/2/4.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        for(int i=0;i<k;++i)
        {
            sum+=nums[i];
        }
        int n=int(nums.size());
        int temp=sum;
        for(int i=k;i<n;++i)
        {
            temp=temp-nums[i-k]+nums[i];
            if(temp>sum)
                sum=temp;
        }
        return sum/k;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums={0,4,0,3,2};
    cout<<Solution().findMaxAverage(nums, 1)<<endl;
    return 0;
}
