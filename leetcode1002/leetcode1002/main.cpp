//
//  main.cpp
//  leetcode1002
//
//  Created by ly on 2020/10/14.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<string> commonChars(vector<string>& A) {
    vector<string> result;
    if(A.empty())
        return result;
    int n=int(A.size());
    vector<vector<int>> data(n,vector<int>(26,0));
    for(int i=0;i<n;i++)
    {
        for(const auto &c:A[i])
            data[i][c-'a']++;
    }
    int count=INT_MAX;
    for(int i=0;i<26;i++)
    {
        count=INT_MAX;
        for(int j=0;j<n;j++)
        {
            if(data[j][i]<count)
                count=data[j][i];
        }
        string s;
        s.push_back('a'+i);
        for(int t=0;t<count;t++)
        {
            result.emplace_back(s);
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<string> A={"bella","label","roller"};
    auto result=commonChars(A);
    for(const auto &c:result)
        cout<<c<<" ";
    cout<<endl;
    return 0;
}
