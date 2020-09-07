//
//  main.cpp
//  leetcode347
//
//  Created by ly on 2020/9/7.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void qsort(vector<pair<int, int>>&nums,int left,int right,vector<int>&result,int k)
{
    if(left>right)
        return;
    int i=left;
    int j=right;
    while(i!=j)
    {
        while(i!=j&&nums[j].second<nums[left].second)
            j--;
        while(i!=j&&nums[i].second>=nums[left].second)
            i++;
        if(i!=j)
        {
            auto temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
        }
    }
    auto temp=nums[left];
    nums[left]=nums[i];
    nums[i]=temp;
    int n=i-left+1;
    if(n>k)
        qsort(nums,left,i-1,result,k);
    else
    {
        for(int t=left;t<=i;t++)
            result.push_back(nums[t].first);
        if(n==k)
            return;
        else
            qsort(nums, i+1, right, result,k-n);
    }
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    if(k<=0||nums.empty())
        return {};
    unordered_map<int,int> count;
    for(auto&i :nums)
        count[i]++;
    vector<pair<int, int>> data;
    for(auto& item:count)
        data.push_back(item);
    vector<int> result;
    qsort(data, 0, data.size()-1, result,k);
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> nums={1};
    auto result=topKFrequent(nums, 1);
    for(auto i:result)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
