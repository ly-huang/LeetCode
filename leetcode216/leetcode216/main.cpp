//
//  main.cpp
//  leetcode216
//
//  Created by ly on 2020/9/11.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void getResult(const int &k,const int &n,vector<vector<int>> &result,vector<int> &cur,const int &index)
{
    cur.emplace_back(index);
    if(index==n&&k==1)
    {
        result.emplace_back(cur);
    }
    else if(index<n&&index+1<=9&&k>0)
    {
        getResult(k-1, n-index, result, cur, index+1);
        cur.pop_back();
        getResult(k, n, result, cur, index+1);
        return;
    }
    cur.pop_back();
}

vector<vector<int>> combinationSum3(int k, int n) {
    if(k<=0||n<=0)
        return {};
    vector<vector<int>> result;
    vector<int> cur;
    getResult(k, n, result, cur, 1);
    return result;
}

int main(int argc, const char * argv[]) {
    auto result=combinationSum3(3, 7);
    for(const auto &item:result)
    {
        for(const auto &i:item)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
