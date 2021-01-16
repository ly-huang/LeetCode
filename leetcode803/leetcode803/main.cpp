//
//  main.cpp
//  leetcode803
//
//  Created by ly on 2021/1/16.
//

#include <iostream>
#include <vector>
using namespace std;


int findf(vector<int> &f,const int &x)
{
    if(f[x]==x)
        return x;
    f[x]=findf(f, f[x]);
    return f[x];
}

void merge(vector<int> &f, vector<int> &s, const int &x, const int &y)
{
    int fx=findf(f, x);
    int fy=findf(f, y);
    if(fx==fy)
        return;
    f[fx]=fy;
    s[fy]+=s[fx];
}

vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
    int n=(int)grid.size();
    int m=(int)grid[0].size();
    vector<vector<int>> data=grid;
    for(const auto &i:hits)
        data[i[0]][i[1]]=0;
    int markNode=n*m;        //标记为屋顶
    vector<int> f(markNode+1);
    for(int i=0;i<=markNode;i++)//初始化并查集
    {
        f[i]=i;
    }
    vector<int>size(markNode+1,1);//记录并查集每个集合的大小
    
    for(int i=0;i<n;i++)//将所有需要敲掉的砖块去除之后改变并查集
    {
        for(int j=0;j<m;j++)
        {
            if(data[i][j])
            {
                if(i==0)
                    merge(f, size, i*m+j, markNode);
                else if(data[i-1][j])
                    merge(f, size, i*m+j, (i-1)*m+j);
                if(j>0&&data[i][j-1])
                    merge(f, size, i*m+j, i*m+j-1);
            }
        }
    }
    vector<pair<int, int>> directions{{-1,0},{1,0},{0,-1},{0,1}};//上下左右四个方向
    vector<int> result(hits.size(),0);
    for(int i=int(hits.size())-1;i>=0;i--)//逆序遍历
    {
        int index_i=hits[i][0];
        int index_j=hits[i][1];
        if(grid[index_i][index_j]==0)
            continue;
        int beforeSize=size[findf(f, markNode)];//添加砖块之前与屋顶相连的砖块的个数
        if(index_i==0)
            merge(f, size, index_i*m+index_j,markNode);//与屋顶相连
        for(const auto &d:directions)
        {
            int ni=index_i+d.first;
            int nj=index_j+d.second;
            if(ni>=0&&ni<n&&nj>=0&&nj<m&&data[ni][nj])
            {
                merge(f, size, index_i*m+index_j,ni*m+nj);
            }
        }
        int afterSize=size[findf(f, markNode)];//添加砖块之后与屋顶相连的砖块的个数
        result[i]=max(0,afterSize-beforeSize-1);
        data[index_i][index_j]=1;
    }
    return result;
}


int main(int argc, const char * argv[]) {
    vector<vector<int>> grips={{1,0,0,0},{1,1,0,0}};
    vector<vector<int>> hits={{1,1},{1,0}};
    hitBricks(grips, hits);
    return 0;
}
