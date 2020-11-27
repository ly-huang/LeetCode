//
//  main.cpp
//  leetcode454
//
//  Created by ly on 2020/11/27.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using  namespace std;


int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
{
    unordered_map<int, int> data;
    int result=0;
    for(auto i:A)
        for(auto j:B)
            data[i+j]++;
    for(auto i:C)
        for(auto j:D)
            result+=data[-i-j];
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
