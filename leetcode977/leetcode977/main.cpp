//
//  main.cpp
//  leetcode977
//
//  Created by ly on 2020/10/16.
//

#include <iostream>
#include <vector>
using namespace std;

//vector<int> sortedSquares(vector<int>& A) {
//    vector<int> result;
//    int n=int(A.size());
//    if(n==0)
//        return result;
//    int i=0;
//    while(i<n&&A[i]<0)
//        i++;
//    int j=i-1;
//    while(j>=0&&i<n)
//    {
//        if(A[i]<-A[j])
//        {
//            result.emplace_back(A[i]*A[i]);
//            i++;
//        }
//        else
//        {
//            result.emplace_back(A[j]*A[j]);
//            j--;
//        }
//    }
//    while(j>=0)
//    {
//        result.emplace_back(A[j]*A[j]);
//        j--;
//    }
//    while(i<n)
//    {
//        result.emplace_back(A[i]*A[i]);
//        i++;
//    }
//    return result;
//}

vector<int> sortedSquares(vector<int>& A) {
    if(A.empty())
        return {};
    size_t n=A.size();
    vector<int> result(n,0);
    size_t i=0,j=n-1;
    n--;
    int a;
    int b;
    while(i<=j)
    {
        a=A[i]*A[i];
        b=A[j]*A[j];
        if(a>=b)
        {
            result[n]=a;
            i++;
        }
        else
        {
            result[n]=b;
            j--;
        }
        n--;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> A={1};
    sortedSquares(A);
    return 0;
}
