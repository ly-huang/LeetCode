//
//  main.cpp
//  leetcode765
//
//  Created by ly on 2021/2/14.
//

#include <iostream>
#include <vector>
using namespace std;

class UnionFind
{
private:
    vector<int> f;
    int setNum;
public:
    UnionFind(int n):setNum(n)
    {
        f.resize(n);
        for(int i=0;i<n;++i)
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
    void merger(int x,int y)
    {
        int fx=findf(x);
        int fy=findf(y);
        if(fx!=fy)
        {
            f[fx]=fy;
            --setNum;
        }
    }
    int getSetNum()
    {
        return setNum;
    }
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=int(row.size());
        UnionFind f(n/2);
        for(int i=0;i<n;i+=2)
        {
            f.merger(row[i]/2, row[i+1]/2);
        }
        return n/2-f.getSetNum();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
