//
//  main.cpp
//  leetcode75
//
//  Created by ly on 2020/10/7.
//

#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums) {
    int p1=0;
    int p2=int(nums.size())-1;
    int i=0;
    while(i<=p2)
    {
        if(nums[i]==0)
        {
            nums[i++]=nums[p1];
            nums[p1++]=0;
        }
        else if(nums[i]==2)
        {
            nums[i]=nums[p2];
            nums[p2--]=2;
        }
        else
            i++;
    }
}

int main(int argc, const char * argv[]) {
    vector<int> nums={2,0,1};
    sortColors(nums);
    for(const auto &i:nums)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
