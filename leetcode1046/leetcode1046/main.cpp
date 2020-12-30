//
//  main.cpp
//  leetcode1046
//
//  Created by ly on 2020/12/30.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int lastStoneWeight(vector<int>& stones) {
    if(stones.empty())
        return 0;
    priority_queue<int> max_heap;
    for(const auto &i : stones)
        max_heap.emplace(i);
    int x,y;
    while(max_heap.size()>1)
    {
        x=max_heap.top();
        max_heap.pop();
        y=max_heap.top();
        max_heap.pop();
        x=x-y;
        if(x!=0)
            max_heap.emplace(x);
    }
    if(max_heap.empty())
        return 0;
    return max_heap.top();
}

int main(int argc, const char * argv[]) {
    vector<int> stones={2,2};
    cout<<lastStoneWeight(stones)<<endl;
    return 0;
}
