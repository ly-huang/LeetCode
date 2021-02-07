//
//  main.cpp
//  leetcode665
//
//  Created by ly on 2021/2/7.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool mark=true;
        int n=int(nums.size());
        for(int i=1;i<n;++i)
        {
            if(nums[i]<nums[i-1])
            {
                if(mark)
                {
                    if(i!=1&&nums[i]<nums[i-2])
                        nums[i]=nums[i-1];
                    mark=false;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
