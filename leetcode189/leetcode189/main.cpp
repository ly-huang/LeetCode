//
//  main.cpp
//  leetcode189
//
//  Created by ly on 2021/1/8.
//

#include <iostream>
#include <vector>
using namespace std;


void rotate(vector<int>& nums, int k) {
    int n=int(nums.size());
    k=k%n;
    if(k==0)
        return;
    for(int i=0,j=n-1;i<j;i++,j--)
    {
        nums[i]=nums[i]^nums[j];
        nums[j]=nums[i]^nums[j];
        nums[i]=nums[i]^nums[j];
    }
    for(int i=0,j=k-1;i<j;i++,j--)
    {
        nums[i]=nums[i]^nums[j];
        nums[j]=nums[i]^nums[j];
        nums[i]=nums[i]^nums[j];
    }
    for(int i=k,j=n-1;i<j;i++,j--)
    {
        nums[i]=nums[i]^nums[j];
        nums[j]=nums[i]^nums[j];
        nums[i]=nums[i]^nums[j];
    }
}
int main(int argc, const char * argv[]) {
    vector<int> nums={1,2,3,4,5,6,7,8};
    rotate(nums, 6);
    std::cout << "Hello, World!\n";
    return 0;
}
