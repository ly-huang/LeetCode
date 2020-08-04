//
//  main.cpp
//  leetcode207
//
//  Created by ly on 2020/8/4.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    if(numCourses<=0||prerequisites.empty())
        return true;
    vector<vector<int>> line(numCourses);
    for(int i=0;i<prerequisites.size();i++)
    {
        line[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    vector<bool> dp(numCourses,false);
    for(int i=0;i<numCourses;i++)
    {
        if(dp[i])
            continue;
        stack<int> node;
        stack<int> level;
        node.push(i);
        level.push(0);
        dp[i]=true;
        while(!node.empty())
        {
            int l=level.top();
            if(l>=numCourses)
                return false;
            int j=node.top();
            node.pop();
            level.pop();
            for(auto item :line[j])
            {
                node.push(item);
                level.push(l+1);
                dp[item]=true;
            }
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    int numCourses=4;
    vector<vector<int>> prerequisites={{0,1},{3,1},{1,3},{3,2}};
    cout<<canFinish(numCourses, prerequisites)<<endl;
    return 0;
}
