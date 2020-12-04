//
//  main.cpp
//  leetcode659
//
//  Created by ly on 2020/12/4.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


bool isPossible(vector<int>& nums) {
    if(nums.empty())
        return false;
    unordered_map<int, int> data;
    for(auto i:nums)
        data[i]++;
    unordered_map<int, int> l;
    for(auto i:nums)
    {
        if(data[i]==0)
            continue;
        if(l[i-1]==0)
        {
            if(data[i+1]&&data[i+2])
            {
                data[i]--;
                data[i+1]--;
                data[i+2]--;
                l[i+2]++;
            }
            else
                return false;
        }
        else
        {
            data[i]--;
            l[i-1]--;
            l[i]++;
            
        }
    }
    return true;
}


int main(int argc, const char * argv[]) {
    vector<int> nums={1,2,3,4,4,5};
    cout<<isPossible(nums)<<endl;
    return 0;
}
