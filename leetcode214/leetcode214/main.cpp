//
//  main.cpp
//  leetcode214
//
//  Created by ly on 2020/8/29.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


string shortestPalindrome(string s) {
    if(s=="")
        return "";
    string str="!#";
    for(int i=0;i<s.length();i++)
    {
        str+=s[i];
        str+='#';
    }
    str+='$';
    int n=str.length();
    vector<int> f(n/2+1,0);
    int c=1,l=0;
    for(int i=1;i<=n/2;i++)
    {
        f[i]=f[2*c-i]+i<c+l?f[2*c-i]:c+l-i;
        while(i+f[i]+1<=n-1&&i-f[i]-1>=0&&str[i+f[i]+1]==str[i-f[i]-1])
            f[i]++;
        if(i+f[i]>c+l)
        {
            c=i;
            l=f[i];
        }
    }
    
    
    int index=1;
    for(int i=1;i<=n/2;i++)
    {
        if(i-f[i]==1)
            index=i;
    }
    string result="";
    index=index+f[index];
    for(int i=n-2;i>index;i--)
    {
        if(str[i]=='#')
            continue;
        result+=str[i];
    }
    return result+s;
}

int main(int argc, const char * argv[]) {
    cout<<shortestPalindrome("ababbbabbaba")<<endl;
    return 0;
}
