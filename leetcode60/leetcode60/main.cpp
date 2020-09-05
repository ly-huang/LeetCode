//
//  main.cpp
//  leetcode60
//
//  Created by ly on 2020/9/5.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

string getPermutation(int n, int k) {
    if(n<=0||k<=0)
        return "";
    int factorial=1;
    for(int i=1;i<=n;i++)
        factorial*=i;
    if(k>factorial)
        return "";
    int currentF=factorial;
    vector<int> index(n,-1);//存储每个数字在第几位（从高到低数）
    int t=0;
    for(int i=0;i<n;i++)
    {
        if(k==0)//高位的数字以确定，地位的数字从左到右依次减小
        {
            for(int j=n-1;j>=0;j--)
            {
                if(index[j]==-1)
                {
                    index[j]=i;
                    break;
                }
            }
            
        }
        else
        {
            currentF=currentF/(n-i);
            t=k/currentF;
            k=k%currentF;
            if(k!=0||t==0)//t应该从1开始，如果有余数，需要进位
                t++;
            for(int j=0;j<n;j++)
            {
                if(index[j]==-1)
                    t--;
                if(t==0)
                {
                    index[j]=i;
                    break;
                }
            }
        }
    }
    int result=0;
    for(int i=0;i<n;i++)
        result+=((i+1)*pow(10,n-index[i]-1));
    return to_string(result);
}
int main(int argc, const char * argv[]) {
    cout<<getPermutation(4, 3)<<endl;
    return 0;
}
