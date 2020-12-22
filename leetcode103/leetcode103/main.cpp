//
//  main.cpp
//  leetcode103
//
//  Created by ly on 2020/12/22.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(root==nullptr)
        return {};
    vector<vector<int>> result;
    vector<int> temp;
    queue<TreeNode*> q;
    int n=0;
    bool forward=true;
    TreeNode*ptr;
    q.emplace(root);
    while(!q.empty())
    {
        n=int(q.size());
        temp={};
        while(n>0)
        {
            ptr=q.front();
            q.pop();
            temp.emplace_back(ptr->val);
            if(ptr->left!=nullptr)
                q.emplace(ptr->left);
            if(ptr->right!=nullptr)
                q.emplace(ptr->right);
            n--;
        }
        if(!forward)
            reverse(temp.begin(), temp.end());
        result.emplace_back(temp);
        forward=!forward;
    }
    return result;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
