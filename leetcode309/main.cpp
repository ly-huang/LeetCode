#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int>& prices) {
    if(prices.size()<2)
        return 0;
    int dp[3];
    dp[0]=-prices[0];
    dp[1]=0;
    dp[2]=0;
    int temp0,temp1;
    for(int i=1;i<prices.size();i++)
    {
        temp0=(dp[0]>dp[2]-prices[i]?dp[0]:dp[2]-prices[i]);
        temp1=dp[0]+prices[i];
        dp[2]=(dp[1]>dp[2]?dp[1]:dp[2]);
        dp[0]=temp0;
        dp[1]=temp1;
    }
    if(dp[0]>dp[1])
    {
        if(dp[0]>dp[2])
            return dp[0];
        return dp[2];
    }
    if(dp[1]>dp[2])
        return dp[1];
    return dp[2];
}
int main() {
    vector<int> prices={1,4,2};
    cout<<maxProfit(prices)<<endl;
    return 0;
}
