//
//  main.cpp
//  leetcode973
//
//  Created by ly on 2020/11/9.
//

#include <iostream>
#include <vector>
using namespace std;

void myQSort(vector<vector<int>> &points,int left,int right)
{
    if(left>=right)
        return;
    int i=left;
    int j=right;
    vector<int> temp;
    int data=pow(points[left][0],2)+pow(points[left][1], 2);
    while (i<j)
    {
        while (j>i&&pow(points[j][0],2)+pow(points[j][1],2)>data)
            j--;
        while (i<j&&pow(points[i][0],2)+pow(points[i][1],2)<=data)
            i++;
        temp=points[i];
        points[i]=points[j];
        points[j]=temp;
    }
    temp=points[i];
    points[i]=points[left];
    points[left]=temp;
    myQSort(points, left, i-1);
    myQSort(points, i+1, right);
}


vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    if(K==0)
        return {};
    int n=int(points.size());
    if(K>=n)
        return points;
    myQSort(points, 0, n-1);
    vector<vector<int>> result;
    for(int i=0;i<K;i++)
    {
        result.emplace_back(points[i]);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> points={{3,3},{5,-1},{-2,4}};
    auto result=kClosest(points, 2);
    for(const auto &item:result)
        cout<<item[0]<<" "<<item[1]<<endl;
    return 0;
}
