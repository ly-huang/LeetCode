//
//  main.cpp
//  leetcode637
//
//  Created by ly on 2020/9/12.
//  Copyright © 2020 ly. All rights reserved.
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

vector<double> averageOfLevels(TreeNode* root) {
    if(root==nullptr)
        return {};
    vector<double> result;
    queue<TreeNode*> nodes;
    double sum=0;
    size_t count=0;
    nodes.push(root);
    TreeNode* ptr=nullptr;
    while(!nodes.empty())
    {
        sum=0;
        count=nodes.size();
        for(size_t i=0;i<count;i++)
        {
            ptr=nodes.front();
            nodes.pop();
            sum+=ptr->val;
            if(ptr->left!=nullptr)
                nodes.push(ptr->left);
            if(ptr->right!=nullptr)
                nodes.push(ptr->right);
        }
        result.push_back(sum/count);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    auto result=averageOfLevels(root);
    for(const auto &i:result)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
