//
//  main.cpp
//  leetcode337
//
//  Created by ly on 2020/8/5.
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


int fun(TreeNode* node,bool haveRobbed)
{
    if(node==nullptr)
        return 0;
    if(haveRobbed)
        return fun(node->left,false)+fun(node->right,false);
    else
    {
        int temp1=node->val;
        int temp2=0;
        temp1+=fun(node->left,true)+fun(node->right,true);
        temp2+=fun(node->left,false)+fun(node->right,false);
        return temp1>temp2?temp1:temp2;
    }
}
int rob(TreeNode* root) {
    if(root==nullptr)
        return 0;
    return fun(root,false);
}

int main(int argc, const char * argv[]) {
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->right=new TreeNode(3);
    root->right->right=new TreeNode(1);
    cout<<rob(root)<<endl;
    return 0;
}
