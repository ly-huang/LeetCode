//
//  main.cpp
//  leetcode452
//
//  Created by ly on 2020/11/23.
//

#include <iostream>
#include <vector>
using namespace std;



void myQSort(vector<vector<int>>& points,int left,int right)
{
    if(left>=right)
        return;
    int i=left;
    int j=right;
    int temp_i;
    int temp_j;
    while(i<j)
    {
        while(j>i&&points[j][1]>points[left][1])
            j--;
        while (i<j&&points[i][1]<=points[left][1])
            i++;
        temp_i=points[i][0];
        temp_j=points[i][1];
        points[i]=points[j];
        points[j][0]=temp_i;
        points[j][1]=temp_j;
    }
    temp_i=points[i][0];
    temp_j=points[i][1];
    points[i]=points[left];
    points[left][0]=temp_i;
    points[left][1]=temp_j;
    myQSort(points, left, i-1);
    myQSort(points, i+1, right);
}

int findMinArrowShots(vector<vector<int>>& points) {
    if(points.empty())
        return 0;
    int n=int(points.size());
    vector<bool> mark(n,false);
    int result=1;
    myQSort(points, 0, n-1);
    int pos=points[0][1];
    for(auto i:points)
    {
        if(i[0]>pos)
        {
            result++;
            pos=i[1];
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> points={{7,15},{6,14},{8,12},{3,4},{4,13},{6,14},{9,11},{6,12},{4,13}};
    cout<<findMinArrowShots(points)<<endl;
    return 0;
}
