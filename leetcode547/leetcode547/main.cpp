//
//  main.cpp
//  leetcode547
//
//  Created by ly on 2021/1/7.
//

#include <iostream>
#include <vector>
using namespace std;

int inline findf(vector<int> &f,const int &x)
{
    if(f[x]==x)
        return x;
    int father=findf(f, f[x]);
    f[x]=father;
    return father;
}

void inline merge(vector<int> &f,const int &x,const int &y)
{
    int fx=findf(f, x);
    int fy=findf(f,y);
    f[fx]=fy;
}

int findCircleNum(vector<vector<int>>& isConnected) {
    if(isConnected.empty())
        return 0;
    int n=int(isConnected.size());
    vector<int>f(n);
    for(int i=0;i<n;i++)
        f[i]=i;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(isConnected[i][j])
                merge(f,i,j);
        }
    }
    int result=0;
    for(int i=0;i<n;i++)
    {
        if(findf(f, i)==i)
            ++result;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
