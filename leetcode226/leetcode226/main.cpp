//
//  main.cpp
//  leetcode226
//
//  Created by ly on 2020/9/16.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) {
    if(root==nullptr)
        return nullptr;
    TreeNode *left=invertTree(root->left);
    TreeNode *right=invertTree(root->right);
    root->left=right;
    root->right=left;
    return root;
}

int main(int argc, const char * argv[]) {
    TreeNode *root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(7);
    invertTree(root);
    return 0;
}
