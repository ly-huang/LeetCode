//
//  main.cpp
//  leetcode79
//
//  Created by ly on 2020/9/13.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool getResult(const vector<vector<char>> &board,const string &word,const size_t &index_i,const size_t &index_j,const size_t &index,vector<vector<bool>> &mark,const size_t &n,const size_t &m,const size_t &l)
{
    if(index_i!=0&&mark[index_i-1][index_j]&&board[index_i-1][index_j]==word[index])//up
    {
        if(l==index+1)
            return true;
        mark[index_i-1][index_j]=false;
        if(getResult(board, word, index_i-1, index_j, index+1, mark, n, m, l))
            return true;
        mark[index_i-1][index_j]=true;
    }
    if(index_i!=n-1&&mark[index_i+1][index_j]&&board[index_i+1][index_j]==word[index])//down
    {
        if(l==index+1)
            return true;
        mark[index_i+1][index_j]=false;
        if(getResult(board, word, index_i+1, index_j, index+1, mark, n, m, l))
            return true;
        mark[index_i+1][index_j]=true;
    }
    if(index_j!=0&&mark[index_i][index_j-1]&&board[index_i][index_j-1]==word[index])//left
    {
        if(l==index+1)
            return true;
        mark[index_i][index_j-1]=false;
        if(getResult(board, word, index_i, index_j-1, index+1, mark, n, m, l))
            return true;
        mark[index_i][index_j-1]=true;
    }
    if(index_j!=m-1&&mark[index_i][index_j+1]&&board[index_i][index_j+1]==word[index])//right
    {
        if(l==index+1)
            return true;
        mark[index_i][index_j+1]=false;
        if(getResult(board, word, index_i, index_j+1, index+1, mark, n, m, l))
            return true;
        mark[index_i][index_j+1]=true;
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    if(board.empty()||word.empty())
        return false;
    size_t n=board.size();
    size_t m=board[0].size();
    size_t l=word.length();
    vector<vector<bool>> mark(n,vector<bool>(m,true));
    for(size_t i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]==word[0])
            {
                if(l==1)
                    return true;
                mark[i][j]=false;
                if(getResult(board, word, i, j, 1, mark, n, m, l))
                   return true;
                mark[i][j]=true;
                
            }
                
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    vector<vector<char>> board={  {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}};
    string word="ABCB";
    cout<<exist(board, word)<<endl;
    return 0;
}
