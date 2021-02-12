//
//  main.cpp
//  leetcode119
//
//  Created by ly on 2021/2/12.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1,1);
        for(int i=2;i<=rowIndex;++i)
        {
            for(int j=i-1;j>0;--j)
            {
                result[j]=result[j-1]+result[j];
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
