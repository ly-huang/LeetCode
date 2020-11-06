//
//  main.cpp
//  leetcode1356
//
//  Created by ly on 2020/11/6.
//

#include <iostream>
#include <vector>
using namespace std;


//如果a>b，则返回true
inline bool compare(const int &a,const int &b)
{
    int count_a=0;
    int count_b=0;
    for(int i=a;i>0;i=i>>1)
    {
        count_a+=i&1;
    }
    for(int i=b;i>0;i=i>>1)
    {
        count_b+=i&1;
    }
    if(count_a>count_b)
        return true;
    if(count_a==count_b&&a>b)
        return true;
    return false;

}

void myQSort(vector<int>&arr ,int left,int right)
{
    if(left>=right)
        return;
    int i=left;
    int j=right;
    int temp;
    while(i<j)
    {
        while(j>i&&compare(arr[j], arr[left]))
            j--;
        while(i<j&&(!compare(arr[i], arr[left])))
            i++;
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    temp=arr[left];
    arr[left]=arr[i];
    arr[i]=temp;
    myQSort(arr, left, i-1);
    myQSort(arr, i+1, right);
}

vector<int> sortByBits(vector<int>& arr) {
    myQSort(arr, 0, int(arr.size()-1));
    return arr;
}

int main(int argc, const char * argv[]) {
    vector<int> arr={0,1,2,3,4,5,6,7,8};
    auto result=sortByBits(arr);
    for(const auto &i: result)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
