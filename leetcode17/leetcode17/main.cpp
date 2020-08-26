//
//  main.cpp
//  leetcode17
//
//  Created by ly on 2020/8/26.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void getString(const string& digits,const vector<string>&map,int i,string str,vector<string>& result)
{
    if(i==digits.length())
    {
        result.push_back(str);
        return;
    }
    if(digits[i]>='2'&&digits[i]<='9')
    {
        for(auto item:map[digits[i]-'2'])
            getString(digits, map, i+1, str+item, result);
    }
    return;
}

vector<string> letterCombinations(string digits) {
    if(digits=="")
        return {};
    vector<string> result;
    vector<string> map={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    getString(digits,map,0,"",result);
    return result;
}

int main(int argc, const char * argv[]) {
    auto result=letterCombinations("23");
    for(auto item:result)
        cout<<item<<endl;
    return 0;
}
