#include <iostream>
#include <vector>
using namespace std;



//动态规划,dp[i][j]表示前i个数分成j组的和的最大值
//int splitArray(vector<int>& nums, int m) {
//    if(nums.empty())
//        return 0;
//    int n=nums.size();
//    unsigned int **dp=new unsigned int* [n];
//    for(int i=0;i<n;i++)
//        dp[i]=new unsigned int[m];
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<m;j++)
//            dp[i][j]=0;
//    }
//    dp[0][0]=nums[0];
//    for(int i=1;i<n;i++)
//    {
//        int t=m-1<i?m-1:i;
//        for(;t>0;t--)
//        {
//            unsigned int sum=0;
//            for(int j=t-1;j<=i;j++)
//                sum+=nums[j];
//            for(int j=t-1;j<i;j++)
//            {
//                sum-=nums[j];
//                int temp=dp[j][t-1]>sum?dp[j][t-1]:sum;
//                if(dp[i][t]==0||dp[i][t]>temp)
//                    dp[i][t]=temp;
//            }
//        }
//        dp[i][t]=dp[i-1][0]+nums[i];
//    }
//
//    int result=dp[n-1][m-1];
//    for(int i=0;i<n;i++)
//        delete []dp[i];
//    delete []dp;
//    return result;
//}


//二分查找
int splitArray(vector<int>& nums, int m) {
    if(nums.empty())
        return 0;
    int n=nums.size();
    unsigned int low=0;
    unsigned int high=0;
    for(int i=0;i<n;i++)
    {
        high+=nums[i];
        if(nums[i]>low)
            low=nums[i];
    }
    unsigned int mid;
    while(low<high)
    {
        mid=low+((high-low)>>1);
        int count=0;
        unsigned int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum>=mid)
            {
                count++;
                if(sum==mid)
                    sum=0;
                else
                    sum=nums[i];
            }
        }
        if(sum>0)
            count++;
        if(count>m)
            low=mid+1;
        else
            high=mid;
    }
    return low;
}
int main() {
    vector<int> nums={10,5,13,4,8,4,5,11,14,9,16,10,20,8};
    cout<<splitArray(nums,8)<<endl;
    return 0;
}
