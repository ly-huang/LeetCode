//
//  main.cpp
//  leetcode127
//
//  Created by ly on 2020/11/5.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;


int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    if(wordList.empty()||beginWord==endWord)
        return 0;
    int n=int(wordList.size());
    int l=int(beginWord.length());
    vector<bool> mark(n,false);
    queue<int> q;
    q.emplace(n);
    wordList.emplace_back(beginWord);
    int result=1;
    int count;
    string s;
    int c;
    while (!q.empty())
    {
        count=int(q.size());
        result++;
        while(count>0)
        {
            count--;
            s=wordList[q.front()];
            q.pop();
            for(int i=0;i<n;i++)
            {
                if(mark[i])
                    continue;
                c=0;
                for(int j=0;j<l&&c<=1;j++)
                {
                    if(wordList[i][j]!=s[j])
                        c++;
                }
                if(c<=1)
                {
                    if(wordList[i]==endWord)
                        return result;
                    q.emplace(i);
                    mark[i]=true;
                }
            }
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    string beginWord="hit";
    string endWord="cog";
    vector<string> wordList={"hot","dot","dog","lot","log","cog"};
    cout<<ladderLength(beginWord, endWord, wordList)<<endl;
    return 0;
}
