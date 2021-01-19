//
//  main.cpp
//  leetcode1584
//
//  Created by ly on 2021/1/19.
//

#include <iostream>
#include <vector>
using namespace std;


struct Data
{
    int node_i;
    int node_j;
    int weight;
    Data(const int &i,const int &j,const int &w)
    {
        node_i=i;
        node_j=j;
        weight=w;
    }
};


class Solution {
public:
    int findf(vector<int> &f,int x)
    {
        if(f[x]==x)
            return x;
        return f[x]=findf(f, f[x]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        if(points.empty())
            return 0;
        int n=(int)points.size();
        vector<int> f(n);
        for(int i=0;i<n;i++)
        {
            f[i]=i;
        }
        
        vector<Data> datas;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                datas.emplace_back(Data(i,j,abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])));
            }
        }
        sort(datas.begin(), datas.end(), [](const Data &x,const Data &y){if(x.weight<y.weight)return true;return false;});
        int result=0;
        int m=int(datas.size());
        for(int i=0;i<m&&n>1;i++)
        {
            int fx=findf(f, datas[i].node_i);
            int fy=findf(f, datas[i].node_j);
            if(fx!=fy)
            {
                f[fx]=fy;
                n--;
                result+=datas[i].weight;
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> points={{0,0},{2,2},{3,10},{5,2},{7,0}};
    Solution s;
    cout<<s.minCostConnectPoints(points)<<endl;
    return 0;
}
