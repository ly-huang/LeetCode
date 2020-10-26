//
//  main.cpp
//  leetcode1365
//
//  Created by ly on 2020/10/26.
//

#include <iostream>
#include <vector>
using namespace std;

void myQSort(const vector<int>& nums,vector<int>&index,int left,int right)
{
    if(left>=right)
        return;
    int i=left;
    int j=right;
    int temp;
    while(i<j)
    {
        while(j>i&&nums[index[j]]>nums[index[left]])
            j--;
        while(i<j&&nums[index[i]]<=nums[index[left]])
            i++;
        temp=index[i];
        index[i]=index[j];
        index[j]=temp;
    }
    temp=index[i];
    index[i]=index[left];
    index[left]=temp;
    myQSort(nums, index, left, i-1);
    myQSort(nums, index, i+1, right);
}

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    if(nums.empty())
        return {};
    int n=int(nums.size());
    vector<int> index(n);
    for(int i=0;i<n;i++)
    {
        index[i]=i;
    }
    myQSort(nums, index, 0, n-1);
    vector<int> result(n);
    for(int i=0,j;i<n;i++)
    {
        j=i-1;
        while(j>=0&&nums[index[j]]==nums[index[i]])
            j--;
        j++;
        result[index[i]]=j;
        while(i+1<n&&nums[index[i+1]]==nums[index[i]])
            result[index[++i]]=j;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> nums={7,7,7};
    auto result=smallerNumbersThanCurrent(nums);
    for(const auto &i:result)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
