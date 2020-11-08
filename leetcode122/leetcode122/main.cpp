//
//  main.cpp
//  leetcode122
//
//  Created by ly on 2020/11/8.
//

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    if(prices.empty())
        return 0;
    int on=-prices[0];
    int off=0;
    int n=int(prices.size());
    int temp;
    for(int i=1;i<n;i++)
    {
        temp=on;
        on=max(on,off-prices[i]);
        off=max(off,temp+prices[i]);
    }
    return max(on,off);
}

int main(int argc, const char * argv[]) {
    vector<int> prices={7,6,4,3,1};
    cout<<maxProfit(prices)<<endl;
    return 0;
}
