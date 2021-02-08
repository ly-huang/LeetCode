//
//  main.cpp
//  leetcode978
//
//  Created by ly on 2021/2/8.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.empty())
            return 0;
        int left=0;
        int right=1;
        int n=int(arr.size());
        int result=0;
        bool mark=true;
        for(;right<n;++right)
        {
            if(mark)
            {
                if(arr[right]>arr[right-1])
                    mark=false;
                else
                {
                    if(right-left>result)
                        result=right-left;
                    if(arr[right]==arr[right-1])//相等不能记录到湍流数组中
                        left=right;
                    else
                        left=right-1;
                    
                }
            }
            else
            {
                if(arr[right]<arr[right-1])
                    mark=true;
                else
                {
                    if(right-left>result)
                        result=right-left;
                    if(arr[right]==arr[right-1])
                        left=right;
                    else
                        left=right-1;
                }
            }
        }
        if(right-left>result)
            result=right-left;
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
