//
//  main.cpp
//  leetcode37
//
//  Created by ly on 2020/9/15.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

//bool getResult(vector<vector<char>>&board,const int &index_i,const int &index_j)
//{
//    vector<bool> row(9,true);
//    vector<bool> col(9,true);
//    vector<bool> grid(9,true);
//    char data;
//    for(int i=0;i<9;i++)
//    {
//        data=board[i][index_j];
//        if(data!='.')
//            col[data-'0'-1]=false;
//    }
//
//    for(int j=0;j<9;j++)
//    {
//        data=board[index_i][j];
//        if(data!='.')
//            row[data-'0'-1]=false;
//    }
//    for(int i=index_i/3*3,t1=0;t1<3;t1++)
//    {
//        for(int j=index_j/3*3,t2=0;t2<3;t2++)
//        {
//            data=board[i+t1][j+t2];
//            if(data!='.')
//                grid[data-'0'-1]=false;
//        }
//    }
//    for(int i=0;i<9;i++)
//    {
//        if(row[i]&&col[i]&&grid[i])
//        {
//            board[index_i][index_j]='0'+i+1;
//            int next_i=index_i,next_j=index_j+1;
//            while(next_j<9&&board[next_i][next_j]!='.')
//                next_j++;
//            if(next_j!=9)
//            {
//                if(getResult(board, next_i, next_j))
//                    return true;
//            }
//            else
//            {
//                for(next_i=next_i+1;next_i<9;next_i++)
//                {
//                    for(next_j=0;next_j<9;next_j++)
//                    {
//                        if(board[next_i][next_j]=='.')
//                            break;
//                    }
//                    if(next_j<9)
//                        break;;
//                }
//                if(next_i!=9)
//                {
//                    if(getResult(board, next_i, next_j))
//                        return true;
//                }
//                else
//                    return true;
//            }
//        }
//    }
//    board[index_i][index_j]='.';
//    return false;
//}
//
//void solveSudoku(vector<vector<char>>& board) {
//    if(board.empty())
//        return;
//    int index_i=0;
//    int index_j=0;
//    for(;index_i<9;index_i++)
//    {
//        for(index_j=0;index_j<9;index_j++)
//        {
//            if(board[index_i][index_j]=='.')
//                break;
//        }
//        if(index_j<9)
//            break;;
//    }
//    if(index_i!=9)
//        getResult(board, index_i, index_j);
//}

bool getResult(vector<vector<char>> &board,vector<int> &row, vector<int> &col, vector<vector<int>> &grid,const vector<pair<int, int>> &todo,int index)
{
    int index_i=todo[index].first;
    int index_j=todo[index].second;
    int mark=row[index_i]|col[index_j]|grid[index_i/3][index_j/3];
    int temp;
    for(int i=0;i<9;i++)
    {
        temp=1<<i;
        if((mark&temp)==0)
        {
            board[index_i][index_j]='1'+i;
            if(index+1==todo.size())
                return true;
            row[index_i]|=temp;
            col[index_j]|=temp;
            grid[index_i/3][index_j/3]|=temp;
            if(getResult(board, row, col, grid, todo, index+1))
                return true;
            row[index_i]^=temp;
            col[index_j]^=temp;
            grid[index_i/3][index_j/3]^=temp;
        }
    }
    board[index_i][index_j]='.';
    return false;
}

void solveSudoku(vector<vector<char>>& board)
{
    if(board.empty())
        return;
    vector<int> row(9,0);
    vector<int> col(9,0);
    vector<vector<int>> grid(3,vector<int>(3,0));
    vector<pair<int, int>> todo;
    char data;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            data=board[i][j];
            if(data=='.')
                todo.push_back(make_pair(i, j));
            else
            {
                int temp=1<<(data-'1');
                row[i]|=temp;
                col[j]|=temp;
                grid[i/3][j/3]|=temp;
            }
        }
    }
    getResult(board, row, col, grid, todo, 0);
}


int main(int argc, const char * argv[]) {
    vector<vector<char>> board={
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}};
    solveSudoku(board);
    for(const auto &item : board)
    {
        for(const auto &c : item)
            cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}
