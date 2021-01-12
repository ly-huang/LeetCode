//
//  main.cpp
//  leetcode1203
//
//  Created by ly on 2021/1/12.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;


bool getSort(vector<char> &mark,const vector<unordered_set<int>> &edges,const int & index,vector<int>&result)
{
    if(mark[index]=='2')
        return true;
    else if(mark[index]=='1')
        return false;
    mark[index]='1';
    for(const auto &i:edges[index])
    {
        if(!getSort(mark, edges, i, result))
            return false;
    }
    mark[index]='2';
    result.emplace_back(index);
    return true;
}

vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
    for(auto &i:group)
    {
        if(i==-1)
            i=m++;
    }
    vector<unordered_set<int>>g_edges(m,unordered_set<int>());
    vector<vector<int>> g(m,vector<int>());
    for(int i=0;i<n;i++)
    {
        g[group[i]].emplace_back(i);
        for(const auto &j:beforeItems[i])
        {
            if(group[j]!=group[i])
                g_edges[group[i]].insert(group[j]);
        }
    }
    vector<char> g_mark(m,'0');
    vector<int> g_result;
    for(int i=0;i<m;i++)
    {
        if(g_mark[i]=='0')
            if(!getSort(g_mark, g_edges, i, g_result))
                return {};
    }
    vector<int> result;
    for(const auto&i:g_result)
    {
        int num=(int)g[i].size();
        unordered_map<int, int> d;
        for(int j=0;j<num;j++)
        {
            d[g[i][j]]=j;
        }
        if(num==1)
            result.emplace_back(g[i][0]);
        else
        {
            vector<char> d_mark(num,'0');
            vector<unordered_set<int>> d_edges(num,unordered_set<int>());
            for(int j=0;j<num;j++)
            {
                for(const auto& t:beforeItems[g[i][j]])
                {
                    if(group[t]==i)
                        d_edges[j].insert(d[t]);
                }
            }
            vector<int> d_result;
            for(int j=0;j<num;j++)
            {
                if(d_mark[j]=='0')
                    if(!getSort(d_mark, d_edges, j, d_result))
                        return {};
                
            }
            for(const auto &j:d_result)
            {
                result.emplace_back(g[i][j]);
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> group={-1,-1,1,0,0,1,0,-1};
    vector<vector<int>> beforeItems={{},{6},{5},{6},{3,6},{},{},{}};
    sortItems(8, 2, group,beforeItems);
    return 0;
}
