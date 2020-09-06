//
//  main.cpp
//  leetcode107
//
//  Created by ly on 2020/9/6.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if(root==nullptr)
        return {};
    vector<vector<int>> result;
    stack<vector<int>> s_result;
    vector<int> data;
    queue<int> level;
    queue<TreeNode*> node;
    node.push(root);
    level.push(1);
    TreeNode* ptr=nullptr;
    int l=1;
    int last_l=1;
    while(!node.empty())
    {
        ptr=node.front();
        node.pop();
        l=level.front();
        level.pop();
        if(l!=last_l)
        {
            s_result.push(data);
            data={};
        }
        data.push_back(ptr->val);
        if(ptr->left!=nullptr)
        {
            node.push(ptr->left);
            level.push(l+1);
        }
        if(ptr->right!=nullptr)
        {
            node.push(ptr->right);
            level.push(l+1);
        }
        last_l=l;
    }
    result.push_back(data);
    while(!s_result.empty())
    {
        result.push_back(s_result.top());
        s_result.pop();
    }
    return result;
}

int main(int argc, const char * argv[]) {
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    auto result=levelOrderBottom(root);
    for(auto item:result)
    {
        for(auto i:item)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
