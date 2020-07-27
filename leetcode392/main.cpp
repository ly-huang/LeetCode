#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string s, string t) {
    int l1=s.length();
    int l2=t.length();
    int i=0,j=0;
    for(;i<l1&&j<l2;j++)
    {
        if(s[i]==t[j])
            i++;
    }
    return i==l1;
}
int main() {
    cout<<isSubsequence("axc","ahbgdc")<<endl;
    return 0;
}
