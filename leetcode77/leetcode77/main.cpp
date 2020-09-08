//
//  main.cpp
//  leetcode77
//
//  Created by ly on 2020/9/8.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void addNum(vector<vector<int>>&result,const int &n,const int &k,const int &index,vector<int> currentCombine,const int& cur)
{
    for(int i=cur+1;i<=n;i++)
    {
        currentCombine.push_back(i);
        if(index==k)
            result.push_back(currentCombine);

        else
            addNum(result, n, k, index+1, currentCombine,i);
        currentCombine.pop_back();

    }
}

vector<vector<int>> combine(int n, int k) {
    if(k<=0)
        return {};
    vector<vector<int>> result;
    addNum(result, n, k, 1, {},0);
    return result;
}
int main(int argc, const char * argv[]) {
    auto result=combine(4, 2);
    for(auto &item:result)
    {
        for(auto& i:item)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
