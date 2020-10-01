//
//  main.cpp
//  leetcodelcp19
//
//  Created by ly on 2020/10/1.
//

#include <iostream>
#include <string>
using namespace std;


int minimumOperations(string leaves) {
    int dp[3]={0,INT_MAX,INT_MAX};
    if(leaves[0]=='y')
        dp[0]=1;
    int n=int(leaves.length());
    int t0,t1,t2;
    t0=dp[0]+(leaves[1]!='r');
    t1=min(dp[0],dp[1])+(leaves[1]!='y');
    dp[0]=t0;
    dp[1]=t1;
    for(int i=2;i<n;i++)
    {
        t0=dp[0]+(leaves[i]!='r');
        t1=min(dp[0],dp[1])+(leaves[i]!='y');
        t2=min(dp[1],dp[2])+(leaves[i]!='r');
        dp[0]=t0;
        dp[1]=t1;
        dp[2]=t2;
    }
    return dp[2];
}
int main(int argc, const char * argv[]) {
    cout<<minimumOperations("ryr")<<endl;
    return 0;
}
