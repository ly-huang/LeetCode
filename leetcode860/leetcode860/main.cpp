//
//  main.cpp
//  leetcode860
//
//  Created by ly on 2020/12/10.
//

#include <iostream>
#include <vector>
using namespace std;


bool lemonadeChange(vector<int>& bills) {
    int count_5=0;
    int count_10=0;
    for(auto i:bills)
    {
        if(i==5)
            count_5++;
        else if(i==10)
        {
            if(count_5==0)
                return false;
            count_5--;
            count_10++;
        }
        else
        {
            if(count_10!=0)
            {
                i-=10;
                count_10--;
            }
            i=(i-5)/5;
            if(count_5<i)
                return false;
            count_5-=i;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
