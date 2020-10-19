//
//  main.cpp
//  leetcode844
//
//  Created by ly on 2020/10/19.
//

#include <iostream>
#include <string>
using namespace std;

//bool backspaceCompare(string S, string T) {
//    for(int i=0;i<S.length();i++)
//    {
//        if(S[i]=='#')
//        {
//            if(i-1>=0)
//                S.erase(--i,1);
//            S.erase(i--,1);
//        }
//    }
//    for(int i=0;i<T.length();i++)
//    {
//        if(T[i]=='#')
//        {
//            if(i-1>=0)
//                T.erase(--i,1);
//            T.erase(i--,1);
//        }
//    }
//    return S==T;
//}

bool backspaceCompare(string S, string T) {
    int i=int(S.length())-1;
    int j=int(T.length())-1;
    int skip1=0;
    int skip2=0;
    while(true)
    {
        while(i>=0&&(S[i]=='#'||skip1>0))
        {
            if(S[i]=='#')
                skip1++;

            else
                skip1--;
            i--;
        }
        while(j>=0&&(T[j]=='#'||skip2>0))
        {
            if(T[j]=='#')
                skip2++;
            else
                skip2--;
            j--;
        }
        if(i>=0&&j>=0)
        {
            if(S[i--]!=T[j--])
                return false;
        }
        else if(i<0&&j<0)
            return true;
        else
            return false;
    }
}

int main(int argc, const char * argv[]) {
    cout<<backspaceCompare("nzp#o#g", "b#nzp#o#g")<<endl;
    return 0;
}
