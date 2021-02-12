//
//  main.cpp
//  leetcode703
//
//  Created by 黄创 on 2021/2/11.
//

#include <iostream>
#include <vector>
using namespace std;


class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        data.resize(k);
        for(int i=0;i<k;++i)
        {
            data[i]=INT_MIN;
        }
        this->k=k;
        int n=int(nums.size());
        k=min(k,n);
        for(int i=0;i<k;++i)
        {
            data[i]=nums[i];
        }
    }
    
    int add(int val) {
        if(val<=data[k-1])
            return data[k-1];
        int index=0;
        while(data[index]>val)
            ++index;
        for(int i=k-2;i>=index;--i)
        {
            data[i+1]=data[i];
        }
        data[index]=val;
        return data[k-1];
    }
private:
    vector<int> data;
    int k;
           
           
};

int main(int argc, const char * argv[]) {
    vector<int> nums={4, 5, 8, 2};
    KthLargest k(3,nums);
    cout<<k.add(3)<<endl;
    return 0;
}
