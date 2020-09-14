//
//  main.cpp
//  leetcode94
//
//  Created by ly on 2020/9/14.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<int> inorderTraversal(TreeNode* root) {
    if(root==nullptr)
        return {};
    vector<int> result;
    
    stack<TreeNode*> s;
    TreeNode *ptr=root;
    while(!s.empty()||ptr!=nullptr)
    {
        while(ptr!=nullptr)
        {
            s.push(ptr);
            ptr=ptr->left;
        }
        ptr=s.top();
        s.pop();
        result.push_back(ptr->val);
        ptr=ptr->right;
    }
        
    return result;
}

int main(int argc, const char * argv[]) {
    TreeNode *root=new TreeNode(2);
    root->left=new TreeNode(3);
    root->left->left=new TreeNode(1);
    auto result=inorderTraversal(root);
    for(const auto &i :result)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
