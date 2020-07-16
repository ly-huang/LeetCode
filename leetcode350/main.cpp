#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    if(nums1.empty()||nums2.empty())
        return result;
     vector<int>::iterator ptr1,ptr2;
     int n1,n2;
     if(nums1.size()>nums2.size())
     {
         ptr1=nums1.begin();
         ptr2=nums2.begin();
         n1=nums1.size();
         n2=nums2.size();
     } else{
         ptr1=nums2.begin();
         ptr2=nums1.begin();
         n1=nums2.size();
         n2=nums1.size();
     }
     vector<bool> mark(n2,true);
     for(int i=0;i<n1;i++)
     {
         for(int j=0;j<n2;j++)
         {
             if(ptr1[i]==ptr2[j]&&mark[j])
             {
                 result.push_back(ptr1[i]);
                 mark[j]= false;
                 break;
             }
         }
     }
     return result;
}
int main() {
    vector<int> nums1={4,9,5};
    vector<int> nums2={9,4,9,8,4};
    auto result=intersect(nums1,nums2);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<" ";
    cout<<endl;
    return 0;
}
