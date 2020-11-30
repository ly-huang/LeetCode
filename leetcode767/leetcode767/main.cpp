//
//  main.cpp
//  leetcode767
//
//  Created by ly on 2020/11/30.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string reorganizeString(string S) {
    if (S.length() < 2) {
        return S;
    }
    vector<int> counts(26, 0);
    int maxCount = 0;
    int length = int(S.length());
    for (auto c:S) {
        counts[c - 'a']++;
        maxCount = max(maxCount, counts[c - 'a']);
    }
    if (maxCount > (length + 1) / 2) {
        return "";
    }
    string reorganizeArray(length, ' ');
    int evenIndex = 0, oddIndex = 1;
    int halfLength = length / 2;
    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        while (counts[i] > 0 && counts[i] <= halfLength && oddIndex < length) {
            reorganizeArray[oddIndex] = c;
            counts[i]--;
            oddIndex += 2;
        }
        while (counts[i] > 0) {
            reorganizeArray[evenIndex] = c;
            counts[i]--;
            evenIndex += 2;
        }
    }
    return reorganizeArray;
}

int main(int argc, const char * argv[]) {
    cout<<reorganizeString("aab")<<endl;
    return 0;
}
