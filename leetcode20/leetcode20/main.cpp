//
//  main.cpp
//  leetcode20
//
//  Created by ly on 2020/8/14.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s) {
    if(s=="")
        return true;
    stack<char> left;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='('||s[i]=='['||s[i]=='{')
            left.push(s[i]);
        else if(s[i]==')')
        {
            if(left.empty()||left.top()!='(')
                return false;
            left.pop();
        }
        else if(s[i]==']')
        {
            if(left.empty()||left.top()!='[')
                return false;
            left.pop();
        }
        else if(s[i]=='}')
        {
            if(left.empty()||left.top()!='{')
                return false;
            left.pop();
        }
    }
    if(left.empty())
        return true;
    return false;
}

int main(int argc, const char * argv[]) {
    cout<<isValid("()[]{}")<<endl;
    return 0;
}
