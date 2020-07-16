#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool isBipartite(vector<vector<int>>& graph) {
    if(graph.empty())
        return false;
    vector<char> color(graph.size(),'0');
    queue<int> q;
    for(int i=0;i<graph.size();i++)
    {
        if(color[i]=='0')
        {
            color[i]='1';
            for(int j=0;j<graph[i].size();j++)
            {
                if(color[graph[i][j]]=='1')
                    return false;
                else if(color[graph[i][j]]=='0')
                {
                    color[graph[i][j]]='2';
                    q.push(graph[i][j]);
                }
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            if(color[node]=='1')
            {
                for(int j=0;j<graph[node].size();j++)
                {
                    if(color[graph[node][j]]=='1')
                        return false;
                    else if(color[graph[node][j]]=='0')
                    {
                        color[graph[node][j]]='2';
                        q.push(graph[node][j]);
                    }
                }
            } else{
                for(int j=0;j<graph[node].size();j++)
                {
                    if(color[graph[node][j]]=='2')
                        return false;
                    else if(color[graph[node][j]]=='0')
                    {
                        color[graph[node][j]]='1';
                        q.push(graph[node][j]);
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> graph={{},{10,44,62},{98},{59},{90},{},{31,59},{52,58},{},{53},{1,63},{51,71},{18,64},{24,26,45,95},{61,67,96},{},{40},{39,74,79},{12,21,72},{35,85},{86,88},{18,76},{71,80},{27,58,85},{13,26,87},{75,94},{13,24,68,77,82},{23},{56,96},{67},{56,73},{6},{41},{50,88,91,94},{},{19,72,92},{59},{49},{49,89},{17},{16},{32,84,86},{61,73,77},{94,98},{1,74},{13,57,90},{},{93},{},{37,38,54,68},{33},{11},{7,85},{9},{49},{61},{28,30,87,93},{45,69,77},{7,23,76},{3,6,36,62},{81},{14,42,55,62},{1,59,61},{10},{12,93},{},{96},{14,29,70,73},{26,49,71,76},{57,83},{67},{11,22,68,89},{18,35},{30,42,67},{17,44},{25},{21,58,68},{26,42,57,95},{},{17},{22,83},{60},{26,83,84,94},{69,80,82},{41,82},{19,23,52},{20,41},{24,56},{20,33},{38,71,99},{4,45},{33},{35},{47,56,64},{25,33,43,82},{13,77},{14,28,66},{},{2,43},{89}};
    cout<<isBipartite(graph)<<endl;
    return 0;
}
