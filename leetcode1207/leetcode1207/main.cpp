//
//  main.cpp
//  leetcode1207
//
//  Created by ly on 2020/10/28.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;


bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int,int> m;
    for(const auto  &i:arr)
        m[i]++;
    set<int> s;
    for(const auto &i:m)
    {
        if(s.find(i.second)!=s.end())
            return false;
        s.emplace(i.second);
    }
    return true;
}

int main(int argc, const char * argv[]) {
    vector<int> arr={1,2,2,1,1,3};
    cout<<uniqueOccurrences(arr)<<endl;
    return 0;
}
