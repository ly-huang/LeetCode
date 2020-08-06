//
//  main.cpp
//  leetcode336
//
//  Created by ly on 2020/8/6.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct node{
    int ch[26]={0};
    int flag=-1;
};

bool isPalindrome(string &word,int i,int j)
{
    while(i<j)
    {
        if(word[i++]!=word[j--])
            return false;
    }
    return true;
}

int findWord(vector<node>&tree,string&word,int i,int j)
{
    if(i>j)
        return tree[0].flag;
    int index=0;
    while(i<=j)
    {
        int x=word[j]-'a';
        if(tree[index].ch[x]==0)
            return -1;
        index=tree[index].ch[x];
        j--;
    }
    return tree[index].flag;
}

vector<vector<int>> palindromePairs(vector<string>& words) {
    if(words.empty())
        return {};
    int n=words.size();
    vector<vector<int>> result;
    
    vector<node> tree; //构建字典树
    tree.push_back(node());
    for(int i=0;i<n;i++)
    {
        int index=0;
        for(int j=0;j<words[i].length();j++)
        {
            int x=words[i][j]-'a';
            if(tree[index].ch[x]==0)
            {
                tree.push_back(node());
                tree[index].ch[x]=tree.size()-1;
            }
            index=tree[index].ch[x];
        }
        tree[index].flag=i;
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=words[i].length();j++)
        {
            if(j&&isPalindrome(words[i], 0, j-1))
            {
                int index=findWord(tree, words[i], j, words[i].length()-1);
                if(index!=-1&&index!=i)
                    result.push_back({index,i});
            }
            if(isPalindrome(words[i], j, words[i].length()-1))
            {
                int index=findWord(tree, words[i], 0, j-1);
                if(index!=-1&&index!=i)
                    result.push_back({i,index});
            }
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    vector<string> words={"a",""};
    auto result=palindromePairs(words);
    for(auto item:result)
        cout<<item[0]<<" "<<item[1]<<endl;
    return 0;
}
