//
//  main.cpp
//  leetcode995
//
//  Created by ly on 2021/2/18.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n=int(A.size());
        int result=0;
        int mark=0;
        for(int i=0;i<n;++i)
        {
            if(i>=K&&A[i-K]>1)
            {
                mark^=1;
                A[i-K]-=2;
            }
            if(mark==A[i])
            {
                if(i+K>n)
                    return -1;
                ++result;
                mark^=1;
                A[i]+=2;
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
