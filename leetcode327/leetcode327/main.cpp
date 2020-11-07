//
//  main.cpp
//  leetcode327
//
//  Created by ly on 2020/11/7.
//

#include <iostream>
#include <vector>
using namespace std;

void countRangeSumRecursive(vector<long>& data, const int &lower, const int &upper, int left, int right,int &result)
{
    if(left>=right)
        return;
    int mid=left+(right-left)/2;
    countRangeSumRecursive(data, lower, upper, left, mid, result);
    countRangeSumRecursive(data, lower, upper, mid+1, right, result);

    int l=mid+1;//后面的和减前面的和
    int r=mid+1;
    int i=left;
    while(i<=mid)
    {
        while(l<=right&&data[l]-data[i]<lower)
            l++;
        r=l;
        while(r<=right&&data[r]-data[i]<=upper)
            r++;
        result+=(r-l);
        i++;
    }

    vector<long> temp;
    l=left;
    r=mid+1;
    while(l<=mid&&r<=right)
    {
        if(data[l]<data[r])
            temp.emplace_back(data[l++]);
        else
            temp.emplace_back(data[r++]);
    }
    while(l<=mid)
        temp.emplace_back(data[l++]);
    while(r<=right)
        temp.emplace_back(data[r++]);
    for(int i=left;i<=right;i++)
    {
        data[i]=temp[i-left];
    }
}

int countRangeSum(vector<int>& nums, int lower, int upper) {
    if(nums.empty())
        return 0;
    long sum=0;
    int n=int(nums.size());
    vector<long> data={0};//添加一个0
    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
        data.emplace_back(sum);
    }
    int result=0;
    countRangeSumRecursive(data, lower, upper, 0, n, result);
    return result;
}


int main(int argc, const char * argv[]) {
    vector<int> nums={-2,5,-1};
    cout<<countRangeSum(nums, -2, 2)<<endl;
    return 0;
}
