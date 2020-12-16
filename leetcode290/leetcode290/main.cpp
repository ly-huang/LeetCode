//
//  main.cpp
//  leetcode290
//
//  Created by ly on 2020/12/16.
//

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool wordPattern(string pattern, string s) {
    unordered_map<char, string> m;
    string temp;
    int index=0;
    int n=int(s.length());
    for(const auto& c:pattern)
    {
        temp="";
        while(index<n&&s[index]!=' ')
            temp+=s[index++];
        index++;
        if(m.find(c)!=m.end())
        {
            if(temp!=m[c])
                return false;
        }
        else
        {
            for(const auto &p:m)
            {
                if(temp==p.second)
                    return false;
            }
            m[c]=temp;
        }
    }
    if(index==n+1)
        return true;
    return false;
}

int main(int argc, const char * argv[]) {
    cout<<wordPattern("abba", "dog dog dog dog")<<endl;
    return 0;
}
