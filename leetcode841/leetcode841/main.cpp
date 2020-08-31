//
//  main.cpp
//  leetcode841
//
//  Created by ly on 2020/8/31.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    if(rooms.empty())
        return true;
    int n=rooms.size();
    vector<bool> enter(n,false);
    queue<int> key;
    int count=0;
    key.push(0);
    while(!key.empty())
    {
        int i=key.front();
        key.pop();
        if(enter[i])
            continue;
        for(auto item: rooms[i])
            key.push(item);
        enter[i]=true;
        count++;
        if(count==n)
            return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> rooms={{1,3},{3,0,1},{2},{0}};
    cout<<canVisitAllRooms(rooms)<<endl;
    return 0;
}
