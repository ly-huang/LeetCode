//
//  main.cpp
//  LeetCode84
//
//  Created by ly on 2020/12/26.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    if(heights.empty())
        return 0;
    int n=int(heights.size());
    stack<int> s;
    s.emplace(-1);
    int result=0;
    int h=-1;
    for(int i=0;i<n;i++)
    {
        while(heights[i]<=h)
        {
            s.pop();
            result=max(result,(i-s.top()-1)*h);
            if(s.size()==1)
                break;
            h=heights[s.top()];
        }
        s.emplace(i);
        h=heights[s.top()];

    }
    while(s.size()>1)
    {
        h=heights[s.top()];
        s.pop();
        result=max(result,(n-s.top()-1)*h);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> heights={2,1,5,6,2,3};
    cout<<largestRectangleArea(heights)<<endl;
    return 0;
}
