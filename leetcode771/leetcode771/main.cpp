//
//  main.cpp
//  leetcode771
//
//  Created by ly on 2020/10/2.
//

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int numJewelsInStones(string J, string S) {
    if(J.length()==0||S.length()==0)
        return 0;
    int n=int(J.length());
    unordered_map<char, int> m;
    int result=0;
    for(int i=0;i<n;i++)
    {
        m[J[i]]=1;
    }
    n=int(S.length());
    for(int i=0;i<n;i++)
    {
        if(m[S[i]]==1)
            result++;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    cout<<numJewelsInStones("aA", "aAAbbbb")<<endl;
    return 0;
}
