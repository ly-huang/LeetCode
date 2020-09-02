//
//  main.cpp
//  leetcodeOffer20
//
//  Created by ly on 2020/9/2.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

bool isNumber(string s) {
    if(s=="")
        return false;
    bool e=false,point=false;//是否已经含有e和小数点
    int i=0;
    int n=s.length();
    while(i<n&&s[i]==' ') //去除开头的空格
        i++;
    if(i==n)
        return false;
    if(s[i]=='+'||s[i]=='-')
    {
        if(i+1==n||s[i+1]==' ')//正负号后不能为空，也不能接空格（可以考虑成空格代表结束）
            return false;
        i++;
    }
    if(s[i]=='.')//小数点可以用作开头，但是用在开头时后面不能为空，同理也不能接空格
    {
        if(i+1==n||s[i+1]==' ')
            return false;
        i++;
        point=true;
    }
    while(i<n)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            int j=i;
            while(j+1<n&&s[j+1]==' ')//如果数字后面是空格，则空格必须一直到字符串结尾
                j++;
            if(j+1==n)
                return true;
            if(i==j)
                i++;
            else
                return false;
            if(s[i]=='.')//数后面是小数点
            {
                if((!point)&&(!e))//小数点不能已经存在，并且小数点不能在e后面
                {
                    int j=i;
                    while(j+1<n&&s[j+1]==' ')//如果小数点后面是空格，则空格必须到字符串结尾
                        j++;
                    if(j+1==n)
                        return true;
                    if(i==j)
                        i++;
                    else
                        return false;
                    if((s[i]>='0'&&s[i]<='9')||s[i]=='e'||s[i]=='E')//小数点后面可以接数字和e
                        point=true;
                    else
                        return false;
                }
                else
                    return false;
            }
            if(s[i]=='e'||s[i]=='E')//数或者小数点后面是e
            {
                if(!e)//e不能已经存在
                {

                    if(i+1==n||s[i+1]==' ')//e后面不能为空，同理不能接空格
                        return false;
                    i++;
                    if(s[i]=='+'||s[i]=='-')//e后面接符号
                    {
                        if(i+1==n||s[i+1]==' ')//符号后面不能为空，同理不能接空格
                            return false;
                        i++;
                    }
                    if(s[i]<'0'||s[i]>'9')
                        return false;
                    e=true;
                }
            }
        }
        else
            return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    cout<<isNumber("46.e3")<<endl;
    return 0;
}
