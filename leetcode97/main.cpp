#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    if(s3.length()!=(s1.length()+s2.length()))
        return false;
    vector<bool> dp(s1.length()+1,false);
    dp[0]=true;
    for(int i=1;i<=s1.length()&&s1[i-1]==s3[i-1];i++)
        dp[i]=true;
    for(int i=1;i<=s2.length();i++)
        for(int j=0;j<=s1.length();j++)
        {
            if(dp[j]&&s3[i+j-1]==s2[i-1])
            {
                dp[j]=true;
                continue;
            }
            if(j==0)
            {
                dp[j]=false;
                continue;
            } else{
                if(dp[j-1]&&s3[i+j-1]==s1[j-1])
                {
                    dp[j]=true;
                } else
                    dp[j]=false;
            }
        }
    return dp[s1.length()];
}
int main() {
    cout<<isInterleave("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa","babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab","babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab")<<endl;
    return 0;
}
