//
//  main.cpp
//  leetcode135
//
//  Created by ly on 2020/12/24.
//

#include <iostream>
#include <vector>
using namespace std;

int candy(vector<int>& ratings) {
    if(ratings.empty())
        return 0;
    int n=int(ratings.size());
    vector<int> counts(n,0);
    counts[0]=1;
    for(int i=1;i<n;i++)
    {
        if(ratings[i]>ratings[i-1])
            counts[i]=counts[i-1]+1;
        else
            counts[i]=1;
    }
    for(int i=n-2;i>=0;i--)
    {
        if(ratings[i]>ratings[i+1]&&counts[i]<=counts[i+1])
            counts[i]=counts[i+1]+1;
    }
    int result=0;
    for(const auto &i:counts)
        result+=i;
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> ratings={1,0,2};
    cout<<candy(ratings)<<endl;
    return 0;
}
