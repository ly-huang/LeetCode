#include <iostream>
using namespace std;

int numTrees(int n) {
    if(n<=1)
        return 1;
    int *G=new int[n+1];
    G[0]=G[1]=1;
    for(int i=2;i<=n;i++)
    {
        G[i]=0;
        for(int j=1;j<=i;j++)
            G[i]+=G[j-1]*G[i-j];
    }
    int result=G[n];
    delete []G;
    return result;
}
int main() {
    cout<<numTrees(4)<<endl;
    return 0;
}
