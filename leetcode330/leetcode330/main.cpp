//
//  main.cpp
//  leetcode330
//
//  Created by ly on 2020/12/29.
//

#include <iostream>
#include <vector>
using namespace std;

int minPatches(vector<int>& nums, int n) {
    int patches = 0;
    long long x = 1;
    int length = int(nums.size()), index = 0;
    while (x <= n) {
        if (index < length && nums[index] <= x) {
            x += nums[index];
            index++;
        } else {
            x <<= 1;
            patches++;
        }
    }
    return patches;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
