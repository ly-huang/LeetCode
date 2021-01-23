//
//  main.cpp
//  leetcode1319
//
//  Created by ly on 2021/1/23.
//

#include <iostream>
#include <vector>
using namespace std;

class UnionFind
{
public:
    UnionFind(const int &n):counts(n)
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
    bool merger(const vector<int> &e)
    {
        int fx=findf(e[0]);
        int fy=findf(e[1]);
        if(fx==fy)
            return false;
        f[fx]=fy;
        --counts;
        return true;
    }
    int getCounts()
    {
        return counts;
    }
private:
    vector<int> f;
    int counts;
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        UnionFind f(n);
        int lines=0;
        for(const auto &e:connections)
        {
            if(!f.merger(e))
                ++lines;
        }
        int counts=f.getCounts();
        if(counts==1)
            return 0;
        if(lines<--counts)
            return -1;
        return counts;
        
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> connections={{0,1},{0,2},{1,2}};
    Solution s;
    s.makeConnected(4, connections);
    return 0;
}
