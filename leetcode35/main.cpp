#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    if(nums.empty())
        return 0;
    int i=0;
    int j=nums.size()-1;
    int mid=(i+j)>>1;
    while(i<=j)
    {
        mid=(i+j)>>1;
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]<target)
        {
            i=mid+1;
        } else{
            j=mid-1;
        }
    }
    return i;
}
int main() {
    vector<int> nums={1,3,5,6};
    cout<<searchInsert(nums,7)<<endl;
    return 0;
}
