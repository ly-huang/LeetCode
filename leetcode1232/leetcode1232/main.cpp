//
//  main.cpp
//  leetcode1232
//
//  Created by ly on 2021/1/17.
//

#include <iostream>
#include <vector>
using namespace std;

bool checkStraightLine(vector<vector<int>>& coordinates) {
    int n=int(coordinates.size());
    if(n<2)
        return false;
    if(coordinates[0][0]==coordinates[1][0])
    {
        int x=coordinates[0][0];
        for(int i=2;i<n;i++)
        {
            if(coordinates[i][0]!=x)
                return false;
        }
        return true;
    }
    double a=((double)coordinates[0][1]-(double)coordinates[1][1])/((double)coordinates[0][0]-(double)coordinates[1][0]);
    double b=(double)coordinates[0][1]-a*(double)coordinates[0][0];
    for(int i=2;i<n;i++)
    {
        if(abs(coordinates[i][1]-(a*coordinates[i][0]+b))>0.001)
            return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    cout<<abs(-1)<<endl;
    return 0;
}
