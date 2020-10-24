//
//  main.cpp
//  leetcode1024
//
//  Created by ly on 2020/10/24.
//

#include <iostream>
#include <vector>
using namespace std;

int videoStitching(vector<vector<int>>& clips, int T) {
    vector<int> maxn(T);
    int last=0,pre=0,result=0;
    for(const auto &i:clips)
    {
        if(i[0]<T)
            maxn[i[0]]=max(maxn[i[0]],i[1]);
    }
    for(int i=0;i<T;i++)
    {
        last=max(maxn[i],last);
        if(i==last)
            return -1;
        if(i==pre)
        {
            result++;
            pre=last;
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> clips={{0,1},{6,8},{0,2},{5,6},{0,4},{0,3},{6,7},{1,3},{4,7},{1,4},{2,5},{2,6},{3,4},{4,5},{5,7},{6,9}};
    cout<<videoStitching(clips, 9)<<endl;
    return 0;
}
