//
//  main.cpp
//  leetcode685
//
//  Created by ly on 2020/9/17.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> &ancestor,int i)
{
    if(ancestor[i]==i)
        return i;
    ancestor[i]=find(ancestor, ancestor[i]);
    return ancestor[i];
}

void merge(vector<int> &ancestor,int i,int j)
{
    ancestor[find(ancestor, i)]=find(ancestor, j);
}

vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    if(edges.empty())
        return {};
    int n=edges.size();
    vector<int> parent(n+1);
    vector<int> ancestor(n+1);
    for(int i=0;i<n+1;i++)
        ancestor[i]=parent[i]=i;
    int conflict = -1;
    int cycle = -1;
    int node1;
    int node2;
    for(int i=0;i<n;i++)
    {
        node1=edges[i][0];
        node2=edges[i][1];
        if(parent[node2]!=node2)
            conflict=i;
        else
        {
            parent[node2]=node1;
            if(find(ancestor, node1)==find(ancestor, node2))
                cycle=i;
            else
                merge(ancestor,node1, node2);
        }
    }
    
    if (conflict < 0)
    {
        return edges[cycle];
    }
    else
    {
        auto conflictEdge = edges[conflict];
        if (cycle >= 0) {
            return {parent[edges[conflict][1]],edges[conflict][1]};
        }
        else
        {
            return edges[conflict];
        }
    }
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> edges={{1,2}, {2,3}, {3,4}, {4,1}, {1,5}};
    auto result=findRedundantDirectedConnection(edges);
    for(auto &i:result)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
