#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> result;
    if(numbers.empty())
        return result;
    int n=numbers.size();
    int i=0,j=n-1;
    while(i<j)
    {
        int sum=numbers[i]+numbers[j];
        if(sum==target)
        {
            result.push_back(i+1);
            result.push_back(j+1);
            break;
        }
        else if(sum<target)
            i++;
        else
            j--;
    }
    return result;
}
int main() {
    vector<int> numbers={2, 7, 11, 15};
    auto result=twoSum(numbers,9);
    cout<<result[0]<<" "<<result[1]<<endl;
    return 0;
}
