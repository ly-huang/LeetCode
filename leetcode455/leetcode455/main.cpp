//
//  main.cpp
//  leetcode455
//
//  Created by ly on 2020/12/25.
//

#include <iostream>
#include <vector>
using namespace std;

void myQSort(vector<int> &data,int left,int right)
{
    if(left>=right)
        return;
    int i=left;
    int j=right;
    int temp;
    while(i<j)
    {
        while(j>i&&data[j]<data[left])
            j--;
        while(i<j&&data[i]>=data[left])
            i++;
        temp=data[i];
        data[i]=data[j];
        data[j]=temp;
    }
    temp=data[i];
    data[i]=data[left];
    data[left]=temp;
    myQSort(data, left, i-1);
    myQSort(data, i+1, right);
}

int findContentChildren(vector<int>& g, vector<int>& s) {
    int l1=int(g.size());
    int l2=int(s.size());
    myQSort(g, 0, l1-1);
    myQSort(s, 0, l2-1);
    int resullt=0;
    int i=0,j=0;
    while(i<l1&&j<l2)
    {
        if(s[j]>=g[i])
        {
            resullt++;
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    return resullt;
}

int main(int argc, const char * argv[]) {
    vector<int> g={1,2,3};
    vector<int> s={1,2,3};
    cout<<findContentChildren(g, s)<<endl;
    return 0;
}
