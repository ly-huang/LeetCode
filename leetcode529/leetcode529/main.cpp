//
//  main.cpp
//  leetcode529
//
//  Created by ly on 2020/8/20.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    if(board.empty())
        return board;
    int i=click[0],j=click[1];
    int n=board.size(),m=board[0].size();
    if(i>=n||j>=m)
        return board;
    vector<vector<char>> result=board;
    if(result[i][j]=='M')
    {
        result[i][j]='X';
        return result;
    }
    
    stack<vector<int>> pos;
    pos.push(click);
    while(!pos.empty())
    {
        vector<int> index=pos.top();
        pos.pop();
        i=index[0],j=index[1];
        int count=0;
        if(i-1>=0)
        {
            if(j-1>=0&&result[i-1][j-1]=='M')
                count++;
            if(result[i-1][j]=='M')
                count++;
            if(j+1<m&&result[i-1][j+1]=='M')
                count++;
        }
        if(j-1>=0&&result[i][j-1]=='M')
            count++;
        if(j+1<m&&result[i][j+1]=='M')
            count++;
        if(i+1<n)
        {
            if(j-1>=0&&result[i+1][j-1]=='M')
                count++;
            if(result[i+1][j]=='M')
                count++;
            if(j+1<m&&result[i+1][j+1]=='M')
                count++;
        }
        if(count!=0)
            result[i][j]='0'+count;
        else
        {
            result[i][j]='B';
            if(i-1>=0)
            {
                if(j-1>=0&&result[i-1][j-1]=='E')
                    pos.push({i-1,j-1});
                if(result[i-1][j]=='E')
                    pos.push({i-1,j});
                if(j+1<m&&result[i-1][j+1]=='E')
                    pos.push({i-1,j+1});
            }
            if(j-1>=0&&result[i][j-1]=='E')
                pos.push({i,j-1});
            if(j+1<m&&result[i][j+1]=='E')
                pos.push({i,j+1});
            if(i+1<n)
            {
                if(j-1>=0&&result[i+1][j-1]=='E')
                    pos.push({i+1,j-1});
                if(result[i+1][j]=='E')
                    pos.push({i+1,j});
                if(j+1<m&&result[i+1][j+1]=='E')
                    pos.push({i+1,j+1});
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<char>> board={{'E', 'E', 'E', 'E', 'E'},
         {'E', 'E', 'M', 'E', 'E'},
         {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'}};
    vector<int> click={3,0};
    auto result=updateBoard(board,click);
    for(auto i:result)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
