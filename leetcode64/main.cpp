#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    if(grid.empty()||grid[0].empty())
        return 0;
    int n=grid[0].size();
    int *dp=new int[n];
    dp[0]=grid[0][0];
    for(int i=1;i<n;i++)
        dp[i]=dp[i-1]+grid[0][i];
    for(int i=1;i<grid.size();i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j==0)
            {
                dp[j]=dp[j]+grid[i][j];
            } else
            {
                dp[j]=(dp[j-1]<dp[j]?dp[j-1]:dp[j])+grid[i][j];
            }
        }
    }
    int result=dp[n-1];
    delete []dp;
    return result;
}
int main() {
    vector<vector<int>> grid={{1,3,1},{1,5,1},{4,2,1}};
    cout<<minPathSum(grid)<<endl;
    return 0;
}
