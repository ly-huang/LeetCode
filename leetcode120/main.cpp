#include <iostream>
#include <vector>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    if(triangle.empty()||triangle[0].empty())
        return 0;
    int n=triangle.size();
    vector<int> dp(n);
    dp[0]=triangle[0][0];
    for(int i=1;i<n;i++)
    {
        int m=triangle[i].size();
        int temp=dp[0];
        for(int j=0;j<m;j++)
        {
            if(j==0)
            {
                temp=dp[j];
                dp[j]=dp[j]+triangle[i][j];
            }
            else if(j==m-1)
            {
                int t=temp+triangle[i][j];
                temp=dp[j];
                dp[j]=t;
            }
            else
            {
                int t=(temp<dp[j]?temp:dp[j])+triangle[i][j];
                temp=dp[j];
                dp[j]=t;
            }
        }
    }
    int result=dp[0];
    for(int i=1;i<n;i++)
    {
        if(dp[i]<result)
            result=dp[i];
    }
    return result;

}
int main() {
    vector<vector<int>> triangle={
            {2},
            {3,4},
            {6,5,7},
            {4,1,8,3}};
    cout<<minimumTotal(triangle)<<endl;
    return 0;
}
