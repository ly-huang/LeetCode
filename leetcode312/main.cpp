#include <iostream>
#include <vector>
using namespace std;

//动态规划
//int maxCoins(vector<int>& nums) {
//    if(nums.empty())
//        return 0;
//    const int n=nums.size();
//    vector<int> data(n+2);
//    for(int i=1;i<n+1;i++)
//        data[i]=nums[i-1];
//    data[0]=1;
//    data[n+1]=1;
//    int dp[n+2][n+2];
//    for(int i=0;i<n+2;i++)
//    {
//        for(int j=0;j<n+2;j++)
//            dp[i][j]=0;
//    }
//    for(int i=n+1;i>=0;i--)
//    {
//        for(int j=i+2;j<n+2;j++)
//            for(int k=i+1;k<j;k++)
//            {
//                int sum=data[i]*data[k]*data[j];
//                sum+=dp[i][k]+dp[k][j];
//                if(dp[i][j]<sum)
//                    dp[i][j]=sum;
//            }
//    }
//    return dp[0][n+1];
//
//}


//带记忆的回溯

int fun(vector<int>&nums,vector<vector<int>>&mem,int i,int j)
{
    if(i>=j)
        return 0;
    if(mem[i][j]!=0)
        return mem[i][j];
    for(int k=i+1;k<j;k++)
    {
        int sum=nums[i]*nums[k]*nums[j];
        sum+=(fun(nums,mem,i,k)+fun(nums,mem,k,j));
        if(mem[i][j]<sum)
            mem[i][j]=sum;
    }
    return mem[i][j];

}

int maxCoins(vector<int>& nums) {
    if(nums.empty())
        return 0;
    const int n=nums.size();
    vector<int> data(n+2);
    for(int i=1;i<n+1;i++)
        data[i]=nums[i-1];
    data[0]=1;
    data[n+1]=1;
    vector<vector<int>> mem(n+2,vector<int>(n+2,0));
    return fun(data,mem,0,n+1);

}
int main() {
    vector<int> nums={3,1,5,8};
    cout<<maxCoins(nums)<<endl;
    return 0;
}
