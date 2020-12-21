//
//  main.cpp
//  leetcode746
//
//  Created by ly on 2020/12/21.
//

#include <iostream>
#include <vector>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    if(cost.empty())
        return 0;
    int on=0;
    int off=0;
    int t=0;
    for(const auto & i: cost)
    {
        t=on;
        on=min(on,off)+i;
        off=t;
    }
    return min(on,off);
}

int main(int argc, const char * argv[]) {
    vector<int> cost={10, 15, 20};
    cout<<minCostClimbingStairs(cost)<<endl;
    return 0;
}
