//
//  main.cpp
//  leetcode922
//
//  Created by ly on 2020/11/12.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> sortArrayByParityII(vector<int>& A) {
    int n=int(A.size());
    vector<int> result(n);
    int i=0,j=1;
    for(int t=0;t<n;t++)
    {
        if(A[t]%2==0)
        {
            result[i]=A[t];
            i+=2;
        }
        else
        {
            result[j]=A[t];
            j+=2;
        }
    }
    return  result;

}

int main(int argc, const char * argv[]) {
    vector<int> A={4,2,5,7};
    auto result=sortArrayByParityII(A);
    for(const auto &i:result)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
