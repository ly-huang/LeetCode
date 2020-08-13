//
//  main.cpp
//  leetcode43
//
//  Created by ly on 2020/8/13.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string addString(string num1,string num2)
{
    int add=0;
    int i=num1.length()-1;
    int j=num2.length()-1;
    string result="";
    for(;i>=0&&j>=0;i--,j--)
    {
        int temp=(num1[i]-'0')+(num2[j]-'0')+add;
        add=temp/10;
        result+=(temp%10+'0');
    }
    for(;i>=0;i--)
    {
        int temp=(num1[i]-'0')+add;
        add=temp/10;
        result+=(temp%10+'0');
    }
    for(;j>=0;j--)
    {
        int temp=(num2[j]-'0')+add;
        add=temp/10;
        result+=(temp%10+'0');
    }
    if(add!=0)
        result+=(add+'0');
    reverse(result.begin(),result.end());
    return result;
}

string multiply(string num1, string num2) {
    if(num1==""||num2=="")
        return "";
    if(num1=="0"||num2=="0")
        return "0";
    string longNum=num1.length()>num2.length()?num1:num2;
    string shortNum=num1.length()<=num2.length()?num1:num2;
    string result="0";
    for(int i=shortNum.length()-1;i>=0;i--)
    {
        string num="";
        for(int t=0;t<shortNum.length()-1-i;t++)
            num+='0';
        int add=0;
        for(int j=longNum.length()-1;j>=0;j--)
        {
            int temp=(shortNum[i]-'0')*(longNum[j]-'0')+add;
            num+=(temp%10+'0');
            add=temp/10;
        }
        if(add!=0)
            num+=(add+'0');
        reverse(num.begin(), num.end());
        result=addString(result,num);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    cout<<multiply("123", "456")<<endl;
    return 0;
}
