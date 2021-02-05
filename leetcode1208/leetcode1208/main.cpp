//
//  main.cpp
//  leetcode1208
//
//  Created by ly on 2021/2/5.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left=0;
        int right=0;
        int l=int(s.length());
        while(right<l)
        {
            maxCost-=abs(s[right]-t[right]);
            if(maxCost<0)
            {
                maxCost+=abs(s[left]-t[left]);
                ++left;
            }
            ++right;
        }
        return right-left;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
