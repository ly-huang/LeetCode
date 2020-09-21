//
//  main.cpp
//  leetcode538
//
//  Created by ly on 2020/9/21.
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

void getResult(TreeNode *node,int &sum)
{
    if(node->right!=nullptr)
        getResult(node->right,sum);
    sum+=node->val;
    node->val=sum;
    if(node->left!=nullptr)
        return getResult(node->left,sum);
}

TreeNode* convertBST(TreeNode* root) {
    if(root==nullptr)
        return nullptr;
    int sum=0;
    getResult(root,sum);
    return root;
}

int main(int argc, const char * argv[]) {
    TreeNode *root=new TreeNode(2);
    root->left=new TreeNode(0);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(-4);
    root->left->right=new TreeNode(1);
    auto result=convertBST(root);
    return 0;
}
