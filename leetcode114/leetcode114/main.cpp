//
//  main.cpp
//  leetcode114
//
//  Created by ly on 2020/8/2.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//递归
//void flatten(TreeNode* root) {
//    if(root==nullptr)
//        return;
//    if(root->left!=nullptr)
//        flatten(root->left);
//    if(root->right!=nullptr)
//        flatten(root->right);
//    if(root->left!=nullptr)
//    {
//        TreeNode *ptrRight=root->right;
//        root->right=root->left;
//        root->left=nullptr;
//        if(ptrRight!=nullptr)
//        {
//            TreeNode *ptr=root->right;
//            while(ptr->right!=nullptr)
//                ptr=ptr->right;
//            ptr->right=ptrRight;
//
//        }
//    }
//}

//栈
void flatten(TreeNode* root)
{
    if(root==nullptr)
        return;
    stack<TreeNode*>s;
    s.push(root);
    TreeNode* ptr;
    TreeNode* prev=nullptr;
    while(!s.empty())
    {
        ptr=s.top();
        s.pop();
        if(prev!=nullptr)
        {
            prev->left=nullptr;
            prev->right=ptr;
        }
        if(ptr->right!=nullptr)
            s.push(ptr->right);
        if(ptr->left!=nullptr)
            s.push(ptr->left);
        prev=ptr;
    }
}

int main(int argc, const char * argv[]) {
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(5);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->right->right=new TreeNode(6);
    flatten(root);
    TreeNode* ptr=root;
    while(ptr!=nullptr)
    {
        cout<<ptr->val<<" ";
        ptr=ptr->right;
    }
    cout<<endl;
    return 0;
}
