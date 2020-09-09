//
//  main.cpp
//  leetcode39
//
//  Created by ly on 2020/9/9.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void getResult(vector<int>& candidates,int target,vector<vector<int>>& result,vector<int> &cur,int index)
{
    int temp=candidates[index];
    if(target==0)
    {
        result.emplace_back(cur);
        return;
    }
    if(target>=temp)
    {
        cur.emplace_back(temp);
        getResult(candidates, target-temp, result, cur, index);
        cur.pop_back();
    }
    if(index+1<candidates.size())
        getResult(candidates, target, result, cur, index+1);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> cur;
    getResult(candidates, target, result,cur,0);
    return result;
}
int main(int argc, const char * argv[]) {
    vector<int> candidates={2,3,6,7};
    auto result=combinationSum(candidates, 7);
    for(auto &item:result)
    {
        for(auto &i:item)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
