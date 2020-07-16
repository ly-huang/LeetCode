#include <iostream>
#include <vector>
using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    if(dungeon.empty()||dungeon[0].empty())
        return 0;
    int n=dungeon.size();
    int m=dungeon[0].size();
    vector<int> dp(m);
    dp[m-1]=dungeon[n-1][m-1]<0?dungeon[n-1][m-1]:0;
    for(int i=m-2;i>=0;i--)
        dp[i]=dp[i+1]+dungeon[n-1][i]<0?dp[i+1]+dungeon[n-1][i]:0;
    for(int i=n-2;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(j==m-1)
            {
                dp[j]=dp[j]+dungeon[i][j];
            } else
            {
                dp[j]=(dp[j]>dp[j+1]?dp[j]:dp[j+1])+dungeon[i][j];
            }
            if(dp[j]>0)
                dp[j]=0;
        }
    }
    return dp[0]<0?-(dp[0]-1):1;
}
int main() {
    vector<vector<int>> dungeon={{1,-3,3},{0,-2,0},{-3,-3,-3}};
    cout<<calculateMinimumHP(dungeon)<<endl;
    return 0;
}
