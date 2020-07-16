#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n=obstacleGrid.size();
    if(n==0)
        return 0;
    int m=obstacleGrid[0].size();
    if(m==0)
        return 0;
    if(obstacleGrid[n-1][m-1]==1||obstacleGrid[0][0]==1)
        return 0;
    int *mark=new int[m];
    for(int i=0;i<m;i++)
        mark[i]=0;
    mark[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(obstacleGrid[i][j]==1)
                mark[j]=0;
            else
            {
                int temp=0;
                if(j>0)
                    temp+=mark[j-1];
                temp+=mark[j];
                mark[j]=temp;
            }
        }
    }
    int result=mark[m-1];
    delete []mark;
    return result;

}

int main() {
    vector<vector<int>> data={{0,0,0},{0,1,0},{0,0,0}};
    cout<<uniquePathsWithObstacles(data)<<endl;
    return 0;
}
