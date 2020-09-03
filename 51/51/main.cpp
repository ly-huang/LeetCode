//
//  main.cpp
//  51
//
//  Created by ly on 2020/9/3.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void check(vector<vector<string>>& result, const int&n,int id,vector<int> pos,unsigned int columns,unsigned int diagonals1, unsigned int diagonals2)
{
    diagonals1<<=1;
    diagonals2>>=1;
    for(int i=0;i<n;i++)
    {
        unsigned int index=1<<i;
        if((columns&index)||(diagonals1&index)||(diagonals2&index))
            continue;
        pos.push_back(i);
        if(id==n-1)
        {
            vector<string> temp(n,"");
            for(int t1=0;t1<n;t1++)
            {
                for(int t2=0;t2<n;t2++)
                {
                    if(pos[t1]==t2)
                        temp[t1]+='Q';
                    else
                        temp[t1]+='.';
                }
            }
            result.push_back(temp);
        }
        else
        {
            check(result, n, id+1, pos,columns|index,diagonals1|index,diagonals2|index);
            pos.pop_back();
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    if(n<=0)
        return{};
    vector<vector<string>> result;
    check(result, n, 0, {},0,0,0);
    return result;
}
int main(int argc, const char * argv[]) {
    auto result=solveNQueens(4);
    for(auto item:result)
    {
        cout<<endl;
        for(auto i:item)
        {
            cout<<i<<endl;
        }
    }
    return 0;
}
