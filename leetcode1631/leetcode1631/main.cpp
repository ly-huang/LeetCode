//
//  main.cpp
//  leetcode1631
//
//  Created by ly on 2021/1/29.
//

#include <iostream>
#include <vector>
using namespace std;

class UnionFind{
private:
    vector<int>f;
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
};

class Solution {
    struct Edge
    {
        int node1;
        int node2;
        int weights;
        Edge(int n1,int n2,int w):node1(n1),node2(n2),weights(w){}
    };
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=int(heights.size());
        int m=int(heights[0].size());
        vector<Edge> edges;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(j!=m-1)
                    edges.emplace_back(Edge(i*m+j,i*m+j+1,abs(heights[i][j]-heights[i][j+1])));
                if(i!=n-1)
                    edges.emplace_back(Edge(i*m+j,(i+1)*m+j,abs(heights[i][j]-heights[i+1][j])));
            }
        }
        sort(edges.begin(), edges.end(),[](const Edge &x,const Edge &y){return x.weights<y.weights;});
        UnionFind f(n*m);
        for(const auto &e:edges)
        {
            f.merge(e.node1, e.node2);
            if(f.findf(0)==f.findf(n*m-1))
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
