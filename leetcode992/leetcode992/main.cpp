//
//  main.cpp
//  leetcode992
//
//  Created by ly on 2021/2/9.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int left=0;
        int right=0;
        int end;
        unordered_map<int, int> data;
        int n=int(A.size());
        int result=0;
        ++data[A[0]];
        --K;
        while(true)
        {
            if(0==K)
            {
                end=right+1;
                while(end<n&&data[A[end]]!=0)++end;
                result+=end-right;
                if(--data[A[left]]==0)
                    ++K;
                ++left;
            }
            else
            {
                if(++right==n)
                    break;
                if(++data[A[right]]==1)
                    --K;
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
