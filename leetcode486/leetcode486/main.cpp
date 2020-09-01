//
//  main.cpp
//  leetcode486
//
//  Created by ly on 2020/9/1.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

//递归解法
//int getScore(vector<int>& nums,int i,int j,int player1)
//{
//
//    if(i==j)
//        return player1*nums[i];
//    int left=nums[i]*player1+getScore(nums, i+1, j, player1*-1);  //取左端
//    int right=nums[j]*player1+getScore(nums, i, j-1, player1*-1); //取右端
//    return left*player1>=right*player1?left:right;                //玩家1保证score越大越好，玩家2保证score越小越好
//}
//
//bool PredictTheWinner(vector<int>& nums) {
//    if(nums.empty())
//        return false;
//    int score=getScore(nums, 0, nums.size()-1, 1);
//    return score>=0;
//}

//动态规划
bool PredictTheWinner(vector<int>& nums) {
    if(nums.empty())
        return false;
    int n=nums.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=n-1;i>=0;i--)
    {
        dp[i][i]=nums[i];
        for(int j=i+1;j<n;j++)
        {
            dp[i][j]=max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1]);
        }
    }
    return dp[0][n-1]>=0;
}
int main(int argc, const char * argv[]) {
    vector<int> nums={1,5,2};
    cout<<PredictTheWinner(nums)<<endl;
    return 0;
}
