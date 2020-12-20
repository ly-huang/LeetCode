//
//  main.cpp
//  leetcode316
//
//  Created by ly on 2020/12/20.
//

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;


string removeDuplicateLetters(string s) {
    vector<int> data(26,0);
    vector<bool> mark(26,false);
    for(const auto &c:s)
        data[c-'a']++;
    stack<char> ret;
    int temp;
    for(const auto &c:s)
    {
        if(mark[c-'a'])
        {
            data[c-'a']--;
            continue;
        }
        while(!ret.empty())
        {
            temp=ret.top();
            if(c<temp&&data[temp-'a']>0)
            {
                ret.pop();
                mark[temp-'a']=false;
            }
            else
                break;
        }
        data[c-'a']--;
        ret.emplace(c);
        mark[c-'a']=true;
    }
    string result="";
    while(!ret.empty())
    {
        result+=ret.top();
        ret.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main(int argc, const char * argv[]) {
    cout<<removeDuplicateLetters("bbcaac")<<endl;
    return 0;
}
