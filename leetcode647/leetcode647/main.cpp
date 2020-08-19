//
//  main.cpp
//  leetcode647
//
//  Created by ly on 2020/8/19.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//int countSubstrings(string s) {
//    if(s=="")
//        return 0;
//    int len=s.length();
//    int result=len;
//    for(int i=0;i<len-1;i++)//回文串长度为偶数
//    {
//        if(s[i+1]==s[i])
//            result++;
//        else
//            continue;
//        for(int j=1;i+1+j<len&&i-j>=0;j++)
//        {
//            if(s[i-j]==s[i+1+j])
//                result++;
//            else
//                break;
//        }
//    }
//    for(int i=1;i<len-1;i++)//回文串长度为奇数
//    {
//        for(int j=1;i+j<len&&i-j>=0;j++)
//        {
//            if(s[i-j]==s[i+j])
//                result++;
//            else
//                break;
//        }
//    }
//    return result;
//}

//int countSubstrings(string s) {  //奇数和偶数统一
//    if(s=="")
//        return 0;
//    int len=s.length();
//    int result=0;
//    for(int i=0;i<(2*len-1);i++)
//    {
//        int l=i/2;
//        int r=i/2+i%2;
//        while(l>=0&&r<len&&s[l]==s[r])
//        {
//            result++;
//            l--;
//            r++;
//        }
//    }
//    return result;
//}


int countSubstrings(string s) {  //Manacher 算法
    if(s=="")
        return 0;
    int result=0;
    string newS="^";
    for(auto item:s)
    {
        newS+='#';
        newS+=item;
    }
    newS+="#$";
    int n=newS.length();
    auto p=vector<int>(n);
    int c=0,r=0;
    for(int i=1;i<n-1;i++)
    {
        p[i]=(i<=r?min(r-i+1,p[2*c-i]):1);
        while(newS[i+p[i]]==newS[i-p[i]])
            p[i]++;
        if(i+p[i]-1>r)
        {
            c=i;
            r=i+p[i]-1;
        }
        result += (p[i] / 2);
    }
    return result;
}



int main(int argc, const char * argv[]) {
    cout<<countSubstrings("aaa")<<endl;
    return 0;
}
