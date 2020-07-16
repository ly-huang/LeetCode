#include <iostream>
#include <string>
#include <stack>
using namespace std;

int longestValidParentheses(string s) {
    if(s=="")
        return 0;
    int result=0;

    stack<int> index;
    index.push(-1);
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
            index.push(i);
        else
        {
            index.pop();
            if(!index.empty())
            {
                int temp=i-index.top();
                if(temp>result)
                    result=temp;
            } else
                index.push(i);
        }
    }
    return result;
}
int main() {
    string s=")(((((()())()()))()(()))(";
    cout<<longestValidParentheses(s)<<endl;
    return 0;
}
