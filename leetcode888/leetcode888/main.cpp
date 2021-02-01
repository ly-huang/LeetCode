//
//  main.cpp
//  leetcode888
//
//  Created by ly on 2021/2/1.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum1=0;
        int sum2=0;
        unordered_set<int> s(B.begin(),B.end());
        for(const auto &i:A)
        {
            sum1+=i;
        }
        for(const auto &i:B)
        {
            sum2+=i;
        }
        int dif=(sum1-sum2)/2;
        vector<int> result(2);
        for(const auto &i:A)
        {
            if(s.find(i-dif)!=s.end())
            {
                result[0]=i;
                result[1]=i-dif;
                break;
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
