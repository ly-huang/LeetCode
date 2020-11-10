//
//  main.cpp
//  leetcode31
//
//  Created by ly on 2020/11/10.
//

#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n=int(nums.size())-1;
    int i;
    for(i=n-1;i>=0;i--)
    {
        if(nums[i]<nums[i+1])
            break;
    }
    int j=n;
    int temp;
    if(i>=0)
    {
        for(;j>i;j--)
        {
            if(nums[j]>nums[i])
                break;
        }
        temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    i++;
    j=n;
    while(i<j)
    {
        temp=nums[i];
        nums[i++]=nums[j];
        nums[j--]=temp;
    }
}

int main(int argc, const char * argv[]) {
    vector<int> nums={3,2,1};
    nextPermutation(nums);
    for(const auto &i:nums)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
