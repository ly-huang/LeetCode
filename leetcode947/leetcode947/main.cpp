//
//  main.cpp
//  leetcode947
//
//  Created by ly on 2021/1/15.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//void dfs(const vector<vector<int>> &stones, vector<bool>&mark,const int &n,int index,int &count)
//{
//    count++;
//    mark[index]=true;
//    for(int i=0;i<n;i++)
//    {
//        if((!mark[i])&&(stones[i][0]==stones[index][0]||stones[i][1]==stones[index][1]))
//            dfs(stones, mark, n, i,count);
//    }
//}
//
//int removeStones(vector<vector<int>>& stones) {
//    int n=int(stones.size());
//    if(n<2)
//        return 0;
//    vector<bool> mark(n,false);
//    int result=0;
//    int count=0;
//    for(int i=0;i<n;i++)
//    {
//        if(!mark[i])
//        {
//            count=0;
//            dfs(stones, mark, n, i,count);
//            result+=count-1;
//        }
//    }
//    return result;
//}


//并查集
class Solution {
public:
    int findf(unordered_map<int, int> &f,int x)
    {
        if(f.find(x)==f.end())
        {
            f[x]=x;
            result++;
        }
        if(f[x]!=x)
            f[x]=findf(f, f[x]);
        return f[x];
    }

    int removeStones(vector<vector<int>>& stones) {
        int n=int(stones.size());
        if(n<2)
            return 0;
        unordered_map<int, int> f;
        for(const auto &s:stones)
        {
            int fx=findf(f,~s[0]);
            int fy=findf(f, s[1]);
            if(fx!=fy)
            {
                f[fx]=fy;
                result--;
            }
        }
        result=n-result;
        return result;
    }
private:
    int result=0;
};



int main(int argc, const char * argv[]) {
    vector<vector<int>> stones={{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    cout<<removeStones(stones)<<endl;
    return 0;
}
