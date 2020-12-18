//
//  main.cpp
//  leetcode389
//
//  Created by ly on 2020/12/18.
//

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//char findTheDifference(string s, string t) {
//    unordered_map<char, int> m;
//    for(const auto &c:s)
//        m[c]++;
//    for(const auto &c:t)
//    {
//        if(m[c]==0)
//            return c;
//        m[c]--;
//    }
//    return ' ';
//}

char findTheDifference(string s, string t) {
    int ret=0;
    for(const auto &c:s)
        ret^=c;
    for(const auto &c:t)
        ret^=c;
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
