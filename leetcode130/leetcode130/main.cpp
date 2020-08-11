//
//  main.cpp
//  leetcode130
//
//  Created by ly on 2020/8/11.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void check(vector<vector<char>> &board,vector<vector<bool>> &valid,int i,int j)
{
    valid[i][j]=true;
    if(i!=0&&board[i-1][j]=='O'&&(!valid[i-1][j]))
        check(board, valid,i-1, j);
    if(i!=board.size()-1&&board[i+1][j]=='O'&&(!valid[i+1][j]))
        check(board, valid,i+1, j);
    if(j!=0&&board[i][j-1]=='O'&&(!valid[i][j-1]))
        check(board, valid,i, j-1);
    if(j!=board[0].size()-1&&board[i][j+1]=='O'&&(!valid[i][j+1]))
        check(board, valid,i, j+1);
}

void solve(vector<vector<char>>& board) {
    if(board.empty()||board[0].empty())
        return;
        
    vector<vector<bool>> valid(board.size(),vector<bool>(board[0].size(),false));
    for(int i=0,j=0;j<board[0].size();j++)
    {
        if(board[i][j]=='O')
            check(board, valid,i, j);
    }
    for(int i=board.size()-1,j=0;j<board[0].size();j++)
    {
        if(board[i][j]=='O')
            check(board, valid,i, j);
    }
    for(int i=1,j=0;i<board.size()-1;i++)
    {
        if(board[i][j]=='O')
            check(board, valid,i, j);
    }
    for(int i=1,j=board[0].size()-1;i<board.size()-1;i++)
    {
        if(board[i][j]=='O')
            check(board, valid,i, j);
    }
    for(int i=1;i<board.size()-1;i++)
    {
        for(int j=1;j<board[0].size()-1;j++)
        {
            if((!valid[i][j])&&board[i][j]=='O')
                board[i][j]='X';
        }
    }
}

int main(int argc, const char * argv[]) {
    vector<vector<char>> board={{'O','X','X','O','X'},{'X','O','O','X','O'},{'X','O','X','O','X'},{'O','X','O','O','O'},{'X','X','O','X','O'}};
//    vector<vector<char>> board={};
    solve(board);
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
