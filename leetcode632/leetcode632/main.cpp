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



vector<int> merge(vector<vector<int>>& nums,vector<vector<int>> &index)
{
    vector<int> result;
    int n=nums.size();
    vector<vector<int>> ptr(n);
    for(int i=0;i<n;i++)
    {
        ptr[i].push_back(0);
        ptr[i].push_back(nums[i].size());
    }
    while(true)
    {
        vector<int> temp={-1};
        for(int j=0;j<n;j++)
        {
            if(ptr[j][0]<ptr[j][1])
            {
                if(temp[0]==-1)
                    temp[0]=j;
                else if(nums[j][ptr[j][0]]==nums[temp[0]][ptr[temp[0]][0]])
                    temp.push_back(j);
                else if(nums[j][ptr[j][0]]<nums[temp[0]][ptr[temp[0]][0]])
                    temp={j};
            }
        }
        if(temp[0]==-1)
            break;
        else
        {
            index.push_back(temp);
            result.push_back(nums[temp[0]][ptr[temp[0]][0]]);
            for(auto t:temp)
                ptr[t][0]++;
        }
    }
    return result;
}

vector<int> smallestRange(vector<vector<int>>& nums)
{
    if(nums.empty())
        return {};
    vector<int> result(2,0);
    vector<vector<int>> index;
    auto newNums=merge(nums,index);
    vector<int> ptr(nums.size(),-1);
    int left=newNums[0],right=newNums.back();
    bool valid=false;
    for(int i=0;i<index.size();i++)
    {
        for(auto t:index[i])
            ptr[t]=i;
        if(!valid)
        {
            valid=true;
            for(auto t:ptr)
            {
                if(t==-1)
                {
                    valid=false;
                    break;
                }
            }
        }
        if(valid)
        {
            int min=ptr[0],max=ptr[0];
            for(auto t:ptr)
            {
                if(t<min)
                    min=t;
                else if(t>max)
                    max=t;
            }
            if(newNums[max]-newNums[min]<right-left)
            {
                left=newNums[min];
                right=newNums[max];
            }
        }

    }
    result[0]=left;
    result[1]=right;
    return result;
}

int main(int argc, const char * argv[]){
    vector<vector<int>> nums={{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    auto redult=smallestRange(nums);
    cout<<redult[0]<<" "<<redult[1]<<endl;
    return 0;
}
