//
//  main.cpp
//  leetcode1128
//
//  Created by ly on 2021/1/26.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        if(dominoes.empty())
            return 0;
        unordered_map<string, int> data;
        int result=0;
        for(const auto &d:dominoes)
        {
            string str1=to_string(d[0])+","+to_string(d[1]);
            string str2=to_string(d[1])+","+to_string(d[0]);
            result+=data[str1];
            ++data[str1];
            if(str1!=str2)
                ++data[str2];
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> dominoes{{1,1},{2,2},{1,1},{1,2},{1,2},{1,1}};
    Solution s;
    cout<<s.numEquivDominoPairs(dominoes);
    return 0;
    
}
