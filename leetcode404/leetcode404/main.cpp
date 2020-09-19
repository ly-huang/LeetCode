//
//  main.cpp
//  leetcode404
//
//  Created by ly on 2020/9/19.
//

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumOfLeftLeaves(TreeNode* root) {
    if(root==nullptr)
        return 0;
    queue<TreeNode*> q;
    TreeNode *node=nullptr;
    int result=0;
    q.push(root);
    while(!q.empty())
    {
        node=q.front();
        q.pop();
        if(node->left!=nullptr)
        {
            if(node->left->left==nullptr&&node->left->right==nullptr)
            {
                result+=node->left->val;
                if(node->left->right!=nullptr)
                    q.push(node->left->right);
            }
            else
            {
                q.push(node->left);
            }
        }
        if(node->right!=nullptr)
        {
            q.push(node->right);
        }
    }
    return result;
    
}

int main(int argc, const char * argv[]) {
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    cout<<sumOfLeftLeaves(root)<<endl;
    return 0;
}
