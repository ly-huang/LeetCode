#include <iostream>
using namespace std;

//bool divisorGame(int N) {
//    if(N%2==0)
//        return true;
//    return false;
//}

bool divisorGame(int N) {
    bool *dp=new bool[N+1];
    for(int i=0;i<=N;i++)
        dp[i]=false;
    dp[1]=false;
    for(int i=2;i<=N;i++)
    {
        for(int j=i-1;j>0;j--)
        {
            if(i%j==0&&!dp[i-j])
            {
                dp[i]=true;
                break;
            }
        }
    }
    bool result=dp[N];
    delete []dp;
    return result;
}
int main() {
    cout<<divisorGame(8)<<endl;
    return 0;
}
