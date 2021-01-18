//
//  main.cpp
//  leetcode721
//
//  Created by ly on 2021/1/18.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>
using namespace std;

int findf(vector<int> &f,int x)
{
    if(f[x]==x)
        return x;
    return f[x]=findf(f, f[x]);
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    if(accounts.empty())
        return {};
    int n=int(accounts.size());
    vector<int> f(n);
    for(int i=0;i<n;i++)
    {
        f[i]=i;
    }
    map<string, int> data;
    for(int i=0;i<n;i++)
    {
        int m=(int)accounts[i].size();
        for(int j=1;j<m;j++)
        {
            if(data.find(accounts[i][j])!=data.end())
            {
                if(accounts[i][0]==accounts[data[accounts[i][j]]][0])
                {
                    int fx=findf(f, i);
                    int fy=findf(f, data[accounts[i][j]]);
                    if(fx!=fy)
                        fx<fy?f[fy]=fx:f[fx]=fy;
                }
            }
            else
                data[accounts[i][j]]=i;
        }
    }
    unordered_map<int, int> newId;
    vector<vector<string>> result;
    for(int i=0;i<n;i++)
    {
        if(findf(f, i)==i)
        {
            newId[i]=(int)newId.size();
            result.push_back({accounts[i][0]});
        }
    }
    for(const auto &d:data)
    {
        result[newId[f[d.second]]].emplace_back(d.first);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<string>> accounts=
    {{"Alex","Alex5@m.co","Alex4@m.co","Alex0@m.co"},{"Ethan","Ethan3@m.co","Ethan3@m.co","Ethan0@m.co"},{"Kevin","Kevin4@m.co","Kevin2@m.co","Kevin2@m.co"},{"Gabe","Gabe0@m.co","Gabe3@m.co","Gabe2@m.co"},{"Gabe","Gabe3@m.co","Gabe4@m.co","Gabe2@m.co"}};
    accountsMerge(accounts);
    return 0;
}
