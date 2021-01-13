//
//  main.cpp
//  leetcode684
//
//  Created by ly on 2021/1/13.
//

#include <iostream>
#include <vector>
using namespace std;

int findf(vector<int> &f,int x)
{
    if(f[x]==x)
        return x;
    f[x]=findf(f, f[x]);
    return f[x];
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n=int(edges.size())+1;
    vector<int> f(n);
    for(int i=0;i<n;i++)
    {
        f[i]=i;
    }
    int fx,fy;
    for(const auto &e:edges)
    {
        fx=findf(f, e[0]);
        fy=findf(f, e[1]);
        if(fx==fy)
        {
            if(e[0]<e[1])
                return {e[0],e[1]};
            else
                return {e[1],e[0]};
        }
        f[fx]=fy;
    }
    return{};
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> edges={{1,2},{1,3},{2,3}};
    auto result=findRedundantConnection(edges);
    cout<<result[0]<<" "<<result[1]<<endl;
    return 0;
}
