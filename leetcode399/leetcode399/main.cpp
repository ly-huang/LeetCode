//
//  main.cpp
//  leetcode399
//
//  Created by ly on 2021/1/6.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace  std;

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, unordered_map<string, double>> data;//构建图
    int n=int(equations.size());
    for(int i=0;i<n;i++)
    {
        if(data.find(equations[i][0])==data.end())
            data[equations[i][0]]=unordered_map<string, double>();
        data[equations[i][0]][equations[i][1]]=values[i];
        if(data.find(equations[i][1])==data.end())
            data[equations[i][1]]=unordered_map<string, double>();
        data[equations[i][1]][equations[i][0]]=1.0/values[i];
    }
    n=int(queries.size());
    vector<double> result(n,-1.0);
    for(int i=0;i<n;i++)
    {
        string qa=queries[i][0],qb=queries[i][1];
        if(data.find(qa)!=data.end()&&data.find(qb)!=data.end())
        {
            if(qa==qb)
                result[i]=1.0;
            else
            {
                //利用广度优先遍历查找a->b的路径
                queue<string> q;
                q.emplace(qa);
                unordered_map<string, double> m;//记录a到x的距离，并且根据其判断x是否已经被遍历过
                m[qa]=1.0;
                m[qb]=-1.0;
                while((!q.empty())&&m[qb]==-1.0)
                {
                    string cur=q.front();
                    q.pop();
                    for(const auto &v:data[cur])
                    {
                        if(m[v.first]<=0)//判断x是否已经被遍历过
                        {
                            m[v.first]=m[cur]*v.second;
                            if(v.first==qb)
                                break;
                            q.emplace(v.first);
                        }
                    }
                }
                result[i]=m[qb];
            }
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
