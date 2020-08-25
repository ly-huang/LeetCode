//
//  main.cpp
//  leetcode491
//
//  Created by ly on 2020/8/25.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void sortNums(vector<int>& nums,int begin,int end,vector<int>& index)
{
    if(begin>=end)
        return;
    int mid=begin+((end-begin)>>1);
    sortNums(nums, begin, mid,index);
    sortNums(nums, mid+1, end,index);
    int i=begin,j=mid+1;
    int t=begin;
    vector<int> temp=index;
    while(i<=mid&&j<=end)
    {
        if(nums[temp[i]]<nums[temp[j]])
            index[t]=temp[i++];
        else if(nums[temp[i]]>nums[temp[j]])
            index[t]=temp[j++];
        else if(temp[i]<temp[j])
            index[t]=temp[i++];
        else
            index[t]=temp[j++];
        t++;
    }
    while(i<=mid)
    {
        index[t]=temp[i++];
        t++;
    }
    while(j<=end)
    {
        index[t]=temp[j++];
        t++;
    }
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
    if(nums.empty())
        return {};
    int n=nums.size();
    vector<vector<int>> result;
    vector<int> index(n);
    for(int i=0;i<n;i++)
        index[i]=i;
    sortNums(nums, 0, n-1, index);
    for(int i=1;i<n;i++)
    {
        int m=result.size();
        for(int j=0;j<i;j++)
        {
            if(index[i]>index[j])
            {
                if(i-1<0||nums[index[i-1]]!=nums[index[i]]||index[i-1]<=index[j])
                {
                    result.push_back({index[j],index[i]});
                }
                while(j+1<i&&nums[index[j]]==nums[index[j+1]])
                    j++;
            }
        }
        for(int j=0;j<m;j++)
        {
            auto item=result[j];
            if(index[i]>item[item.size()-1])
            {
                if(i-1<0||nums[index[i-1]]!=nums[index[i]]||index[i-1]<=item[item.size()-1])
                {
                    item.push_back(index[i]);
                    result.push_back(item);
                }
            }
        }
    }
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            result[i][j]=nums[result[i][j]];
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> nums={1,2,3,1,2,3,1,2,3};
    auto result=findSubsequences(nums);
    for(auto items:result)
    {
        for(auto item:items)
            cout<<item<<" ";
        cout<<endl;
    }
    return 0;
}
