#include <iostream>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    if(s=="")
        return 0;
    int n=s.length();
    int result=1;
    int index[255];
    for(int i=0;i<255;i++)
        index[i]=-1;
    int begin=0;
    index[s[0]]=0;
    int temp=1;
    int i=begin+1;
    while(i<n)
    {
        if(index[s[i]]!=-1&&index[s[i]]>=begin&&index[s[i]]!=i)
        {
            if(temp>result)
                result=temp;
            begin=index[s[i]]+1;
            if(n+1-begin<temp)
                break;
            i=begin+1;
            temp=1;
            index[s[begin]]=begin;
            continue;

        }
        index[s[i]]=i;
        temp++;
        i++;
    }
    if(temp>result)
        result=temp;
    return result;

}
int main() {
    cout<<lengthOfLongestSubstring("au")<<endl;
    return 0;
}
