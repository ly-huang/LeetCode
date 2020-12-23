//
//  main.cpp
//  leetcode387
//
//  Created by ly on 2020/12/23.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int firstUniqChar(string s) {
    if(s.empty())
        return -1;
    vector<int> data(26,-1);
    int n=(int)s.length();
    int index;
    for(int i=0;i<n;i++)
    {
        index=s[i]-'a';
        if(data[index]==-1)
            data[index]=i;
        else if(data[index]>-1)
            data[index]=-2;
    }
    int result=n;
    for(int i=0;i<26;i++)
    {
        if(data[i]>-1&&data[i]<result)
            result=data[i];
    }
    if(result==n)
        return -1;
    return result;

}

int main(int argc, const char * argv[]) {
    
    return 0;
    
}
