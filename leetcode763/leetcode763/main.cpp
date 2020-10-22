//
//  main.cpp
//  leetcode763
//
//  Created by ly on 2020/10/22.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> partitionLabels(string S) {
    int m[26]={0};
    int n=int(S.length());
    for(int i=0;i<n;i++)
    {
        m[S[i]-'a']=i;
    }
    int last=0;
    int start=-1;
    vector<int> result;
    for(int i=0;i<n;i++)
    {
        if(m[S[i]-'a']>last)
            last=m[S[i]-'a'];
        if(i==last)
        {
            result.emplace_back(i-start);
            start=i;
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    auto result=partitionLabels("ababcbacadefegdehijhklij");
    for(const auto &i:result)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
