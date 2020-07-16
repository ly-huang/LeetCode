#include <iostream>
#include <vector>
using namespace std;


vector<int> divingBoard(int shorter, int longer, int k) {
    vector<int> result;
    if(k<=0)
        return result;
    if(shorter==longer)
    {
        result.push_back(k*longer);
        return result;
    }
    for(int i=0;i<=k;i++)
    {
        result.push_back((k-i)*shorter+i*longer);
    }
    return result;
}
int main() {
    int shorter=1;
    int longer=2;
    int k=3;
    auto result=divingBoard(shorter,longer,k);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<endl;
    return 0;
}
