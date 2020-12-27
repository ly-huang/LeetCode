//
//  main.cpp
//  leetcode205
//
//  Created by ly on 2020/12/27.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isIsomorphic(string s, string t) {
    if(s.length()!=t.length())
        return false;
    int n=int(s.length());
    vector<int> hash_map1(256,-1);
    vector<int> hash_map2(256,-1);
    for(int i=0;i<n;i++)
    {
        if(hash_map1[s[i]]==-1)
            hash_map1[s[i]]=t[i];
        else if(hash_map1[s[i]]!=t[i])
            return false;
        if(hash_map2[t[i]]==-1)
            hash_map2[t[i]]=s[i];
        else if(hash_map2[t[i]]!=s[i])
            return false;
    }
    for(int i=0;i<256;i++)
    {
        if(hash_map1[i]!=-1&&hash_map2[hash_map1[i]]!=i)
            return false;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
