//
//  main.cpp
//  leetcode925
//
//  Created by ly on 2020/10/21.
//

#include <iostream>
#include <string>
using namespace std;

bool isLongPressedName(string name, string typed) {
    int l1=int(name.size());
    int l2=int(typed.size());
    if(l2<l1)
        return false;
    int i=0,j=0;
    while(i<l1&&j<l2)
    {
        if(name[i]==typed[j])
        {
            i++;
            j++;
            continue;
        }
        else if(j==0)
            return false;
        else if(typed[j-1]!=typed[j])
            return false;
        else
            j++;
    }
    while(j<l2&&typed[j]==typed[j-1])
        j++;
    if(i==l1&&j==l2)
        return true;
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
