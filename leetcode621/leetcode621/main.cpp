//
//  main.cpp
//  leetcode621
//
//  Created by ly on 2020/12/5.
//

#include <iostream>
#include <vector>
using namespace std;



int leastInterval(vector<char>& tasks, int n) {
    int m=int(tasks.size());
    int time=1;
    vector<int> data(26,0);
    for(auto i:tasks)
        data[i-'A']++;
    vector<pair<int, int>> queue;
    for(int i=0;i<26;i++)
    {
        if(data[i])
            queue.emplace_back(make_pair(data[i], 1));
    }
    int t=int(queue.size());
    queue.emplace_back(make_pair(0, 0));
    int index;
    int minTime;
    while(m>0)
    {
        index=t;
        minTime=INT_MAX;
        for(int i=0;i<t;i++)
        {
            if(queue[i].second<=time&&queue[i].first>queue[index].first)
                index=i;
            else if(queue[i].first>0&&queue[i].second<minTime)
                minTime=queue[i].second;
        }
        if(index==t)
            time=minTime;
        else
        {
            m--;
            queue[index].first--;
            queue[index].second+=n+1;
            time++;
        }
    }
    return --time;
    
}

int main(int argc, const char * argv[]) {
    vector<char> tasks={'A','A','A','B','B','B'};
    cout<<leastInterval(tasks, 2)<<endl;
    return 0;
}
