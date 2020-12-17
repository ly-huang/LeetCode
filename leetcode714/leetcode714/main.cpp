//
//  main.cpp
//  leetcode714
//
//  Created by ly on 2020/12/17.
//

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    if(prices.empty())
        return 0;
    int n=int(prices.size());
    int on=-prices[0];
    int off=0;
    int temp;
    for(int i=1;i<n;i++)
    {
        temp=on;
        on=max(on,off-prices[i]);
        off=max(off,temp+prices[i]-fee);
    }
    return max(off,on);
}

int main(int argc, const char * argv[]) {
    vector<int> price={1, 3, 2, 8, 4, 9};
    cout<<maxProfit(price, 2)<<endl;
    return 0;
}
