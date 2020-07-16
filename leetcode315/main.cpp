#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int>& nums,vector<int>& index,vector<int>&result,int begin,int end)
{
    if(begin==end)
        return;
    int mid=(begin+end)/2;
    sort(nums,index,result,begin,mid);
    sort(nums,index,result,mid+1,end);
    vector<int> temp(end-begin+1);
    for(int i=0;i<end-begin+1;i++)
        temp[i]=index[begin+i];
    int i=begin,j=mid+1;
    int t=i;
    for(;i<mid+1&&j<end+1;t++)
    {
        if(nums[temp[i-begin]]<=nums[temp[j-begin]])
        {
            index[t]=temp[i-begin];
            i++;
        } else
        {
            index[t]=temp[j-begin];
            for(int t1=i;t1<mid+1;t1++)
                result[temp[t1-begin]]++;
            j++;
        }
    }
    for(;i<mid+1;i++,t++)
    {
        index[t]=temp[i-begin];
    }
    for(;j<end+1;j++,t++)
    {
        index[t]=temp[j-begin];
    }
}

vector<int> countSmaller(vector<int>& nums) {
    int n=nums.size();
    if(n==0)
        return vector<int>();
    vector<int> index(n);
    for(int i=0;i<n;i++)
        index[i]=i;
    vector<int> result(n,0);
    sort(nums,index,result,0,n-1);
    return result;

}
int main() {
    vector<int> nums={5,2,6,1};
    auto result=countSmaller(nums);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<" ";
    cout<<endl;
    return 0;
}
