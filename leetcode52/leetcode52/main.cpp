//
//  main.cpp
//  leetcode52
//
//  Created by ly on 2020/10/17.
//

#include <iostream>
using namespace std;

void getResult(const int &n,int index,int &m,int &ml,int &mr,int &result)
{
    bool v=mr&1;
    ml=ml<<1;
    mr=mr>>1;
    int t=1;
    for(int i=0;i<n;i++)
    {
        t=1<<i;
        if(t&m||t&ml||t&mr)
            continue;
        if(index==n)
        {
            result+=1;
            break;
        }
        else
        {
            m|=t;
            ml|=t;
            mr|=t;
            getResult(n, index+1, m, ml, mr, result);
            m^=t;
            ml^=t;
            mr^=t;
        }
    }
    ml=ml>>1;
    mr=mr<<1;
    if(v)
        mr+=1;
}

int totalNQueens(int n) {
    int result=0;
    int m=0;
    int ml=0;
    int mr=0;
    getResult(n, 1, m, ml, mr, result);
    return result;
    
}

int main(int argc, const char * argv[]) {
    cout<<totalNQueens(4)<<endl;
    return 0;
}
