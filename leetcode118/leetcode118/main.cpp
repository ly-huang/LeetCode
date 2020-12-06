//
//  main.cpp
//  leetcode118
//
//  Created by ly on 2020/12/6.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    if(numRows<=0)
        return {};
    vector<vector<int>> result={{1}};
    for(int i=1;i<numRows;i++)
    {
        vector<int> temp(i+1,1);
        for(int j=1;j<i;j++)
        {
            temp[j]=result[i-1][j-1]+result[i-1][j];
        }
        result.emplace_back(temp);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
