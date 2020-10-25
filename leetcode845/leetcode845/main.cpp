//
//  main.cpp
//  leetcode845
//
//  Created by ly on 2020/10/25.
//

#include <iostream>
#include <vector>
using namespace std;

enum type {level,up,down};

//int longestMountain(vector<int>& A) {
//    if(A.empty())
//        return 0;
//    int n=int(A.size());
//    int result=0;
//    int cur=0;
//    type t=level;
//    for(int i=1;i<n;i++)
//    {
//        if(A[i]>A[i-1])
//        {
//            if(t==up)
//                cur++;
//            else if(t==level)
//            {
//                cur=2;
//                t=up;
//            }
//            else
//            {
//                if(cur>result)
//                    result=cur;
//                t=up;
//                cur=2;
//            }
//        }
//        else if(A[i]==A[i-1])
//        {
//            if(t==up)
//            {
//                t=level;
//                cur=0;
//            }
//            else if(t==down)
//            {
//                if(cur>result)
//                    result=cur;
//                t=level;
//                cur=0;
//            }
//        }
//        else
//        {
//            if(t==up)
//            {
//                cur++;
//                t=down;
//            }
//            else if(t==down)
//                cur++;
//        }
//    }
//    if(t==down&&cur>result)
//        result=cur;
//    return result;
//}

int longestMountain(vector<int>& A) {
    int n=int(A.size());
    if(n<3)
        return 0;
    int pos=0;//起点
    int i=1;
    int result=0;
    while(i<n)
    {
        while(i<n&&A[i]<=A[i-1])//寻找起点
            i++;
        if(i==n)
            break;
        pos=i-1;
        i++;
        while(i<n&&A[i]>A[i-1])//向上的过程
            i++;
        if(i==n)
            break;
        if(A[i]==A[i-1])//山顶是平的，不符合条件
            continue;
        i++;
        while (i<n&&A[i]<A[i-1])//向下的过程
            i++;
        if(i-pos>result)
            result=i-pos;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> A={0,1,2,3,4,5,4,3,2,1,0};
    cout<<longestMountain(A)<<endl;
    return 0;
}
