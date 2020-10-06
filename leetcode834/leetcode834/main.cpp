//
//  main.cpp
//  leetcode834
//
//  Created by ly on 2020/10/6.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        _N=N;
        _nodes.resize(_N);
        _cnt.resize(_N);
        _ans.resize(N);
        for(int i=0;i<_N;i++)
        {
            _cnt[i]=1;
            _ans[i]=0;
        }
        for(const auto &i:edges)
        {
            _nodes[i[0]].emplace_back(i[1]);
            _nodes[i[1]].emplace_back(i[0]);
        }
        dfs(0, -1);
        dfs2(0,-1);
        return _ans;
        
    }
private:
    int _N;
    vector<vector<int>> _nodes;
    vector<int> _cnt;
    vector<int> _ans;
    void dfs(int child,int parent)
    {
        int n=int(_nodes[child].size());
        int next;
        for(int i=0;i<n;i++)
        {
            next=_nodes[child][i];
            if(next!=parent)
            {
                dfs(next,child);
                _cnt[child]+=_cnt[next];
                _ans[child]+=(_ans[next]+_cnt[next]);
            }
        }
    }
    
    void dfs2(int child,int parent)
    {
        int n=int(_nodes[child].size());
        int next;
        for(int i=0;i<n;i++)
        {
            next=_nodes[child][i];
            if(next!=parent)
            {
                _ans[next]=_ans[child]-_cnt[next]*2+_N;
                dfs2(next, child);
            }
        }
    }
    
};
int main(int argc, const char * argv[]) {
    vector<vector<int>> edges={{0,1},{0,2},{2,3},{2,4},{2,5}};
    Solution s;
    auto result=s.sumOfDistancesInTree(6, edges);
    for(const auto &i : result)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
