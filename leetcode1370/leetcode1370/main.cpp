//
//  main.cpp
//  leetcode1370
//
//  Created by ly on 2020/11/25.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


string sortString(string s) {
    if(s.empty())
        return "";
    string result="";
    int l=int(s.length());
    vector<int> mark(26,0);
    for(int i=0;i<l;i++)
    {
        mark[s[i]-'a']++;
    }
    while (result.length()<l)
    {
        for(int i=0;i<26;i++)
        {
            if(mark[i])
            {
                result+='a'+i;
                mark[i]--;
            }
        }
        for(int i=25;i>=0;i--)
        {
            if(mark[i])
            {
                result+='a'+i;
                mark[i]--;
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    cout<<sortString("aaaabbbbcccc")<<endl;
    return 0;
}
