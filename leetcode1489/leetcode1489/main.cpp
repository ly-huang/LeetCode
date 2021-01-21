//
//  main.cpp
//  leetcode1489
//
//  Created by ly on 2021/1/21.
//

#include <iostream>
#include <vector>
using namespace std;

class UnionFind
{
public:
    UnionFind(int n):setCount(n),weights(0)
    {
        f.resize(n);
        for(int i=0;i<n;i++)
        {
            f[i]=i;
        }
    }
    int findf(int x)
    {
        if(f[x]==x)
            return x;
        return f[x]=findf(f[x]);
    }
    bool merger(const vector<int> &x)
    {
        int fx=findf(x[0]);
        int fy=findf(x[1]);
        if(fx==fy)
            return false;
        f[fx]=fy;
        setCount--;
        weights+=x[2];
        return true;
    }
    int getSetCount()const
    {
        return setCount;
    }
    int getWeights()const
    {
        return weights;
    }
private:
    vector<int> f;
    int setCount;
    int weights;
};


class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m=int(edges.size());
        for(int i=0;i<m;i++)
        {
            edges[i].emplace_back(i);
        }
        sort(edges.begin(), edges.end(), [](const auto &x,const auto &y){return x[2]<y[2];});
        int weights=0;
        {
            UnionFind uf(n);
            for(int i=0;i<m&&uf.getSetCount()>1;i++)
            {
                uf.merger(edges[i]);
            }
            weights=uf.getWeights();
        }
        vector<vector<int>> result(2);
        for(int i=0;i<m;i++)
        {
            {//判断是否是关键边
                UnionFind uf(n);
                for(int j=0;j<m&&uf.getSetCount()>1;j++)
                {
                    if(i!=j)
                        uf.merger(edges[j]);
                }
                if(uf.getSetCount()>1||uf.getWeights()>weights)
                {
                    result[0].emplace_back(edges[i][3]);
                    continue;
                }
            }
            {//判断是否为伪关键边
                UnionFind uf(n);
                uf.merger(edges[i]);
                for(int j=0;j<m&&uf.getSetCount()>1;j++)
                {
                    if(i!=j)
                        uf.merger(edges[j]);
                }
                if(uf.getSetCount()==1&&uf.getWeights()==weights)
                    result[1].emplace_back(edges[i][3]);
            }
            
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
