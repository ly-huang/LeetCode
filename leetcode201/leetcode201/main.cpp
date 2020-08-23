//
//  main.cpp
//  leetcode201
//
//  Created by ly on 2020/8/23.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <bitset>
using namespace std;

//int rangeBitwiseAnd(int m, int n) {
//    if(m==0)
//        return 0;
//    int left=n;
//    int right=0;
//    for(int i=1;left!=0;i=i<<1)
//    {
//        int mid=n&i;
//        right=right|i;
//        if(mid!=0)
//        {
//            if(((n|right)^mid)>=m)
//                left=left^mid;
//            else
//                break;
//        }
//    }
//    return left;
//}


int rangeBitwiseAnd(int m, int n) {
    int i=0;
    for(;m!=n;i++)
    {
        m=m>>1;
        n=n>>1;
    }
    return m<<i;
    
}
int main(int argc, const char * argv[]) {
    cout<<rangeBitwiseAnd(5, 7)<<endl;
    return 0;
}
