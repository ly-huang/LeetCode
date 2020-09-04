//
//  main.cpp
//  leetcode257
//
//  Created by ly on 2020/9/4.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void fun(vector<string>& result,TreeNode* node,string path)
{
    path+=to_string(node->val);
    if(node->left==nullptr&&node->right==nullptr)
    {
        result.push_back(path);
        return;
    }
    if(node->left!=nullptr)
        fun(result,node->left,path+"->");
    if(node->right!=nullptr)
        fun(result,node->right,path+"->");
}

vector<string> binaryTreePaths(TreeNode* root) {
    if(root==nullptr)
        return {};
    vector<string> result;
    fun(result,root,"");
    return result;
}

int main(int argc, const char * argv[]) {
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->right=new TreeNode(5);
    auto result=binaryTreePaths(root);
    for(auto item:result)
        cout<<item<<endl;
    return 0;
}
