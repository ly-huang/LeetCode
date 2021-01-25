//
//  main.cpp
//  leetcode959
//
//  Created by ly on 2021/1/25.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class UnionFind
{
public:
    UnionFind(const int &n):setCount(n)
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
    void merger(const int &x,const int &y)
    {
        int fx=findf(x);
        int fy=findf(y);
        if(fx==fy)
            return;
        f[fx]=fy;
        setCount--;
    }
    int getSetCount()const
    {
        return setCount;
    }
private:
    vector<int>f;
    int setCount;
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        if(grid.empty()||grid[0].empty())
            return 0;
        int n=(int)grid.size();
        UnionFind f(4*n*n);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                int index=(i*n+j)*4;
                if(' '==grid[i][j])
                {
                    f.merger(index, index+1);
                    f.merger(index+1, index+2);
                    f.merger(index+2, index+3);
                }
                else if('/'==grid[i][j])
                {
                    f.merger(index, index+1);
                    f.merger(index+2, index+3);
                }
                else if('\\'==grid[i][j])
                {
                    f.merger(index+1, index+2);
                    f.merger(index, index+3);
                }
                if(i!=n-1)
                {
                    f.merger(index+3, ((i+1)*n+j)*4+1);
                }
                if(j!=n-1)
                {
                    f.merger(index+2, (i*n+j+1)*4);
                }
            }
        }
        return f.getSetCount();
    }
};

int main(int argc, const char * argv[]) {
    vector<string> grid({" /","/ "});
    Solution a;
    a.regionsBySlashes(grid);
    return 0;
}
