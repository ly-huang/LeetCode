//
//  main.cpp
//  leetcode738
//
//  Created by ly on 2020/12/15.
//

#include <iostream>
#include <vector>
using namespace std;


int monotoneIncreasingDigits(int N) {
    vector<int> data;
    int n=N;
    while(n!=0)
    {
        data.emplace_back(n%10);
        n=n/10;
    }
    n=int(data.size());
    int i=n-2;
    while(i>=0&&data[i]>=data[i+1])
        i--;
    if(i==-1)
        return N;
    while(i<n-1&&data[i]<data[i+1])
        data[++i]--;
    for(int j=0;j<i;j++)
    {
        data[j]=9;
    }
    int result=0;
    for(int i=n-1;i>=0;i--)
    {
        result=result*10+data[i];
    }
    return result;
}

int main(int argc, const char * argv[]) {
    cout<<monotoneIncreasingDigits(332)<<endl;
    return 0;
}
