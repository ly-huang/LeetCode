//
//  main.cpp
//  leetcode839
//
//  Created by ly on 2021/1/31.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class UnionFind{
private:
    vector<int> f;
    int setNum;
public:
    UnionFind(const int &n):setNum(n)
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
        int fx=findf(x);
        int fy=findf(y);
        if(fx==fy)
            return;
        f[fx]=f[fy];
        --setNum;
    }
    int getSetNum()
    {
        return setNum;
    }
};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n=int(strs.size());
        UnionFind f(n);
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                if(f.findf(i)!=f.findf(j))
                {
                    if(isSimilar(strs[i], strs[j]))
                        f.merge(i, j);
                }
            }
        }
        return f.getSetNum();
    }
private:
    bool isSimilar(const string &s1,const string &s2)const
    {
        if(s1==s2)
            return true;
        if(s1.length()!=s2.length())
            return false;
        int num=0;
        int n=int(s1.length());
        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s2[i])
                num++;
        }
        if(num>2)
            return false;
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
