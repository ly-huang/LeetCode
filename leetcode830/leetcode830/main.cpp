//
//  main.cpp
//  leetcode830
//
//  Created by ly on 2021/1/5.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> largeGroupPositions(string s) {
    if(s.length()<3)
        return {};
    int n=int(s.length());
    int left=0;
    int right=0;
    vector<vector<int>> result;
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[left])
            right=i;
        else
        {
            if(right-left>=2)
                result.push_back({left,right});
            left=i;
        }
    }
    if(right-left>=2)
        result.push_back({left,right});
    return result;
}

int main(int argc, const char * argv[]) {
    string s="abcdddeeeeaabbbcd";
    auto result=largeGroupPositions(s);
    return 0;
}
