//
//  main.cpp
//  leetcode78
//
//  Created by ly on 2020/9/20.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    result.push_back({});
    if(nums.empty())
        return result;
    int n=int(nums.size());
    int m;
    vector<int> set;
    for(int i=0;i<n;i++)
    {
        m=int(result.size());
        for(int j=0;j<m;j++)
        {
            set=result[j];
            set.emplace_back(nums[i]);
            result.emplace_back(set);
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> nums={1,2,3};
    auto result=subsets(nums);
    for(const auto &item:result)
    {
        for(const auto &i:item)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
