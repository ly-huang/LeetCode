//
//  main.cpp
//  leetcode123
//
//  Created by ly on 2021/1/9.
//

#include <iostream>
#include <vector>
using namespace std;


int maxProfit(vector<int>& prices) {
     if(prices.empty())
         return 0;
    int on[3]={INT_MIN/2,INT_MIN/2,INT_MIN/2};
    int off[3]={INT_MIN/2,INT_MIN/2,INT_MIN/2};
    on[0]=-prices[0];
    off[0]=0;
    int n=int(prices.size());
    int temp;
    int last;
    for(int i=1;i<n;i++)
    {
        last=0;
        for(int j=0;j<=i/2+1&&j<3;j++)
        {
            temp=on[j];
            on[j]=max(on[j],off[j]-prices[i]);
            if(j>0)
                off[j]=max(off[j],last+prices[i]);
            last=temp;
        }
    }
    return *max_element(off, off+3);
}

int main(int argc, const char * argv[]) {
    vector<int> prices={1,2};
    cout<<maxProfit(prices)<<endl;
    return 0;
}
