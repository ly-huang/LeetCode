//
//  main.cpp
//  leetcode435
//
//  Created by ly on 2020/12/31.
//

#include <iostream>
#include <vector>
using namespace std;

void myQSort(vector<vector<int>> &data, int left,int right)
{
    if(left>=right)
        return;
    int i=left;
    int j=right;
    vector<int> temp;
    while(i<j)
    {
        while(j>i&&data[j][0]>data[left][0])
            j--;
        while(i<j&&data[i][0]<=data[left][0])
            i++;
        temp=data[i];
        data[i]=data[j];
        data[j]=temp;
    }
    temp=data[i];
    data[i]=data[left];
    data[left]=temp;
    myQSort(data, left, i-1);
    myQSort(data, i+1, right);
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if(intervals.empty())
        return 0;
    int n=int(intervals.size());
    
    sort(intervals.begin(),intervals.end(),[](const auto &u,const auto &v){return u[0]<v[0];});
    vector<int> dp(n,1);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(intervals[j][1]<=intervals[i][0])
                dp[i]=max(dp[j]+1,dp[i]);
        }
    }
    return n-*max_element(dp.begin(), dp.end());
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> intervals={{1,2}, {2,3}, {3,4}, {1,3}};
    cout<<eraseOverlapIntervals(intervals)<<endl;
    return 0;
}
