//
//  main.cpp
//  leetcode399(Union_Find)
//
//  Created by ly on 2021/1/6.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int findf(vector<int>& f, vector<double>& w, int x) { //寻找父节点并且压缩路径
    if(f[x]==x)
        return x;
    int father=findf(f, w, f[x]);
    w[x]*=w[f[x]];
    f[x]=father;
    return father;
}

void merge(vector<int>& f, vector<double>& w, int x, int y, double val) { //合并集合
    int fx=findf(f, w, x);
    int fy=findf(f, w, y);
    w[fx]=val*w[y]/w[x];
    f[fx]=fy;
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, int> v;
    int count=0;
    for(const auto &i:equations)
    {
        if(v.find(i[0])==v.end())
            v[i[0]]=count++;
        if(v.find(i[1])==v.end())
            v[i[1]]=count++;
    }
    vector<int> f(count);
    vector<double> w(count,1.0);
    for(int i=0;i<count;i++)//初始化集合
        f[i]=i;
    int n=int(equations.size());
    for(int i=0;i<n;i++)//根据题目条件合并集合
    {
        merge(f,w,v[equations[i][0]],v[equations[i][1]],values[i]);
    }
    n=int(queries.size());
    vector<double> result(n,-1.0);
    for(int i=0;i<n;i++)
    {
        string a=queries[i][0];
        string b=queries[i][1];
        if(v.find(a)!=v.end()&&v.find(b)!=v.end())
        {
            if(findf(f, w, v[a])==findf(f, w, v[b])) //处于同一集合中才能计算结果
                result[i]=w[v[a]]/w[v[b]];
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<string>> equations={{"a","b"},{"b","c"}};
    vector<double> values={2.0,3.0};
    vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    auto result=calcEquation(equations, values, queries);
    return 0;
}
