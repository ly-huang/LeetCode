//
//  main.cpp
//  leetcode85
//
//  Created by ly on 2020/12/26.
//

#include <iostream>
#include <vector>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty())
        return 0;
    int n=int(matrix.size());
    int m=int(matrix[0].size());
    int result=0;
    int count_c;//以matrix[i][j]为左上角的矩阵，当行数为x时最大的列数
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)//遍历每个以matrix[i][j]为左上角的矩形
        {
            count_c=INT_MAX;
            for(int t1=i;t1<n&&matrix[t1][j]=='1';t1++)
            {
                int t2=j;
                while(t2<m&&matrix[t1][t2]=='1')
                    t2++;
                count_c=min(count_c,t2-j);
                if(result<(t1-i+1)*count_c)
                    result=(t1-i+1)*count_c;
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<char>> matrix={{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout<<maximalRectangle(matrix)<<endl;
    return 0;
}
