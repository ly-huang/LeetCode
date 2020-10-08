//
//  main.cpp
//  leetcode344
//
//  Created by ly on 2020/10/8.
//

#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char>& s) {
    int i=0;
    int j=int(s.size());
    while(i<j)
    {
        s[i]=s[i]^s[j];
        s[j]=s[i]^s[j];
        s[i]=s[i]^s[j];
        i++;j--;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
