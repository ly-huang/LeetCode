#include <iostream>
#include <string>
using namespace std;


bool check(const string &s,const string &p,int &index,int i,int j) {
    while(index<s.length())
    {
        if(s[index]==p[i]||p[i]=='?')
        {
            int t1=index+1;
            int t2=i+1;
            for(;t2<j;t1++,t2++)
            {
                if(t1==s.length())
                    return false;
                if(s[t1]==p[t2]||p[t2]=='?')
                    continue;
                break;
            }
            if(t2==j)
            {
                index=t1;
                return true;
            }
        }
        index++;
    }
    return false;
}


bool isMatch(string s, string p) {
    if(s==""&&p=="")
        return true;
    if(s=="")
    {
        for(int i =0;i<p.length();i++)
        {
            if(p[i]!='*')
                return false;
        }
        return true;
    }
    if(p=="")
        return false;
    int len=0;
    if(p[0]!='*')
    {
        while(len<p.length()&&p[len]!='*')
        {
            if(len==s.length())
                return false;
            if(p[len]!='?'&&s[len]!=p[len])
                return false;
            len++;
        }

    }
    if(len==p.length()&&len<s.length())
        return false;

    int i=len;
    int j=i;
    while(len<s.length())
    {
        i=j;
        while(i<p.length()&&p[i]=='*')
            i++;
        if(i==p.length()&&p[i-1]=='*')
            return true;
        j=i;
        while(j<p.length()&&p[j]!='*')
            j++;
        if(j==p.length())
        {
            if(j-i>s.length()-len)
                return false;
            j--;
            int index=s.length()-1;
            while(j>=i)
            {
                if(p[j]!='?'&&s[index]!=p[j])
                    return false;
                j--;
                index--;
            }
            return true;
        }
        if(!check(s,p,len,i,j))
            return false;
    }
    while(j<p.length())
    {
        if(p[j]!='*')
            return false;
        j++;
    }
    return true;
}

int main() {
    cout<<isMatch("abc","*abc?*")<<endl;
    return 0;
}
