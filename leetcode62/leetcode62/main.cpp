//
//  main.cpp
//  leetcode62
//
//  Created by ly on 2020/12/9.
//

#include <iostream>
using namespace std;

int uniquePaths(int m, int n) {
    if(m==1||n==1)
        return 1;
    int sum=m+n-2;
    int t=min(m,n)-1;
    long result=1;
    for(int i=0;i<t;i++)
    {
        result=result*(sum-i)/(i+1);
    }
    return int(result);
}

int main(int argc, const char * argv[]) {
    cout<<uniquePaths(5, 5)<<endl;
    return 0;
}
