//
//  main.cpp
//  leetcode632
//
//  Created by ly on 2020/8/1.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

//归并排序的合并过程
vector<int> smallestRange(vector<vector<int>>& nums)
{
    if(nums.empty())
        return {};
    vector<int> result={0,INT_MAX};
    int n=nums.size();
    vector<int> index(n,0);
    vector<int> includeNum;
    for(int i=0;i<n;i++)
        includeNum.push_back(nums[i][0]);
    while(true)
    {
        vector<int> temp={-1};
        for(int j=0;j<n;j++)
        {
            if(index[j]<nums[j].size())
            {
                if(temp[0]==-1)
                    temp[0]=j;
                else if(nums[j][index[j]]==nums[temp[0]][index[temp[0]]])
                    temp.push_back(j);
                else if(nums[j][index[j]]<nums[temp[0]][index[temp[0]]])
                    temp={j};
            }
        }
        if(temp[0]==-1)
            break;
        else
        {
            for(auto t:temp)
                includeNum[t]=nums[t][index[t]];
            int left=includeNum[0],right=includeNum[0];
            for(int i=0;i<n;i++)
            {
                if(includeNum[i]<left)
                    left=includeNum[i];
                else if(includeNum[i]>right)
                    right=includeNum[i];
            }
            if(right-left<result[1]-result[0])
            {
                result[0]=left;
                result[1]=right;
            }
            for(auto t:temp)
                index[t]++;
        }
    }
    return result;
}

int main(int argc, const char * argv[]){
    vector<vector<int>> nums={{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    auto redult=smallestRange(nums);
    cout<<redult[0]<<" "<<redult[1]<<endl;
    return 0;
}
