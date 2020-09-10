//
//  main.cpp
//  leetcode40
//
//  Created by ly on 2020/9/10.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void myQsort(vector<int>& data,int left,int right)
{
    if(left>=right)
        return;
    int i=left;
    int j=right;
    while(i<j)
    {
        while(j>i&&data[j]>data[left])
            j--;
        while(i<j&&data[i]<=data[left])
            i++;
        if(i==j)
        {
            int temp=data[left];
            data[left]=data[i];
            data[i]=temp;
            break;
        }
        else
        {
            int temp=data[i];
            data[i]=data[j];
            data[j]=temp;
        }
    }
    myQsort(data, left, i-1);
    myQsort(data, i+1, right);
}

void getResult(vector<pair<int, int>> &data,const int &target,vector<vector<int>> &result,const int &index,vector<int> &cur)
{
    if(target==0)
    {
        result.emplace_back(cur);
        return;
    }
    if(index==data.size()||target<data[index].first)
        return;
    
    getResult(data, target, result, index+1, cur);
    
    int n=min(target/data[index].first,data[index].second);
    for(int i=1;i<=n;i++)
    {
        cur.emplace_back(data[index].first);
        getResult(data, target-data[index].first*i, result, index+1, cur);
    }
    for(int j=1;j<=n;j++)
        cur.pop_back();
    
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    int n=candidates.size();
    myQsort(candidates, 0, n-1);
    vector<pair<int, int>> data;
    data.emplace_back(make_pair(candidates[0],1));
    for(int i=1;i<n;i++)
    {
        if(candidates[i]!=candidates[i-1])
            data.emplace_back(make_pair(candidates[i], 1));
        else
            data[data.size()-1].second++;
    }
    vector<vector<int>> result;
    vector<int> cur;
    getResult(data, target, result, 0, cur);
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> candidates={2,5,2,1,2};
    auto result=combinationSum2(candidates, 5);
    for(auto &item:result)
    {
        for(auto &i:item)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
