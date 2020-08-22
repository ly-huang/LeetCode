//
//  main.cpp
//  leetcode679
//
//  Created by ly on 2020/8/22.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool process(vector<double>& nums)
{
    int n=nums.size();
    if(n==1)
    {
        if(nums[0]>=24.0-0.000001&&nums[0]<=24.0+0.000001)
            return true;
        return false;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            vector<double> newData;
            for(int t=0;t<n;t++)
            {
                if(t!=i&&t!=j)
                    newData.push_back(nums[t]);
            }
            newData.push_back(nums[i]+nums[j]);
            if(process(newData))
               return true;
            newData[n-2]=nums[i]-nums[j];
            if(process(newData))
                return true;
            newData[n-2]=nums[j]-nums[i];
            if(process(newData))
                return true;
            newData[n-2]=nums[i]*nums[j];
            if(process(newData))
                return true;
            if(nums[j]<-0.000001||nums[j]>0.000001)
            {
                newData[n-2]=nums[i]/nums[j];
                if(process(newData))
                    return true;
            }
            if(nums[i]<-0.000001||nums[i]>0.000001)
            {
                newData[n-2]=nums[j]/nums[i];
                if(process(newData))
                    return true;
            }
        }
    }
    return false;
}

bool judgePoint24(vector<int>& nums) {
    if(nums.empty())
        return false;
    vector<double> data;
    for(auto item:nums)
        data.push_back(item);
    return process(data);
}

int main(int argc, const char * argv[]) {
    vector<int> nums={3,3,8,8};
    cout<<judgePoint24(nums)<<endl;
    return 0;
}
