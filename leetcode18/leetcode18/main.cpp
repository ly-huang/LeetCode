//
//  main.cpp
//  leetcode18
//
//  Created by ly on 2020/10/5.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        n=int(nums.size());
        myQsort(nums, 0, n-1);
        getResult(nums, target, 0);
        return result;
    }
private:
    int n;
    vector<vector<int>> result;
    void getResult(const vector<int>&nums,const int &target,int index)
    {
        int left,t1,t2;
        int sum;
        for(int i=0;i<n;i++)
        {
            if(i!=0&&nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<n;j++)
            {
                if(j!=i+1&&nums[j]==nums[j-1])
                    continue;
                left=target-nums[i]-nums[j];
                t1=j+1;
                t2=n-1;
                if(t1<n&&nums[t1]>0&&nums[t1]>left)
                    break;
                while(t1<t2)
                {
                    sum=nums[t1]+nums[t2];
                    if(sum==left)
                    {
                        result.push_back({nums[i],nums[j],nums[t1++],nums[t2--]});
                        while(t1<t2&&nums[t1]==nums[t1-1])
                            t1++;
                        while(t2>t1&&nums[t2]==nums[t2+1])
                            t2--;
                    }
                    else if(sum<left)
                    {
                        t1++;
                        while(t1<t2&&nums[t1]==nums[t1-1])
                            t1++;
                    }
                    else
                    {
                        t2--;
                        while(t2>t1&&nums[t2]==nums[t2+1])
                            t2--;
                    }
                }
            }
        }
    }

    void myQsort(vector<int>& nums,int left,int right)
    {
        if(left>=right)
            return;;
        int i=left;
        int j=right;
        int num=nums[left];
        int temp;
        while(i<j)
        {
            while(j>i&&nums[j]>num)
                j--;
            while(i<j&&nums[i]<=num)
                i++;
            temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
        }
        temp=nums[i];
        nums[i]=num;
        nums[left]=temp;
        myQsort(nums, left, i-1);
        myQsort(nums, i+1, right);
    }
    
};

int main(int argc, const char * argv[]) {
    vector<int> nums={-2,-1,-1,1,1,2,2};
    Solution s;
    auto result=s.fourSum(nums, 0);
    for(const auto &item:result)
    {
        for(const auto &i:item)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
