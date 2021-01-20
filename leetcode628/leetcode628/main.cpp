//
//  main.cpp
//  leetcode628
//
//  Created by ly on 2021/1/20.
//

#include <iostream>
#include <vector>
using namespace std;

//int maximumProduct(vector<int>& nums) {
//    sort(nums.rbegin(), nums.rend());
//    int ret1=(*(nums.end()-1))*(*(nums.end()-2))*nums[0];
//    int ret2=nums[0]*nums[1]*nums[2];
//    return max(ret1,ret2);
//}

int maximumProduct(vector<int>& nums) {
    int min1=INT_MAX,min2=INT_MAX;
    int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN;
    for(const auto &i:nums)
    {
        if(i<min1)
        {
            min2=min1;
            min1=i;
        }
        else if (i<min2)
            min2=i;
        if(i>max1)
        {
            max3=max2;
            max2=max1;
            max1=i;
        }
        else if (i>max2)
        {
            max3=max2;
            max2=i;
        }
        else if(i>max3)
            max3=i;
    }
    return max(min1*min2*max1,max1*max2*max3);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
