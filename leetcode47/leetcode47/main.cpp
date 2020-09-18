//
//  main.cpp
//  leetcode47
//
//  Created by ly on 2020/9/18.
//

#include <iostream>
#include <vector>
using namespace std;

void myQsort(vector<int> &nums,int left,int right)
{
    if(left>=right)
        return;
    int i=left;
    int j=right;
    while(i<j)
    {
        while(j>i&&nums[j]>nums[left])
            j--;
        while(i<j&&nums[i]<=nums[left])
            i++;
        if(i==j)
        {
            int temp=nums[left];
            nums[left]=nums[i];
            nums[i]=temp;
        }
        else
        {
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
        }
    }
    myQsort(nums, left, i-1);
    myQsort(nums, i+1, right);
}

void getResult(const vector<int> &nums,vector<vector<int>> &result,vector<bool> &mark,int index,vector<int> &current, const int &n)
{
    if(mark[index])
    {
        if(index+1<n)
            getResult(nums, result, mark, index+1, current, n);
        else
            return;
    }
    else
    {
        current.emplace_back(nums[index]);
        if(current.size()==n)
        {
            result.emplace_back(current);
            current.pop_back();
            return;
        }
        else
        {
            mark[index]=true;
            getResult(nums, result, mark, 0, current, n);
        }
        
        mark[index]=false;
        current.pop_back();
        int i=1;
        while(index+i<n&&nums[index+i]==nums[index])
            i++;
        if(index+i<n)
        {
            getResult(nums, result, mark, index+i, current, n);
        }
        
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    if(nums.empty())
        return {};
    int n=nums.size();
    vector<vector<int>> result;
    vector<bool> mark(n,false);
    vector<int> current;
    myQsort(nums, 0, n-1);
    getResult(nums, result, mark, 0, current, n);
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> nums={2,2,1,1};
    auto result=permuteUnique(nums);
    for(const auto &item:result)
    {
        for(const auto &i :item)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
