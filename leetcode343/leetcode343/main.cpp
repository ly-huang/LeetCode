//
//  main.cpp
//  leetcode343
//
//  Created by ly on 2020/7/30.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


//使分得的数尽量平均
//int integerBreak(int n) {
//    if(n<2)
//        return 0;
//    int result=0;
//    for(int i=2;i<=n;i++)
//    {
//        vector<int> data(i);
//        for(int j=0;j<i-1;j++)
//            data[j]=n/i;
//        data[i-1]=n-(n/i)*(i-1);
//        for(int j=0;data[i-1]-data[j]>1;j++)
//        {
//            data[j]++;
//            data[i-1]--;
//        }
//        int temp=1;
//        for(int j=0;j<i;j++)
//            temp*=data[j];
//        if(result<temp)
//            result=temp;
//        else
//            break;
//    }
//    return result;
//}

//dp（可以只考虑j=2和j=3的情况）
int integerBreak(int n)
{
    if(n<2)
        return 0;
    vector<int> dp(n+1);
    dp[0]=dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        int result=0;
        for(int j=1;j<i;j++)
        {
            int temp=j*(i-j);
            if(temp<(j*dp[i-j]))
                temp=j*dp[i-j];
            if(result<temp)
                result=temp;
        }
        dp[i]=result;
    }
    return dp[n];
}
int main(int argc, const char * argv[]) {
    cout<<integerBreak(15)<<endl;
    return 0;
}
