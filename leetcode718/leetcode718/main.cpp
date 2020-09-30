//
//  main.cpp
//  leetcode718
//
//  Created by ly on 2020/9/30.
//

#include <iostream>
#include <vector>
using namespace std;

int findLength(vector<int>& A, vector<int>& B) {
    int n_A=int(A.size());
    int n_B=int(B.size());
    vector<int> dp(n_A,0);
    int result=0;
    for(int i=n_B-1;i>=0;i--)
    {
        for(int j=0;j<n_A-1;j++)
        {
            if(A[j]==B[i])
            {
                dp[j]=1+dp[j+1];
                if(dp[j]>result)
                    result=dp[j];
            }
            else
                dp[j]=0;
        }
        if(A[n_A-1]==B[i])
            dp[n_A-1]=1;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> A={1,2,3,2,3,1,4};
    vector<int> B={3,2,1,4,7};
    cout<<findLength(A, B)<<endl;
    return 0;
}
