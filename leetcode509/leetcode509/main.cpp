//
//  main.cpp
//  leetcode509
//
//  Created by ly on 2021/1/4.
//

#include <iostream>
using namespace std;

int fib(int n) {
    if(n<=0)
        return 0;
    int num1=0;
    int num2=1;
    int result=1;
    for(int i=1;i<n;i++)
    {
        result=num1+num2;
        num1=num2;
        num2=result;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    for(int i=1;i<30;i++)
        cout<<fib(i)<<endl;
    return 0;
}
