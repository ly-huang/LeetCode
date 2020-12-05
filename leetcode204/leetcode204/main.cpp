//
//  main.cpp
//  leetcode204
//
//  Created by ly on 2020/12/4.
//

#include <iostream>
using namespace std;

int countPrimes(int n) {
    int result=0;
    bool valid=true;
    for(int i=2;i<n;i++)
    {
        valid=true;
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                valid=false;
                break;
            }
        }
        if(valid)
            result++;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    cout<<countPrimes(11)<<endl;
    return 0;
}
