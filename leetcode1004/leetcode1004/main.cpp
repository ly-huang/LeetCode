//
//  main.cpp
//  leetcode1004
//
//  Created by ly on 2021/2/19.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left=0;
        int right=0;
        int n=int(A.size());
        while(right<n)
        {
            if(0==A[right])
            {
                --K;
            }
            if(K<0)
            {
                if(0==A[left])
                {
                    ++K;
                }
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
