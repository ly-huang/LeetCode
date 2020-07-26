#include <iostream>
#include <vector>
using namespace std;

int fun(vector<vector<int>>& matrix,int **dp,int n,int m,int i,int j)
{
    if(dp[i][j]!=0)
        return dp[i][j];
    int next[4];

    if(i==0||matrix[i][j]>=matrix[i-1][j])
        next[0]=0;
    else
        next[0]=fun(matrix,dp,n,m,i-1,j);
    if(i==n-1||matrix[i][j]>=matrix[i+1][j])
        next[1]=0;
    else
        next[1]=fun(matrix,dp,n,m,i+1,j);
    if(j==0||matrix[i][j]>=matrix[i][j-1])
        next[2]=0;
    else
        next[2]=fun(matrix,dp,n,m,i,j-1);
    if(j==m-1||matrix[i][j]>=matrix[i][j+1])
        next[3]=0;
    else
        next[3]=fun(matrix,dp,n,m,i,j+1);
    int result=0;
    for(int i=0;i<4;i++)
    {
        if(next[i]>result)
            result=next[i];
    }
    dp[i][j]=result+1;
    return dp[i][j];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    if(matrix.empty()||matrix[0].empty())
        return 0;
    int n=matrix.size();
    int m=matrix[0].size();
    int **dp=new int*[n];
    for(int i=0;i<n;i++)
        dp[i]=new int [m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            dp[i][j]=0;
    }
    for(int i=0;i<n;i++)
    {

        for(int j=0;j<m;j++)
        {
            fun(matrix,dp,n,m,i,j);
        }
    }

    int result=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(result<dp[i][j])
                result=dp[i][j];
        }
    }
    for(int i=0;i>m;i++)
        delete []dp[i];
    delete []dp;
    return result;

}
int main() {
    vector<vector<int>> matrix={{9,9,4},{6,6,8},{2,1,1}};
    cout<<longestIncreasingPath(matrix)<<endl;
    return 0;
}
