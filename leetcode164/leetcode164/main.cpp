//
//  main.cpp
//  leetcode164
//
//  Created by ly on 2020/11/26.
//

#include <iostream>
#include <vector>
using namespace std;

void myQSort(vector<int> &nums,int left,int right)
{
    if(left>=right)
        return;
    int i=left;
    int j=right;
    int temp;
    while (i<j)
    {
        while(j>i&&nums[j]>nums[left])
            j--;
        while (i<j&&nums[i]<=nums[left])
            i++;
        temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    temp=nums[i];
    nums[i]=nums[left];
    nums[left]=temp;
    myQSort(nums, left, i-1);
    myQSort(nums, i+1, right);
}

int maximumGap(vector<int>& nums) {
    int n=int(nums.size());
    if(n<=1)
        return 0;
    myQSort(nums, 0, n-1);
    int result=nums[1]-nums[0];
    for(int i=2;i<n;i++)
    {
        if(nums[i]-nums[i-1]>result)
            result=nums[i]-nums[i-1];
    }
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
