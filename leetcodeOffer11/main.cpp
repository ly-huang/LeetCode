#include <iostream>
#include <vector>
using namespace std;

//暴力搜索
//int minArray(vector<int>& numbers) {
//    if(numbers.empty())
//        return 0;
//    int result=numbers[0];
//    for(int i=1;i<numbers.size();i++)
//    {
//        if(numbers[i]<result)
//        {
//            result=numbers[i];
//            break;
//        }
//    }
//    return result;
//}

//二分查找
int minArray(vector<int>& numbers){
    if(numbers.empty())
        return 0;
    int low=0;
    int high=numbers.size()-1;
    int mid;
    while(low<high)
    {
        mid=low+((high-low)>>1);
        if(numbers[mid]<numbers[high])
            high=mid;
        else if(numbers[mid]==numbers[high])
            high--;
        else
            low=mid+1;
    }
    return numbers[low];
}
int main() {
    vector<int> numbers={3,4,5,1,2};
    cout<<minArray(numbers)<<endl;
    return 0;
}
