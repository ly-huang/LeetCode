//
//  main.cpp
//  leetcode778
//
//  Created by ly on 2021/1/30.
//

#include <iostream>
#include <vector>
using namespace std;

class UnionFind{
public:
    UnionFind(const int &n)
    {
        f.resize(n);
        for(int i=0;i<n;++i)
        {
            f[i]=i;
        }
    }
    int findf(const int &x)
    {
        if(x==f[x])
            return x;
        return f[x]=findf(f[x]);
    }
    void merge(const int &x,const int &y)
    {
        f[findf(x)]=f[findf(y)];
    }
private:
    vector<int> f;
};

class Solution {
    struct Edge{
        int node1;
        int node2;
        int weights;
        Edge(const int &n1,const int &n2,const int &w):node1(n1),node2(n2),weights(w){}
    };
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=int(grid.size());
        vector<Edge> edges;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=n-1)
                {
                    edges.emplace_back(Edge(i*n+j,(i+1)*n+j,max(grid[i][j],grid[i+1][j])));
                }
                if(j!=n-1)
                {
                    edges.emplace_back(Edge(i*n+j,i*n+j+1,max(grid[i][j],grid[i][j+1])));
                }
            }
        }
        sort(edges.begin(), edges.end(),[](const Edge&e1,const Edge&e2){return e1.weights<e2.weights;});
        UnionFind f(n*n);
        for(const auto&e :edges)
        {
            f.merge(e.node1, e.node2);
            if(f.findf(0)==f.findf(n*n-1))
                return e.weights;
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
