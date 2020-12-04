//
//  main.cpp
//  leetcode321
//
//  Created by ly on 2020/12/4.
//

#include <iostream>
#include <vector>
using namespace std;


vector<int> myStack(const vector<int> &nums,int k)
{
    vector<int> result(k);
    int n=int(nums.size());
    int index=0;
    int i=0;
    while(i<n)
    {
        if(n-i==k-index)
        {
            while(i<n)
                result[index++]=nums[i++];
        }
        else
        {
            if(index>0&&nums[i]>result[index-1])
            {
                index--;
            }
            else if(index<k)
                result[index++]=nums[i++];
            else
                i++;
        }
    }
    return result;
}


void merge(const vector<int> &nums1,const vector<int> &nums2,vector<int> &result,const int &k)
{
    int n1=int(nums1.size());
    int n2=int(nums2.size());
    vector<int> temp(k);
    int index=0;
    int i=0;
    int j=0;
    while(i<n1&&j<n2)
    {
        if(nums1[i]>nums2[j])
        {
            temp[index++]=nums1[i++];
        }
        else if(nums2[j]>nums1[i])
        {
            temp[index++]=nums2[j++];
        }
        else
        {
            bool valid=false;
            for(int m=1,c=min(n1-i,n2-j);m<c;m++)
            {
                if(nums1[i+m]>nums2[j+m])
                {
                    temp[index++]=nums1[i++];
                    valid=true;
                    break;
                }
                else if(nums2[j+m]>nums1[i+m])
                {
                    temp[index++]=nums2[j++];
                    valid=true;
                    break;
                }
            }
            if(!valid)
            {
                if(n1-i<n2-j)
                    temp[index++]=nums2[j++];
                else
                    temp[index++]=nums1[i++];
            }
        }
    }
    while(i<n1)
        temp[index++]=nums1[i++];
    while(j<n2)
        temp[index++]=nums2[j++];
    for(int m=0;m<k;m++)
    {
        if(temp[m]<result[m])
            break;
        if(temp[m]>result[m])
        {
            result=temp;
            break;
        }
    }
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int n1=int(nums1.size());
    int n2=int(nums2.size());
    int t=min(n1,k);
    vector<int> result(k,0);
    for(int i=max(0,k-n2);i<=t;i++)
    {
        auto s1=myStack(nums1, i);
        auto s2=myStack(nums2, k-i);
        merge(s1,s2,result,k);
    }
    return result;
}


int main(int argc, const char * argv[]) {
    vector<int> nums1={1,6,5,4,7,3,9,5,3,7,8,4,1,1,4};
    vector<int> nums2={4,3,1,3,5,9};
    auto result=maxNumber(nums1, nums2, 21);
    for(auto i:result)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
