//
//  main.cpp
//  leetcode1423
//
//  Created by 黄创 on 2021/2/6.
//

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=int(cardPoints.size());
        int sum=0;
        for(int i=0;i<k;++i)
        {
            sum+=cardPoints[i];
        }
        int temp=sum;
        for(int i=1;i<=k;++i)
        {
            temp=temp-cardPoints[k-i]+cardPoints[n-i];
            if(temp>sum)
                sum=temp;
        }
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> carPoints({1,2,3,4,5,6,1});
    cout<<Solution().maxScore(carPoints, 3)<<endl;
    return 0;
}
