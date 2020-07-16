#include <iostream>
#include<vector>
#include <map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    map<int,int> data;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        if(data.find(target-nums[i])!=data.end())
        {
            result.push_back(data[target-nums[i]]);
            result.push_back(i);
            break;
        } else
            data[nums[i]]=i;
    }
    return result;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<endl;
    return 0;
}
