//
//  main.cpp
//  leetcode0803
//
//  Created by ly on 2020/7/31.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

//跳跃查找
//int findMagicIndex(vector<int>& nums) {
//    if(nums.empty())
//        return -1;
//    for(int i=0;i<nums.size();)
//    {
//        if(nums[i]==i)
//            return i;
//        else if(nums[i]>i)
//            i=nums[i];
//        else
//            i++;
//
//    }
//    return -1;
//
//}



//二分剪枝
int fun(vector<int>&nums,int i, int j)
{
    if(i>j)
        return -1;
    int mid=i+((j-i)>>1);
    if(nums[mid]==mid)
    {
        if(mid==i)
            return i;
        else
            return fun(nums,i,mid);
    }
    int result=fun(nums,i,mid-1);
    if(result!=-1)
        return result;
    return fun(nums,mid+1,j);
}

int findMagicIndex(vector<int>& nums)
{
    if(nums.empty())
        return -1;
    return fun(nums,0,nums.size()-1);
}

int main(int argc, const char * argv[]) {
    vector<int> nums={1, 1, 1};
    cout<<findMagicIndex(nums)<<endl;
    return 0;
}
