//
//  main.cpp
//  leetcode111
//
//  Created by ly on 2020/8/21.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void getMinDepth(TreeNode* root,int depth,int &result)
{
    if(depth>result)
        return;
    if(root->left==nullptr&&root->right==nullptr)
        result=depth;
    else
    {
        if(root->left!=nullptr)
            getMinDepth(root->left, depth+1, result);
        if(root->right!=nullptr)
            getMinDepth(root->right, depth+1, result);
    }
}

int minDepth(TreeNode* root) {
    if(root==nullptr)
        return 0;
    int result=INT_MAX;
    getMinDepth(root, 1, result);
    return result;
    
}

int main(int argc, const char * argv[]) {
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    cout<<minDepth(root)<<endl;
    return 0;
}
