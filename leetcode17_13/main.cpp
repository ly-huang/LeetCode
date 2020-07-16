#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Trie{
    Trie* next[26];
    bool isEnd;
    Trie(){for(int i=0;i<26;i++)next[i]=NULL;isEnd=false;}
};
class Mytrie{
private:
    Trie *root=NULL;
    void destroy(Trie *ptr){
        for(int i=0;i<26;i++)
        {
            if(ptr->next[i]!=NULL)
                destroy(ptr->next[i]);
        }
        delete ptr;
    }
public:
    Mytrie(){root=new Trie;}
    void insert(string s){
        Trie*ptr=root;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(ptr->next[s[i]-'a']==NULL)
                ptr->next[s[i]-'a']=new Trie;
            ptr=ptr->next[s[i]-'a'];
        }
        ptr->isEnd=true;
    }
    const Trie *getRoot(){return root;}
    ~Mytrie(){
        destroy(root);
    }

};
int respace(vector<string>& dictionary, string sentence) {
    if(dictionary.empty())
        return sentence.length();
    if(sentence=="")
        return 0;

    Mytrie mytrie;
    for(int i=0;i<dictionary.size();i++)
        mytrie.insert(dictionary[i]);

    const Trie*ptr=mytrie.getRoot();
    vector<int> dp(sentence.length()+1);
    for(int i=0;i<dp.size();i++)
        dp[i]=i;
    for(int i=0;i<sentence.length();i++)
    {
        dp[i + 1] = dp[i] + 1;
        if (ptr->next[sentence[i] - 'a'] != NULL)
        {
            const Trie *cur = ptr;
            for (int j = i; j >= 0; j--)
            {
                if (cur->next[sentence[j] - 'a'] != NULL)
                {
                    if (cur->next[sentence[j] - 'a']->isEnd)
                        dp[i + 1] = (dp[j] < dp[i + 1] ? dp[j] : dp[i + 1]);
                    cur = cur->next[sentence[j] - 'a'];
                } else
                    break;
            }
        }
    }
    return dp.back();
}
int main() {
    vector<string> dictionary={"looked","just","like","her","brother"};
    string sentence="jesslookedjustliketimherbrother";
    cout<<respace(dictionary,sentence)<<endl;
    return 0;
}
