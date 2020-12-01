//
//  main.cpp
//  leetcode34
//
//  Created by ly on 2020/12/1.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int n=int(nums.size());
    int left=0;
    int right=n-1;
    int mid=0;
    vector<int> result={-1,-1};
    while(left<=right)
    {
        mid=left+(right-left)/2;
        if(nums[mid]<target)
            left=mid+1;
        else if(nums[mid]>target)
            right=mid-1;
        else
            break;
    }
    if(left>right)
        return result;
    int i=left;
    int j=mid;
    int m;
    while (i<j)
    {
        if(nums[i]==target)
            break;
        else
            i++;
        m=i+(j-i)/2;
        if(nums[m]<target)
            i=m+1;
        else if(nums[m]>target)
            j=m-1;
        else
            j=m;
    }
    result[0]=i;
    i=mid;
    j=right;
    while (i<j)
    {
        if(nums[j]==target)
            break;
        else
            j--;
        m=i+(j-i)/2;
        if(nums[m]<target)
            i=m+1;
        else if(nums[m]>target)
            j=m-1;
        else
            i=m;
    }
    result[1]=j;
    return result;
}


int main(int argc, const char * argv[]) {
    vector<int> nums={5,7,7,8,8,10};
    auto result=searchRange(nums, 8);
    cout<<result[0]<<","<<result[1]<<endl;
    return 0;
}
