//
//  main.cpp
//  leetcode424
//
//  Created by ly on 2021/2/2.
//

#include <iostream>
#include <string>
#include <array>
using namespace std;


class Solution {
public:
    int characterReplacement(string s, int k) {
        array<int, 26> num;
        for(int i=0;i<26;++i)
        {
            num[i]=0;
        }
        int left=0;
        int n=int(s.length());
        int maxNum=0;
        for(int i=0;i<n;++i)
        {
            ++num[s[i]-'A'];
            maxNum=max(maxNum,num[s[i]-'A']);
            if(i-left+1-maxNum>k)
            {
                --num[s[left]-'A'];
                ++left;
            }
        }
        return n-left;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
