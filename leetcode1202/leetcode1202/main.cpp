//
//  main.cpp
//  leetcode1202
//
//  Created by ly on 2021/1/11.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int findf(vector<int> &f,const int &x)
{
    if(f[x]==x)
        return x;
    int father=findf(f,f[x]);
    f[x]=father;
    return father;
}

string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    if(s.empty())
        return s;
    int n=int(s.length());
    vector<int> f(n);
    for(int i=0;i<n;i++)
        f[i]=i;
    for(const auto &p:pairs)
    {
        f[findf(f,p[0])]=findf(f,p[1]);
    }
    unordered_map<int, pair<string,vector<int>>> m;
    for(int i=0;i<n;i++)
    {
        if(findf(f,i)==i)
            m[i]=make_pair("", vector<int>());
    }
    for(int i=0;i<n;i++)
    {
        m[f[i]].first+=s[i];
        m[f[i]].second.emplace_back(i);
    }
    for(auto &data:m)
    {
        sort(data.second.first.begin(), data.second.first.end());
        int l=int(data.second.first.length());
        for(int i=0;i<l;i++)
        {
            s[data.second.second[i]]=data.second.first[i];
        }
    }
    return s;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
