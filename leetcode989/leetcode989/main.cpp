//
//  main.cpp
//  leetcode989
//
//  Created by ly on 2021/1/22.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> addToArrayForm(vector<int>& A, int K) {
    vector<int> result;
    int up=0;
    
    int sum=0;
    for(int i=int(A.size())-1;i>=0;K=K/10,i--)
    {
        sum=K%10+A[i]+up;
        result.emplace_back(sum%10);
        up=sum/10;
    }
    while(K!=0)
    {
        sum=K%10+up;
        result.emplace_back(sum%10);
        up=sum/10;
        K=K/10;
    }
    if(up!=0)
        result.emplace_back(up);
    reverse(result.begin(), result.end());
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> A={1,2,0,0};
    addToArrayForm(A, 34);
    return 0;
}
