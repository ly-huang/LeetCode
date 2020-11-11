//
//  main.cpp
//  leetcode514
//
//  Created by ly on 2020/11/11.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int findRotateSteps(string ring, string key) {
    int n = ring.size(), m = key.size();
    vector<int> pos[26];
    for (int i = 0; i < n; ++i) {
        pos[ring[i] - 'a'].push_back(i);
    }
    int dp[m][n];
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    for (auto& i: pos[key[0] - 'a']) {
        dp[0][i] = min(i, n - i) + 1;
    }
    for (int i = 1; i < m; ++i) {
        for (auto& j: pos[key[i] - 'a']) {
            for (auto& k: pos[key[i - 1] - 'a']) {
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(abs(j - k), n - abs(j - k)) + 1);
            }
        }
    }
    return *min_element(dp[m - 1], dp[m - 1] + n);
}


int main(int argc, const char * argv[]) {
    cout<<findRotateSteps("tawzu","zzzwwwuuutttaaa")<<endl;
    return 0;
}
