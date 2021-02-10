//
//  main.cpp
//  leetcode567
//
//  Created by ly on 2021/2/10.
//

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=int(s1.length());
        int n2=int(s2.length());
        if(n1>n2)
            return false;
        unordered_map<char, int> data;
        for(const auto &c:s1)
        {
            ++data[c];
        }
        int left=0;
        int right=0;
        while(right<n2)
        {
            if(0==data[s2[right]])
            {
                while(s2[left]!=s2[right])
                {
                    ++data[s2[left++]];
                    ++n1;
                }
                if(left==right)
                {
                    left=++right;
                }
                else
                {
                    ++data[s2[left++]];
                    ++n1;
                }
            }
            else
            {
                --data[s2[right]];
                --n1;
                if(0==n1)
                    return true;
                ++right;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    cout<<Solution().checkInclusion("ab", "eidboaoo")<<endl;
    return 0;
}
