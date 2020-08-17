//
//  main.cpp
//  leetcode110
//
//  Created by ly on 2020/8/17.
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

int check(TreeNode *root,bool& result)
{
    int left=1;
    int right=1;
    if(root->left!=nullptr)
        left+=check(root->left,result);
    if(!result)
        return -1;
    if(root->right!=nullptr)
        right+=check(root->right,result);
    if(left-right>1||right-left>1)
        result=false;
    return left>right?left:right;
}

bool isBalanced(TreeNode* root) {
    if(root==nullptr)
        return true;
    bool result=true;
    check(root, result);
    return result;
    
}

int main(int argc, const char * argv[]) {
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    cout<<isBalanced(root)<<endl;
    return 0;
}
