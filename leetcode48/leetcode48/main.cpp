//
//  main.cpp
//  leetcode48
//
//  Created by ly on 2020/12/19.
//

#include <iostream>
#include <vector>
using namespace std;

//void rotate(vector<vector<int>>& matrix) {
//    if(matrix.empty()||matrix[0].empty())
//        return;
//    int n=int(matrix.size())-1;
//    int a,b,t,next_a,next_b,next_t;
//    for(int i=0;i<=n;i++)
//    {
//        for(int j=i;j<n-i;j++)
//        {
//            a=i;b=j;
//            t=matrix[a][b];
//            while(true)
//            {
//                next_a=b;
//                next_b=n-a;
//                next_t=matrix[next_a][next_b];
//                matrix[next_a][next_b]=t;
//                a=next_a;
//                b=next_b;
//                t=next_t;
//                if(next_a==i&&next_b==j)
//                    break;
//            }
//        }
//    }
//}

void rotate(vector<vector<int>>& matrix) {
    int n = int(matrix.size());
    // 水平翻转
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n; ++j) {
            swap(matrix[i][j], matrix[n - i - 1][j]);
        }
    }
    // 主对角线翻转
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix={{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    rotate(matrix);
    for(auto i:matrix)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
