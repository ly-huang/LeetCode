//
//  main.cpp
//  leetcode459
//
//  Created by ly on 2020/8/24.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

////使用遍历的方法
//bool check(const string &s,const int &n,const int &index)
//{
//    for(int i=1,t=n/index;i<t;i++)
//    {
//        for(int j=0;j<index;j++)
//        {
//            if(s[j]!=s[index*i+j])
//            {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//bool repeatedSubstringPattern(string s) {
//    if(s=="")
//        return false;
//    int index=1;
//    int n=s.length();
//    while(index<=n/2)
//    {
//        while(s[index]!=s[0]||(n%index!=0))
//        {
//            index++;
//            if(index>n/2)
//                return false;
//        }
//       if(check(s, n, index))
//           return true;
//        else
//            index++;
//    }
//    return false;
//}

//-------------------------------------------------
////KMP算法
//int KMP(const string& text,const string& pat)
//{
//    if(pat=="")
//        return -1;
//    int n=pat.length();
//    vector<int> next(n,0);
//    next[0]=-1;
//    for(int i=2;i<n;i++)//计算next数组的值
//    {
//        for(int j=i-1;j>0;j=next[j])
//        {
//            if(pat[i-1]==pat[next[j]])
//            {
//                next[i]=next[j]+1;
//                break;
//            }
//        }
//    }
//
//    //进行字符串的匹配
//    int m=text.length();
//    int index=0,i=0;
//    while(i<m)
//    {
//        if(pat[index]==text[i])
//        {
//            i++;
//            index++;
//            if(index==n)
//                return i-index;
//        }
//        else if(index==0)
//            i++;
//        else
//            index=next[index];
//    }
//    return -1;
//}
//
//bool repeatedSubstringPattern(string s)
//{
//    if(s=="")
//        return false;
//    string ss=s+s;
//    ss.erase(ss.begin());
//    int index=KMP(ss, s);
//    return index!=-1&&index!=s.length()-1;
//}

bool repeatedSubstringPattern(string s)
{
    if(s=="")
        return false;
    int n=s.length();
       vector<int> next(n,-1);
       for(int i=1;i<n;i++)
       {
           for(int j=i-1;j!=-1;j=next[j])
           {
               if(s[i]==s[next[j]+1])
               {
                   next[i]=next[j]+1;
                   break;
               }
           }
       }
    return next[n - 1] != -1 && n % (n - next[n - 1] - 1) == 0;
}

int main(int argc, const char * argv[]) {
    cout<<repeatedSubstringPattern("bb")<<endl;
    return 0;
}
