//
//  main.cpp
//  leetcode480
//
//  Created by ly on 2021/2/3.
//

#include <iostream>
#include <vector>
using  namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<int> data(k);
        for(int i=0;i<k;++i)
        {
            data[i]=nums[i];
        }
        myQsort(data, 0, k-1);
        int index=k-1;
        int n=int(nums.size());
        vector<double> result;
        int mid1,mid2;
        mid1=mid2=k/2;
        if(k%2==0)
            mid2=mid1-1;
        vector<int> temp(k);
        while(true)
        {
            result.emplace_back((data[mid1]*1.0+data[mid2]*1.0)/2.0);
            ++index;
            if(index>=n)
                break;
            bool mark1=true;
            bool mark2=true;
            for(int i=0,j=0;i<k;)
            {
                if(j<k)
                {
                    if(mark1&&data[j]==nums[index-k])
                    {
                        mark1=false;
                        ++j;
                        
                    }
                    else if(mark2&&data[j]>nums[index])
                    {
                        mark2=false;
                        temp[i++]=nums[index];

                    }
                    else
                    {
                        temp[i++]=data[j++];
                    }
                }
                else
                {
                    temp[i++]=nums[index];
                }
            }
            data=temp;
        }
        return result;
    }
private:
    void myQsort(vector<int>&data,int left,  int right)
    {
        if(left>=right)
            return;
        int i=left;
        int j=right;
        int temp;
        while(i<j)
        {
            while(j>i&&data[j]>data[left])--j;
            while(i<j&&data[i]<=data[left])++i;
            temp=data[i];
            data[i]=data[j];
            data[j]=temp;
        }
        temp=data[i];
        data[i]=data[left];
        data[left]=temp;
        myQsort(data, left, i-1);
        myQsort(data, i+1, right);
    }
};

int main(int argc, const char * argv[]) {
    vector<int>nums({1,3,-1,-3,5,3,6,7});
    Solution s;
    auto result=s.medianSlidingWindow(nums, 3);
    std::cout << "Hello, World!\n";
    return 0;
}
