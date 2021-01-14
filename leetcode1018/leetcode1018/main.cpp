//
//  main.cpp
//  leetcode1018
//
//  Created by ly on 2021/1/14.
//

#include <iostream>
#include <vector>
using namespace std;

vector<bool> prefixesDivBy5(vector<int>& A) {
    int n=int(A.size());
    int data=0;
    vector<bool> result(n,false);
    for(int i=0;i<n;i++)
    {
        data=(data*2+A[i])%5;
        if(data==0)
            result[i]=true;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
